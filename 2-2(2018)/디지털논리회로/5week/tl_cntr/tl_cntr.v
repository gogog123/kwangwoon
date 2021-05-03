module tl_cntr(clk, reset_n, Ta, Tb, La, Lb);
//Traffic light controller module 
input clk, reset_n, Ta, Tb;
output [1:0] La, Lb;
wire [1:0] q, d;

ns_logic U0_ns_logic(.q(q[1:0]), .Ta(Ta), .Tb(Tb), .d(d[1:0]));
_register2_r U0_register2_r(.clk(clk), .reset_n(reset_n),.d(d[1:0]), .q(q[1:0]));
o_logic U0_o_logic(.q(q[1:0]), .La(La[1:0]), .Lb(Lb[1:0]));
//instance of ns_logic, register, o_logic
endmodule 