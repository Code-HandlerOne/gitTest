#include"global.h"
const int QUANTUM = 3;
std::deque<pcb*>new_queue;
std::deque<pcb*>ready_queue;
std::deque<pcb*>running_queue;
std::deque<pcb*>block_queue;
std::deque<pcb*>finished_queue;
pcb* current_process=nullptr;
int time_count=1;
bool interrupt_flag=false;
bool start_schedule=false;
std::map<pcb*, std::chrono::system_clock::time_point>block_start_time;
std::mutex console_mutex;