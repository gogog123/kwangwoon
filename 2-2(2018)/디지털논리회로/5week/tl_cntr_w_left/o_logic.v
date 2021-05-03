module o_logic(q, La, Lb);
//
input [2:0] q;
output [1:0] La, Lb;
wire La_w, Lb_w;

_and2 U0_and2(.a(q[1]),.b(~q[0]),.y(La_w));
_or2 U1_or2(.a(La_w),.b(q[2]),.y(La[1]));
//output La1

_or2 U2_or2(.a(q[0]),.b(q[2]),.y(La[0]));
//output La0

_and2 U3_and2(.a(q[1]),.b(~q[0]),.y(Lb_w));
_or2 U4_or2(.a(~q[2]),.b(Lb_w),.y(Lb[1]));
//output Lb1

_or2 U5_or2(.a(~q[2]),.b(q[0]),.y(Lb[0]));
//output Lb0

endmodule 