#include"print_interface.h"
#include<iostream>

void print_interface()
{
	std::cout << "\t\tWelcome to my OS!" << std::endl;
	std::cout << "\t1.输入create命令可以创建进程；" << std::endl;
	std::cout << "\t2.输入Esc命令可以阻塞当前进程；" << std::endl;
	std::cout << "\t3.输入Enter命令可以选择新进程调度，当前进程进入就绪态；" << std::endl;
	std::cout << "\t4.输入wakeup命令可以唤醒阻塞进程;" << std::endl;
	std::cout << "\t5.输入finished命令可以结束当前进程;" << std::endl;
}