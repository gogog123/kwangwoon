#pragma once
#include <systemc.h>

SC_MODULE(Adder) {
	sc_in<bool> clk;

	sc_in<sc_int<32>> A;
	sc_in<sc_int<32>> B;
	sc_in<sc_int<1>> Cin;
	//Adder input
	sc_out<sc_int<32>> result;
	sc_out<sc_int<1>> Cout;
	//Adder output

	//hand shaking
	sc_in<sc_int<1>> A_valid;
	sc_in<sc_int<1>> B_valid;
	sc_in<sc_int<1>> Cin_valid;
	sc_in<sc_int<1>> Cout_ready;
	sc_in<sc_int<1>> result_ready;
	//Adder input
	sc_out<sc_int<1>> A_ready;
	sc_out<sc_int<1>> B_ready;
	sc_out<sc_int<1>> Cin_ready;
	sc_out<sc_int<1>> Cout_valid;
	sc_out<sc_int<1>> result_valid;
	//Adder output

	void Adder_main();

	SC_CTOR(Adder) { //Adder execution
		SC_CTHREAD(Adder_main, clk.pos()); //positive edge execution
	}
};

#define DELAY 1

void Adder::Adder_main(void) {

	//initialize handshake
	A_ready.write(0);
	B_ready.write(0);
	Cin_ready.write(0);
	Cout_valid.write(0);
	result_valid.write(0);

	result.write(0);
	Cout.write(0);
	wait(); //wait clock edge 

	while (true) {
		sc_int<32> in_A;
		sc_int<32> in_B;
		sc_int<1> in_Cin;
		sc_int<1> out_Cout;
		sc_int<33> out_result;

		A_ready.write(1);
		B_ready.write(1);
		Cin_ready.write(1);
		//ready success 

		do {
			wait();
		} while (!A_valid.read() && !B_valid.read() && Cin_valid.read());
		//All A_valid, B_valid, Cin_valid, 1

		in_A = A.read();
		in_B = B.read();
		in_Cin = Cin.read();
		//cout << in_Cin.to_uint() << endl;

		//read, Save
		A_ready.write(0);
		B_ready.write(0);
		Cin_ready.write(0);

		int result_int = 0;
		result_int = in_A.to_uint() + in_B.to_uint() + 1;
		//cout << in_A.to_uint() << " " << in_B.to_uint() << " "<< in_Cin.to_uint() << endl;
		//cout << result_int << endl;

;		cout << "Result: " << result_int << endl;
		if (result_int < in_B.to_uint())
			Cout.write(1);
		else
			Cout.write(0);
		cout << "Cout: " << Cout << endl;


		for (int i = 0; i < DELAY; i++) wait();  //waint 10time
		
		Cout_valid.write(1);
		result_valid.write(1);
		result.write(out_result);
		Cout.write(out_Cout);

		do {
			wait();
		} while (!Cout_ready.read() && !result_ready.read());

		Cout_valid.write(0);
		result_valid.write(0);

	}

}
