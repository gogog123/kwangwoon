#include "Three_Process.h"

int sc_main(int sc_argc, char* sc_argv[]) {

	sc_clock clk("clock", 10, SC_NS);
	Three_Process U_Three_Process("U_Three_Process");

	cout << "Simulation starts!!" << endl;
	U_Three_Process.clk(clk);
	sc_start(100, SC_NS);

	return 0;
}