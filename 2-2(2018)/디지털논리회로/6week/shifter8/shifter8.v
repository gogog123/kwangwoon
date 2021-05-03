module shifter8(clk, reset_n, op, shamt, d_in, d_out);
//coding the module header
input clk, reset_n;
input [2:0] op;
input [1:0] shamt;
input [7:0] d_in;
output [7:0] d_out;

wire [7:0] do_next;

cc_logic U0_cc_logic(.op(op),.shamt(shamt),.d_in(d_in),.d_out(d_out),.do_next(do_next));
_register8_r U0_register8_r(.clk(clk),.reset_n(reset_n),.d(do_next),.q(d_out));
//instance combinational circuit, 8-bits register
endmodule 