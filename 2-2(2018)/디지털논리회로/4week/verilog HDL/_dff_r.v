module _dff_r(clk, reset_n, d, q); //resettable D flip-flop
input clk, reset_n, d;
output q;
wire w_d;

_and2 U0_and(.a(reset_n),.b(d),.y(w_d));
_dff U0_dff(.clk(clk),.d(w_d),.q(q));
//instance of and2, dff
endmodule 