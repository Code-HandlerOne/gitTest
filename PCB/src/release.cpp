#include"release.h"
#include"global.h"
#include<iostream>

void release()
{
	while (true) {
		while (!finished_queue.empty()) {
			std::unique_lock<std::mutex> lock(console_mutex);

			pcb* process = finished_queue.front();
			finished_queue.pop_front();
			std::cout << "进程" << process->name << "已经释放！" << std::endl;
			delete process;

			lock.unlock();
		}
	}
}