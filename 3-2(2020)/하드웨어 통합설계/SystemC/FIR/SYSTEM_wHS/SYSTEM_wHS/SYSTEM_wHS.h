#pragma once

#include <systemc.h>
#include "fir_whs.h"
#include "tb_whs.h"

SC_MODULE(SYSTEM) {
	tb* tb0;
	fir* fir0;
	//module instaciation

	sc_signal<bool> rst_sig;
	sc_signal<sc_int<16>> inp_sig;
	sc_signal<sc_int<16>> outp_sig;
	//wire
	sc_clock clk_sig; //clock signal
	
	sc_signal<bool> inp_sig_vld;
	sc_signal<bool> inp_sig_rdy;
	sc_signal<bool> outp_sig_vld;
	sc_signal<bool> outp_sig_rdy;
	//handshaking


	SC_CTOR(SYSTEM) :clk_sig("clk_sig", 10, SC_NS) { // clock period 10ns
		tb0 = new tb("tb0");
		tb0->clk(clk_sig);
		tb0->rst(rst_sig);
		tb0->inp(inp_sig);
		tb0->outp(outp_sig);
		//add handshaking
		tb0->inp_vld(inp_sig_vld);
		tb0->inp_rdy(inp_sig_rdy);
		tb0->outp_vld(outp_sig_vld);
		tb0->outp_rdy(outp_sig_rdy);
		//testbench connect

		fir0 = new fir("fir0");
		fir0->clk(clk_sig);
		fir0->rst(rst_sig);
		fir0->inp(inp_sig);
		fir0->outp(outp_sig);
		//add handshaking
		fir0->inp_vld(inp_sig_vld);
		fir0->inp_rdy(inp_sig_rdy);
		fir0->outp_vld(outp_sig_vld);
		fir0->outp_rdy(outp_sig_rdy);
		//fir connect
	}
	//instanciation & port connection

	~SYSTEM() {
		delete tb0;
		delete fir0;
	}
	//desructor
};
