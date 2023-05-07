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
	std::string name;		//进程名
	process_state state;	//进程状态
	int serve_time;			//需要处理机的时间
	int run_time;			//已经运行的时间
	int rest_time;			//剩余时间
	int IO_time;			//IO需要的时间
	int IO_start_time;		//IO开始时间
	int IO_end_time;		//IO结束时间

public:
	pcb();
	pcb(std::string& name, process_state& state, int& serve_time, int& run_time, int& rest_time, int& IO_time, int& IO_start_time, int& IO_end_time);
};

