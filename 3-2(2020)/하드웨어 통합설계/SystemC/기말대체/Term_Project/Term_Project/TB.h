#pragma once
#include <systemc.h>

SC_MODULE(TB) {
	sc_in<bool> clk;

	sc_out<sc_int<32>> A;
	sc_out<sc_int<32>> B;
	sc_out<sc_int<1>> Cin;
	//TB output
	sc_in<sc_int<32>> result;
	sc_in<sc_int<1>> Cout;
	//TB input

	//hand shaking
	sc_out<sc_int<1>> A_valid;
	sc_out<sc_int<1>> B_valid;
	sc_out<sc_int<1>> Cin_valid;
	sc_out<sc_int<1>> Cout_ready;
	sc_out<sc_int<1>> result_ready;
	//TB output
	sc_in<sc_int<1>> A_ready;
	sc_in<sc_int<1>> B_ready;
	sc_in<sc_int<1>> Cin_ready;
	sc_in<sc_int<1>> Cout_valid;
	sc_in<sc_int<1>> result_valid;
	//TB input

	const char* input_file = "Simulation.txt";
	std::ifstream fin;

	void source();
	void sink();

	SC_CTOR(TB) {
		SC_CTHREAD(source, clk.pos()); //send input_signal
		SC_CTHREAD(sink, clk.pos()); //receive output_signal
	}
};

void TB::source() {

	A.write(0);
	A_valid.write(0);
	B.write(0);
	B_valid.write(0);
	Cin.write(0);
	Cin_valid.write(0);
	wait();

	fin.open(input_file);
	//file open

	sc_int<32> temp; //result
	sc_int<32> A_read;
	sc_int<32> B_read;
	char cmd[64];
	A_valid.write(1);
	B_valid.write(1);
	Cin_valid.write(1);
	int a = 0;

	while (!fin.eof()) {
		a++;
		for (int i = 0; i < 3; i++) {
			if (a == 2)
				break;
			fin.getline(cmd, 64);
			if (i == 0) {
				cout << "A: " << cmd << endl;
				int check = 31;
				for (int j = 0; j < 39; j++) {
					if (cmd[j] == 48) {
						A_read[check] = 0;
						check--;
					}
					else if (cmd[j] == 49) {
						A_read[check] = 1;
						check--;
					}
				}
				A.write(A_read);
			}
			if (i == 1) {
				cout << "B: " << cmd << endl;
				int check = 31;
				for (int j = 0; j < 39; j++) {
					if (cmd[j] == 48) {
						B_read[check] = 0;
						check--;
					}
					else if (cmd[j] == 49) {
						B_read[check] = 1;
						check--;
					}
				}
				B.write(B_read);
			}
			if (i == 2) {
				cout << "Cin: " << cmd << endl;
				if (cmd[0] == 48) //0
					Cin.write(0);
				else if (cmd[0] == 49) //1
					Cin.write(1);
			}
		}

		do {
			wait();
		} while (!A_ready.read() && !B_ready.read() && !Cin_ready.read());

		A_valid.write(0);
		B_valid.write(0);
		Cin_valid.write(0);
	}
}

void TB::sink() {
	sc_int<32> inresult;
	sc_int<1> incout;

	char output_file[256];
	sprintf(output_file, "./output.data");
	FILE* outfp = fopen(output_file, "wb");
	if (outfp == NULL) {
		printf("Couldn¡¯t open output.dat for writing.\n");
		exit(0);
	}//not file

	
	Cout_ready.write(0);
	result_ready.write(0);

	for (int i = 0; i < 32; i++) {
		Cout_ready.write(1);
		result_ready.write(1);

		do {
			wait();
		} while (!Cout_valid.read() && !result_valid.read());

		inresult = result.read();
		incout = Cout.read();
		//read

		result_ready.write(0);
		Cout_ready.write(0);

		inresult = result.read();
		incout = Cout.read();

		char cmd[64];
		sc_int<32> result_read;

		for (int i = 0; i < 2; i++) {
			
			fin.getline(cmd, 64);
			if (i == 0) {
				cout << "File_Result: " << cmd << endl;
				int check = 31;
				for (int j = 0; j < 39; j++) {
					if (cmd[j] == 48) {
						result_read[check] = 0;
						check--;
					}
					else if (cmd[j] == 49) {
						result_read[check] = 1;
						check--;
					}
				}
			}
			if (i == 1) {
				int c = 0;
				cout << "File_Cout: " << cmd << endl;
				if (cmd[0] == 48) //0
					c = 0;
				else if (cmd[0] == 49) //1
					c = 1;
			}
		}
		fin.getline(cmd, 64);
	}

	sc_stop();
	//end testbench
}