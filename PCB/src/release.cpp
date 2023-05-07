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
			std::cout << "����" << process->name << "�Ѿ��ͷţ�" << std::endl;
			delete process;

			lock.unlock();
		}
	}
}