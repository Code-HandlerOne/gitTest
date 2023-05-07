#include<iostream>
#include "pcb.h"


pcb::pcb()=default;

pcb::pcb(std::string &name, process_state &state, int &serve_time, int &run_time, int &rest_time, int &IO_time, int &IO_start_time, int &IO_end_time):
	name(name), state(state), serve_time(serve_time),  run_time(run_time), rest_time(rest_time), IO_time(IO_time), IO_start_time(IO_start_time), IO_end_time(IO_end_time){};
	
	

