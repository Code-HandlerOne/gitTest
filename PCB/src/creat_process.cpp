#include"create_process.h"
#include"global.h"
#include<iostream>

void create_process()
{
	std::string name;			//������
	process_state state=NEW;	//����״̬
	int serve_time;				//��Ҫ�������ʱ��
	int run_time=0;				//�Ѿ����е�ʱ��
	int rest_time;				//ʣ��ʱ��
	int IO_time;				//IO��Ҫ��ʱ��
	int IO_start_time;			//IO��ʼʱ��
	int IO_end_time;			//IO����ʱ��
	char flag;
	for (int i = 0;;) {
		std::cout << "\n�Ƿ�Ҫ������" << i + 1 << "������?\n�������ǣ�Y/y���N/n" << std::endl;
		std::cin >> flag;
		std::cout << "\n";
		
		if (flag == 'Y' || flag == 'y') {
			std::cout << "���ڴ�����" << i + 1 << "�����̣�" << std::endl;

			std::cout << "�������������";
			std::cin >> name;

			std::cout << "��������Ҫ��ʱ�䣺";
			std::cin >> serve_time;
			rest_time = serve_time;

			std::cout << "������IO��ʼʱ�䣺";
			std::cin >> IO_start_time;

			std::cout << "������IO����ʱ�䣺";
			std::cin >> IO_end_time;

			IO_time = IO_end_time - IO_start_time;
			pcb* process = new pcb(name, state, serve_time, run_time, rest_time, IO_time, IO_start_time, IO_end_time);
			new_queue.push_back(process);

			++i;
		}
		else if (flag == 'N' || flag == 'n')break;
		else std::cout << "������Ч�����������룡" << std::endl;
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
