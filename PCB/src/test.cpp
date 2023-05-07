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
	//���������߳�
	std::thread schedule_thread(schedule);
	//���������߳�
	std::thread block_thread(block);
	//�����ͷ��߳�
	std::thread release_thread(release);
	while (true) {

		print_interface();
		std::cout << "������������" << std::endl;
		std::string str;
		std::cin >> str;

		auto it = instruct.find(str);
		int command = 0; 
		if (it == instruct.end())command = -1;
		else command= it->second;

		switch (command) {
		case create:
			system("cls");
			std::cout << "\t\t�����Ǵ������̽��棡" << std::endl;
			create_process();

			getchar();
			std::cin.get();
			system("cls");
			start_schedule = true;			//��������̺�����߳̿�ʼ
			break;

		case Esc:
			system("cls");
			std::cout << "\t\t�������������̽��棡" << std::endl;
			getchar();
			std::cin.get();
			system("cls");
			break;

		case Enter:
			system("cls");
			std::cout << "\t\t������ѡ���½��̵��Ƚ��棡" << std::endl;
			getchar();
			std::cin.get();
			system("cls");
			break;

		case wakeup:
			system("cls");
			std::cout << "\t\t�����ǻ��ѽ��̽��棡" << std::endl;
			getchar();
			std::cin.get();
			system("cls");
			break;

		case finished:
			system("cls");
			std::cout << "\t\t��������ɽ��̽��棡" << std::endl;
			getchar();
			std::cin.get();
			system("cls");
			break;

		default:
			system("cls");
			std::cout << "������Ч��" << std::endl;
			getchar();
			std::cin.get();
			system("cls");
			break;
		}
	}
	

}