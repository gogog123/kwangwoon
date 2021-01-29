#pragma once
SC_MODULE(fir) {
	sc_in<bool> clk;
	sc_in<bool> rst;
	sc_in <sc_int<16>> inp;
	sc_out<sc_int<16>> outp;
	//port 

	void fir_main();

	SC_CTOR(fir) { //fir execution
		SC_CTHREAD(fir_main, clk.pos()); //positive edge execution
		reset_signal_is(rst, true); //rst == 1, resets
	}
};

const sc_uint<8> coef[5] = { 18,77,107,77,18 }; //not change constant

void fir::fir_main(void) {
	sc_int<16> taps[5] = { 0,0,0,0,0 }; //declare
	outp.write(0); 
	wait(); //wait clock edge

	while (true) {
		for (int i = 4; i > 0; i--) {
			taps[i] = taps[i - 1];
		}
		taps[0] = inp.read();
		sc_int<16> val;
		for (int i = 0; i < 5; i++) {
			val += coef[i] * taps[i]; // val is sum of coef * tap
		}
		outp.write(val); //result write
		wait();
	}
}


