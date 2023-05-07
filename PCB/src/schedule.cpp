#include"schedule.h"
#include"global.h"
#include<chrono>
#include<thread>
#include<iostream>
#include<chrono>
#include<thread>
void schedule()
{
	while (true) {
		
		if (start_schedule) {
			std::this_thread::sleep_for(std::chrono::seconds(3));
			while (!ready_queue.empty() || !running_queue.empty()) {
				pcb* process = ready_queue.front();
				ready_queue.pop_front();
				running_queue.push_back(process);
				current_process = running_queue.front();
				auto start_time = std::chrono::system_clock::now();
				//输出当前进程信息
				std::cout << "This is Process " << current_process->name << ", I am running in time-slice " << time_count << std::endl;
				//当前进程在该时间片完成
				if (current_process->rest_time <= QUANTUM) {
					++time_count;
					//运行到结束时间然后紧接着调度下一个进程
					auto end_time= start_time+std::chrono::seconds(current_process->rest_time);
					std::this_thread::sleep_until(end_time);
					//状态从运行态变为完成态
					std::unique_lock<std::mutex> lock(console_mutex);

					std::cout << "进程" << current_process->name << "已完成!" << std::endl;
					finished_queue.push_back(current_process);
					running_queue.pop_front();

					//更新信息
					current_process->rest_time = 0;
					current_process->run_time = current_process->serve_time;
					current_process->state = FINISHED;

					lock.unlock();
				}
				//当前进程在该时间片阻塞
				else if (current_process->run_time + QUANTUM >= current_process->IO_start_time&&current_process->run_time<current_process->IO_end_time) {
					++time_count;
					//运行到阻塞的时间然后紧接着调度下一个进程
					auto end_time=start_time+ std::chrono::seconds(current_process->IO_start_time-current_process->run_time);
					std::this_thread::sleep_until(end_time);

					//状态从运行态转为阻塞态
					std::unique_lock<std::mutex> lock(console_mutex);

					auto block_stime= std::chrono::system_clock::now();
					block_start_time.insert(std::make_pair(current_process, block_stime));

					std::cout << "进程" << current_process->name << "被阻塞!" << std::endl;
					block_queue.push_back(current_process);
					running_queue.pop_front();

					//更新信息
					current_process->run_time = current_process->IO_start_time;
					current_process->rest_time = current_process->serve_time - current_process->run_time;
					current_process->state = BLOCKED;

					lock.unlock();
				}
				//正常轮转
				else {
					++time_count;
					auto end_time = start_time + std::chrono::seconds(QUANTUM);
					std::this_thread::sleep_until(end_time);

					//状态变为就绪态
					std::unique_lock<std::mutex> lock(console_mutex);

					ready_queue.push_back(current_process);
					running_queue.pop_front();

					//更新信息
					current_process->run_time += QUANTUM;
					current_process->rest_time = current_process->serve_time - current_process->run_time;
					current_process->state = READY;

					lock.unlock();
				}
			}

		}

		
	}
	
}