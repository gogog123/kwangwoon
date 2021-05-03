module tl_cntr_w_left(clk, reset_n, Ta, Tal, Tb, Tbl, La, Lb);
//
input clk, reset_n, Ta, Tal, Tb, Tbl;
output [1:0] La, Lb;
wire [2:0] q, d;

ns_logic U0_ns_logic(.q(q[2:0]), .Ta(Ta), .Tal(Tal), .Tb(Tb), .Tbl(Tbl), .d(d[2:0]));
_register3_r U0_register3_r(.clk(clk), .reset_n(reset_n), .d(d[2:0]), .q(q[2:0]));
o_logic U0_o_logic(.q(q[2:0]), .La(La[1:0]), .Lb(Lb[1:0]));
//instance of ns_logic, register3, o_logic
endmodule 