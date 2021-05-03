module _dff(clk, d, q, q_bar); //D Flip-Flop module
input clk, d;
output q, q_bar;
wire clk_bar, w_q;

_inv U0_inv(.a(clk), .y(clk_bar));
_dlatch U0_dlatch(.clk(clk_bar), .d(d), .q(w_q));
_dlatch U1_dlatch(.clk(clk), .d(w_q), .q(q), .q_bar(q_bar));
//instance of inveter, dlatch
endmodule 