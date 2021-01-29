#include "Memory.h"
#include <math.h>

SC_HAS_PROCESS(Memory);
Memory::Memory(sc_module_name instName, int addrW, int dataW) : sc_module
(instName) {
	addWidth = addrW;
	dataWidth = dataW;
	size = ((sc_biguint<1024>)pow<int, int>(2, addrW)) * (dataW / 8);

}