module _register2_r(clk, reset_n, d, q);
//state save
input clk, reset_n;
input [1:0] d;
output [1:0] q;

_dff_r U0_dff_r(.clk(clk),.reset_n(reset_n), .d(d[0]),.q(q[0]));
_dff_r U1_dff_r(.clk(clk),.reset_n(reset_n), .d(d[1]),.q(q[1]));
//instance of dff_r
endmodule 
