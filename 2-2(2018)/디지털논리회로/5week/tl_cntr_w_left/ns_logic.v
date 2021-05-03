module ns_logic(q, Ta, Tal, Tb, Tbl, d);
//traffic light controller left top module 
input [2:0] q;
input Ta, Tal, Tb, Tbl;
output [2:0] d;
wire d2_w0, d2_w1, d2_w2; //d2_wire
wire d1_w0, d1_w1, d1_w2; //d1_wire
wire d0_w0, d0_w1, d0_w2, d0_w3;//d0_wire

_and3 U0_and3(.a(~q[2]), .b(q[1]), .c(q[0]),.y(d2_w0));
_and2 U1_and2(.a(q[2]), .b(~q[1]),.y(d2_w1));
_and3 U3_and3(.a(q[2]), .b(q[1]), .c(~q[0]),.y(d2_w2));
_or3 U4_or3(.a(d2_w0),.b(d2_w1),.c(d2_w2),.y(d[2]));
//output d2

_and3 U5_and3(.a(~q[2]), .b(~q[1]), .c(q[0]),.y(d1_w0));
_and2 U6_and2(.a(q[1]), .b(~q[0]), .y(d1_w1));
_and3 U7_and3(.a(q[2]), .b(~q[1]), .c(q[0]),.y(d1_w2));
_or3 U8_or3(.a(d1_w0),.b(d1_w1),.c(d1_w2),.y(d[1]));
//output d1

_and4 U9_and4(.a(~q[2]), .b(~q[1]), .c(~q[0]),.d(~Ta), .y(d0_w0));
_and4 U10_and4(.a(~q[2]), .b(q[1]), .c(~q[0]),.d(~Tal), .y(d0_w1));
_and4 U11_and4(.a(q[2]), .b(~q[1]), .c(~q[0]),.d(~Tb), .y(d0_w2));
_and4 U12_and4(.a(q[2]), .b(q[1]), .c(~q[0]),.d(~Tbl), .y(d0_w3));
_or4 U13_or4(.a(d0_w0),.b(d0_w1),.c(d0_w2),.d(d0_w3), .y(d[0]));
//output d0

endmodule 