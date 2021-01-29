#pragma once
#include <systemc.h>

SC_MODULE(tb) {
	sc_in<bool> clk;
	sc_out<bool> rst;
	sc_in<sc_int<16>> outp;
	sc_out<sc_int<16>> inp;
	//add handshaking
	sc_in<bool> outp_vld;
	sc_out<bool> outp_rdy;
	sc_out<bool> inp_vld;
	sc_in<bool> inp_rdy;
	//in/out port fir converse

	void source();
	void sink();

	SC_CTOR(tb) { //tb constructor
		SC_CTHREAD(source, clk.pos());
		SC_CTHREAD(sink, clk.pos());
		//positive edge execution
	}
};

void tb::source() {
	inp.write(0);
	inp_vld.write(0);
	rst.write(1); //assert reset
	wait();
	rst.write(0); //deassert reset
	wait();

	sc_int<16> tmp; //fir input

	for (int i = 0; i < 64; i++) {
		if (i > 23 && i < 29) //24~28
			tmp = 256; //input
		else
			tmp = 0;
		inp_vld.write(1); // write
		inp.write(tmp);

		do {
			wait();
		} while (!inp_rdy.read());
		inp_vld.write(0);
	}
}

void tb::sink() {
	sc_int<16> indata;

	char output_file[256];
	sprintf(output_file, "./output.data");
	FILE* outfp = fopen(output_file, "wb");
	if (outfp == NULL) {
		printf("Couldn¡¯t open output.dat for writing.\n");
		exit(0);
	}

	//initialize port
	outp_rdy.write(0);

	for (int i = 0; i < 64; i++) {
		outp_rdy.write(1);

		do {
			wait();
		} while (!outp_vld.read());
		indata = outp.read();
		outp_rdy.write(0);

		indata = outp.read(); //read

		cout << i << " :\t" << indata.to_int() << endl; //print output, check
		fprintf(outfp, "%g\n", indata.to_double());
	}

	sc_stop();
	//end testbench
}