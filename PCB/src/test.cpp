#include"test.h"
#include"print_interface.h"
#include"create_process.h"
#include"schedule.h"
#include"global.h"
#include"block.h"
#include"release.h"
#include<iostream>
#include<map>
#include<thread>


void test()
{
	enum choice {
		create=0,
		Esc=1,
		Enter=2,
		wakeup=3,
		finished=4
	};
	std::map<std::string, choice>instruct = {
		{"create",create},
		{"Esc",Esc},
		{"Enter",Enter},
		{"wakeup",wakeup},
		{"finished",finished},
	};
	//创建调度线程
	std::thread schedule_thread(schedule);
	//创建阻塞线程
	std::thread block_thread(block);
	//创建释放线程
	std::thread release_thread(release);
	while (true) {

		print_interface();
		std::cout << "请输入你的命令：" << std::endl;
		std::string str;
		std::cin >> str;

		auto it = instruct.find(str);
		int command = 0; 
		if (it == instruct.end())command = -1;
		else command= it->second;

		switch (command) {
		case create:
			system("cls");
			std::cout << "\t\t这里是创建进程界面！" << std::endl;
			create_process();

			getchar();
			std::cin.get();
			system("cls");
			start_schedule = true;			//创建完进程后调度线程开始
			break;

		case Esc:
			system("cls");
			std::cout << "\t\t这里是阻塞进程界面！" << std::endl;
			getchar();
			std::cin.get();
			system("cls");
			break;

		case Enter:
			system("cls");
			std::cout << "\t\t这里是选择新进程调度界面！" << std::endl;
			getchar();
			std::cin.get();
			system("cls");
			break;

		case wakeup:
			system("cls");
			std::cout << "\t\t这里是唤醒进程界面！" << std::endl;
			getchar();
			std::cin.get();
			system("cls");
			break;

		case finished:
			system("cls");
			std::cout << "\t\t这里是完成进程界面！" << std::endl;
			getchar();
			std::cin.get();
			system("cls");
			break;

		default:
			system("cls");
			std::cout << "命令无效！" << std::endl;
			getchar();
			std::cin.get();
			system("cls");
			break;
		}
	}
	

}