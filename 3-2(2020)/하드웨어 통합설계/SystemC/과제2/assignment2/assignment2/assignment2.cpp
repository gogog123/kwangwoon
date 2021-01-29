#include <systemc.h>

int sc_main(int sc_argc, char* sc_argv[]) {
	sc_lv<4> data1_lv = "1xz0";
	sc_lv<8> data2_lv;		       	 //data_bv = xxxxxxxx
	sc_logic parity;
	cout << "data2_lv: " << data2_lv << endl;

	data2_lv.range(3, 0) = data1_lv; //data_bv = xxxx1xz0
	cout << "data2_lv: " << data2_lv << endl;

	data2_lv.range(0, 3) = data1_lv; //data_bv = xxxx0zx1
	cout << "data2_lv: " << data2_lv << endl;

	data2_lv[4] = 1;                 //data_bv = xxx10zx1
	cout << "data2_lv: " << data2_lv << endl;

	parity = data2_lv.xor_reduce();  //parity = 1
	cout << "parity: " << parity << endl;
	return 0;
}