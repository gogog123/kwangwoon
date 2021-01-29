
#include <systemc.h>

SC_MODULE(Three_Process) {
	sc_in <bool> clk;


	SC_CTOR(Three_Process) {
		SC_THREAD(first_thread);
		sensitive << clk.pos();
		SC_THREAD(second_thread);
		sensitive << clk.pos();
		SC_THREAD(third_thread);
		sensitive << clk.pos();
	}

	void first_thread(void);
	void second_thread(void);
	void third_thread(void);
};
