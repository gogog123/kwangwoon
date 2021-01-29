#pragma once

SC_MODULE(fir) {
	sc_in<bool> clk;
	sc_in<bool> rst;
	sc_in <sc_int<16>> inp;
	sc_out<sc_int<16>> outp;

	//add handshaking
	sc_in<bool> inp_vld;
	sc_out<bool> inp_rdy;
	sc_out<bool> outp_vld;
	sc_in<bool> outp_rdy;

	//port 

	void fir_main();

	SC_CTOR(fir) { //fir execution
		SC_CTHREAD(fir_main, clk.pos()); //positive edge execution
		reset_signal_is(rst, true); //rst == 1, resets
	}
};

#define DELAY 1

const sc_uint<8> coef[5] = { 18,77,107,77,18 }; //not change constant

void fir::fir_main(void) {

	sc_int<16> taps[5] = { 0,0,0,0,0 };

	for (int i = 0; i < 5; i++) {
		taps[i] = 0;
	}

	//initialize handshake
	inp_rdy.write(0);
	outp_vld.write(0);

	outp.write(0);
	wait(); //wait clock edge

	//FIR filter
	while (true) {
		sc_int<16> in_val;
		sc_int<16> out_val;

		inp_rdy.write(1); //write ready == 1 // ready success

		do {
			wait();
		} while (!inp_vld.read()); //when vld == 0
		in_val = inp.read();
		inp_rdy.write(0);
		//tell "tb" that fir is not ready to take another input yet.
	
		for (int i = 4; i > 0; i--) {
			taps[i] = taps[i - 1];
		}
		taps[0] = inp.read();
		sc_int<16> val;
		for (int i = 0; i < 5; i++) {
			val += coef[i] * taps[i];
		}
		for (int i = 0; i < DELAY; i++) wait();  //waint 10time
		outp_vld.write(1); //change 1
		outp.write(val); 
		do {
			wait();
		} while (!outp_rdy.read()); ////when rdy == 0

		outp_vld.write(0);
	}

}
