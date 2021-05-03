module _dff_rs(clk, set_n, reset_n, d, q);
//synchronous set/resettable D flip-flop
input clk, set_n, reset_n, d;
output q;
wire w_d, w_set_n, w_or;

_inv U0_inv(.a(set_n),.y(w_set_n));
_or2 U0_or2(.a(d),.b(w_set_n),.y(w_or));
_and2 U0_and2(.a(w_or),.b(reset_n),.y(w_d)); 
_dff U0_dff(.clk(clk),.d(w_d),.q(q));
//instance of gates, dff
endmodule 