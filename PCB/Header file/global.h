/*
	全局变量声明
*/
#pragma once
#include<deque>
#include<map>
#include<chrono>
#include<mutex>
#include"pcb.h"
extern const int QUANTUM;					 //时间片
extern std::deque<pcb*>new_queue;			 //新建队列
extern std::deque<pcb*>ready_queue;			 //就绪队列
extern std::deque<pcb*>running_queue;		 //运行队列
extern std::deque<pcb*>block_queue;			 //阻塞队列
extern std::deque<pcb*>finished_queue;		 //完成队列
extern pcb* current_process;				 //当前进程
extern int time_count;						 //当前时间片
extern bool interrupt_flag;					 //中断标志
extern bool start_schedule;					 //调度线程开始标志
extern std::map<pcb*, std::chrono::system_clock::time_point>block_start_time;//进程阻塞开始时间
extern std::mutex console_mutex;