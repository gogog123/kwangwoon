#pragma once
#include <systemc.h>
#include "Adder.h"
#include "TB.h"

SC_MODULE(SYSTEM) {
	
	TB* TB0;
	Adder* Adder0;
	//module instaciation

	sc_clock clk_sig;
	
	sc_signal<sc_int<32>> A_sig;
	sc_signal<sc_int<32>> B_sig;
	sc_signal<sc_int<1>> Cin_sig;
	//Adder input, TB output
	sc_signal<sc_int<32>> result_sig;
	sc_signal<sc_int<1>> Cout_sig;
	//Adder output, TB input
	
	//hand shaking
	sc_signal<sc_int<1>> A_valid_sig;
	sc_signal<sc_int<1>> B_valid_sig;
	sc_signal<sc_int<1>> Cin_valid_sig;
	sc_signal<sc_int<1>> Cout_ready_sig;
	sc_signal<sc_int<1>> result_ready_sig;
	//Adder input, TB output
	sc_signal<sc_int<1>> A_ready_sig;
	sc_signal<sc_int<1>> B_ready_sig;
	sc_signal<sc_int<1>> Cin_ready_sig;
	sc_signal<sc_int<1>> Cout_valid_sig;
	sc_signal<sc_int<1>> result_valid_sig;
	//Adder output, TB input

	SC_CTOR(SYSTEM) : clk_sig("clk_sig", 1, SC_NS) { // cycle period = 1ns
		TB0 = new TB("TB0"); //allocation
		TB0->clk(clk_sig);
		TB0->A(A_sig);
		TB0->B(B_sig);
		TB0->Cin(Cin_sig);
		TB0->result(result_sig);
		TB0->Cout(Cout_sig);
		TB0->A_valid(A_valid_sig);
		TB0->B_valid(B_valid_sig);
		TB0->Cin_valid(Cin_valid_sig);
		TB0->Cout_ready(Cout_ready_sig);
		TB0->result_ready(result_ready_sig);
		TB0->A_ready(A_ready_sig);
		TB0->B_ready(B_ready_sig);
		TB0->Cin_ready(Cin_ready_sig);
		TB0->Cout_valid(Cout_valid_sig);
		TB0->result_valid(result_valid_sig);
		//connect TB

		Adder0 = new Adder("Adder0"); //allocation
		Adder0->clk(clk_sig);
		Adder0->A(A_sig);
		Adder0->B(B_sig);
		Adder0->Cin(Cin_sig);
		Adder0->result(result_sig);
		Adder0->Cout(Cout_sig);
		Adder0->A_valid(A_valid_sig);
		Adder0->B_valid(B_valid_sig);
		Adder0->Cin_valid(Cin_valid_sig);
		Adder0->Cout_ready(Cout_ready_sig);
		Adder0->result_ready(result_ready_sig);
		Adder0->A_ready(A_ready_sig);
		Adder0->B_ready(B_ready_sig);
		Adder0->Cin_ready(Cin_ready_sig);
		Adder0->Cout_valid(Cout_valid_sig);
		Adder0->result_valid(result_valid_sig);
		//connect Adder
	}

	~SYSTEM() {
		delete TB0;
		delete Adder0;
	}
	//destructor
};