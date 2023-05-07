#include"block.h"
#include"global.h"
#include<chrono>
#include<iostream>
bool operator>=(const std::chrono::system_clock::duration& time_point, int& value)
{
	int second = std::chrono::duration_cast<std::chrono::seconds>(time_point).count();
	return second >= value;
}
void block()
{
	while (true) {
		while (!block_queue.empty()) {
			for (auto it = block_start_time.begin(); it != block_start_time.end(); ) {
				auto now_time = std::chrono::system_clock::now();
				auto time = now_time - it->second;
				pcb* process = it->first;
				if (time >= process->IO_time) {
					//����̬�����̬
					std::unique_lock<std::mutex> lock(console_mutex);
					std::cout << "����" << process->name << "��IO�Ѿ���ɣ�" << std::endl;
					ready_queue.push_back(process);
					auto x = std::find(block_queue.begin(), block_queue.end(), process);
					block_queue.erase(x);
					//������Ϣ
					process->run_time = process->IO_end_time;
					process->rest_time = process->serve_time - process->run_time;
					process->state = READY;
					//��map��ɾ����ǰԪ��
					it = block_start_time.erase(it);

					lock.unlock();
				}
				else {
					++it;
				}
			}
		}
	}
}