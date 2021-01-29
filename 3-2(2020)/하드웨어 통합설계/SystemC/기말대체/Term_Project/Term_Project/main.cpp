#include <systemc.h>
#include "SYSTEM.h"

SYSTEM* top = NULL; //initialization

int sc_main(int argc, char* argv[]) {

	top = new SYSTEM("top"); //allocation, name 
	sc_start(); //testbench start

	return 0;
}