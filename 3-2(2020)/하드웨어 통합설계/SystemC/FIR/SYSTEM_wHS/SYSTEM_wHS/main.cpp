#include <systemc.h>
#include "SYSTEM_wHS.h"

SYSTEM* top = NULL; //initialization

int sc_main(int argc, char* argv[]) {
	top = new SYSTEM("top"); //allocation
	sc_start(); //testbench start
	return 0;
}