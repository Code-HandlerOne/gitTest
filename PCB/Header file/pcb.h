#pragma once
#include"state.h"
#include<string>
class pcb
{
	friend void create_process();
	friend void schedule();
	friend void block();
	friend void release();
private:
	std::string name;		//������
	process_state state;	//����״̬
	int serve_time;			//��Ҫ�������ʱ��
	int run_time;			//�Ѿ����е�ʱ��
	int rest_time;			//ʣ��ʱ��
	int IO_time;			//IO��Ҫ��ʱ��
	int IO_start_time;		//IO��ʼʱ��
	int IO_end_time;		//IO����ʱ��

public:
	pcb();
	pcb(std::string& name, process_state& state, int& serve_time, int& run_time, int& rest_time, int& IO_time, int& IO_start_time, int& IO_end_time);
};

