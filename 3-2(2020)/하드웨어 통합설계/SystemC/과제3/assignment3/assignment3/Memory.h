#include <systemc.h>

SC_MODULE(Memory) {
	sc_biguint<200> size;
	//siae: Memory size in bytes
	int dataWidth, addWidth;

	Memory(sc_module_name, int, int);

	void print() const {
		cout << endl << "Instance name: " << name() << endl
			<< "Memory size is " << size << "bytes."
			<< endl << "Its address and data widths are "
			<< addWidth << " and " << dataWidth << ", respectively." << endl;
	}
};