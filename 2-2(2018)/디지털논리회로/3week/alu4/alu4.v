module alu4(a, b, op, result, c, n, z, v); //4bits Arithmetic logic unit
input [3:0] a,b;
input [2:0] op;
output [3:0] result;
output c,n,z,v;

wire [3:0] w_not_a, w_not_b, w_and, w_or, w_xor, w_xnor, w_add, w_sub;
wire c3_add, co_add, c3_sub, co_sub;

_inv_4bits    U0_inv_4bits(.a(a[3:0]),.y(w_not_a[3:0])); //a inverter
_inv_4bits    U1_inv_4bits(.a(b[3:0]),.y(w_not_b[3:0])); //b inverter
_and2_4bits   U0_and2_4bits(.a(a[3:0]),.b(b[3:0]),.y(w_and[3:0]));
_or2_4bits    U0_or2_4bits(.a(a[3:0]),.b(b[3:0]),.y(w_or[3:0]));
_xor2_4bits   U0_xor2_4bits(.a(a[3:0]),.b(b[3:0]),.y(w_xor[3:0]));
_xnor2_4bits  U0_xnor2_4bits(.a(a[3:0]),.b(b[3:0]),.y(w_xnor[3:0]));

cla4_ov       U0_cla4_ov(.a(a[3:0]),.b(b[3:0]),.ci(1'b0),.s(w_add[3:0]),.c3(c3_add),.co(co_add));
cla4_ov       U1_cla4_ov(.a(a[3:0]),.b(b[3:0]),.ci(1'b1),.s(w_sub[3:0]),.c3(c3_sub),.co(co_sub));
mx8_4bits     U0_mx8_4bits(.a(w_not_a),.b(w_not_b),.c(w_and),.d(w_or),.e(w_xor),.f(w_xnor),.g(w_add),
              .h(w_sub),.s2(op[2]),.s1(op[1]),.s0(op[0]),.y(result));

cal_flags4    U0_cal_flags4(.op(op),.result(result),.co_add(co_add),.c3_add(c3_add),
              .co_sub(co_sub),.c3_sub(c3_sub),.c(c),.n(n),.z(z),.v(v));
//instance				  
endmodule 