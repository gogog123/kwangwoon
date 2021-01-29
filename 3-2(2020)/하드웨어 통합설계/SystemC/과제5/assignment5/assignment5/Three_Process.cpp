#include "Three_Process.h"

void Three_Process::first_thread(void) {
	while (1) {
		wait();
		std::cout << sc_time_stamp() << ": I'm the first thread!" << std::endl;
	}
}

void Three_Process::second_thread(void)
{
	while (1) {
		wait();
		std::cout << sc_time_stamp() << ": I'm the second thread!" << std::endl;
	}
}

void Three_Process::third_thread(void)
{
	while (1) {
		wait();
		std::cout << sc_time_stamp() << ": I'm the third thread!" << std::endl;
	}
}

void first_thread(void)
{
	while (1) {
		wait();
		std::cout << sc_time_stamp() << ": I'm the first thread!" << std::endl;
	}
}

void second_thread(void)
{
	while (1) {
		wait();
		std::cout << sc_time_stamp() << ": I'm the second thread!" << std::endl;
	}
}

void third_thread(void)
{
	while (1) {
		wait();
		std::cout << sc_time_stamp() << ": I'm the third thread!" << std::endl;
	}
}
