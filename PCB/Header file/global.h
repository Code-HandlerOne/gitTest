/*
	ȫ�ֱ�������
*/
#pragma once
#include<deque>
#include<map>
#include<chrono>
#include<mutex>
#include"pcb.h"
extern const int QUANTUM;					 //ʱ��Ƭ
extern std::deque<pcb*>new_queue;			 //�½�����
extern std::deque<pcb*>ready_queue;			 //��������
extern std::deque<pcb*>running_queue;		 //���ж���
extern std::deque<pcb*>block_queue;			 //��������
extern std::deque<pcb*>finished_queue;		 //��ɶ���
extern pcb* current_process;				 //��ǰ����
extern int time_count;						 //��ǰʱ��Ƭ
extern bool interrupt_flag;					 //�жϱ�־
extern bool start_schedule;					 //�����߳̿�ʼ��־
extern std::map<pcb*, std::chrono::system_clock::time_point>block_start_time;//����������ʼʱ��
extern std::mutex console_mutex;