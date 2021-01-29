#include <systemc.h>
#include "Memory.h"

int sc_main(int argc, char* argv[]) {

	Memory m0("Mem0", 16, 32), m1("Mem1", 32, 32);
	m0.print();
	m1.print();

	return 0;
}