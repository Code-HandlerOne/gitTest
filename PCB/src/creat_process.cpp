#include"create_process.h"
#include"global.h"
#include<iostream>

void create_process()
{
	std::string name;			//进程名
	process_state state=NEW;	//进程状态
	int serve_time;				//需要处理机的时间
	int run_time=0;				//已经运行的时间
	int rest_time;				//剩余时间
	int IO_time;				//IO需要的时间
	int IO_start_time;			//IO开始时间
	int IO_end_time;			//IO结束时间
	char flag;
	for (int i = 0;;) {
		std::cout << "\n是否要创建第" << i + 1 << "个进程?\n请输入是：Y/y或否：N/n" << std::endl;
		std::cin >> flag;
		std::cout << "\n";
		
		if (flag == 'Y' || flag == 'y') {
			std::cout << "正在创建第" << i + 1 << "个进程：" << std::endl;

			std::cout << "请输入进程名：";
			std::cin >> name;

			std::cout << "请输入需要的时间：";
			std::cin >> serve_time;
			rest_time = serve_time;

			std::cout << "请输入IO开始时间：";
			std::cin >> IO_start_time;

			std::cout << "请输入IO结束时间：";
			std::cin >> IO_end_time;

			IO_time = IO_end_time - IO_start_time;
			pcb* process = new pcb(name, state, serve_time, run_time, rest_time, IO_time, IO_start_time, IO_end_time);
			new_queue.push_back(process);

			++i;
		}
		else if (flag == 'N' || flag == 'n')break;
		else std::cout << "输入无效！请重新输入！" << std::endl;
	}
	
	while (!new_queue.empty()) {
		pcb* temp = new_queue.front();
		temp->state = READY;
		ready_queue.push_back(temp);
		new_queue.pop_front();
	}
	
	
	/*for (auto it = ready_queue.begin(); it != ready_queue.end(); ++it) {
		std::cout << (*it)->name;
	}*/
}
