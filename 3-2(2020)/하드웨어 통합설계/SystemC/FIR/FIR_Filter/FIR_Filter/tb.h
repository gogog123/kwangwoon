#pragma once
SC_MODULE(tb) {
	sc_in<bool> clk;
	sc_out<bool> rst;
	sc_in<sc_int<16>> outp;
	sc_out<sc_int<16>> inp;
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
		inp.write(tmp);
		wait();
	}
}

void tb::sink() {
	sc_int<16> indata;

	for (int i = 0; i < 64; i++) {
		indata = outp.read(); //read
		wait();
		cout << i << " :\t" << indata.to_int() << endl; //print output
	}

	sc_stop();
	//end testbench
}