module alu32(a, b, op, result, c, n, z, v); 
//32bits Arithmetic logic unit
input [31:0] a,b;
input [2:0] op;
output [31:0] result;
output c,n,z,v;

wire [31:0] w_not_a, w_not_b, w_and, w_or, w_xor, w_xnor, w_add, w_sub;
wire co_prev_add, co_add, co_prev_sub, co_sub;

_inv_32bits    U0_inv_32bits(.a(a[31:0]),.y(w_not_a[31:0])); //a inverter
_inv_32bits    U1_inv_32bits(.a(b[31:0]),.y(w_not_b[31:0])); //b inverter
_and2_32bits   U0_and2_32bits(.a(a[31:0]),.b(b[31:0]),.y(w_and[31:0]));
_or2_32bits    U0_or2_32bits(.a(a[31:0]),.b(b[31:0]),.y(w_or[31:0]));
_xor2_32bits   U0_xor2_32bits(.a(a[31:0]),.b(b[31:0]),.y(w_xor[31:0]));
_xnor2_32bits  U0_xnor2_32bits(.a(a[31:0]),.b(b[31:0]),.y(w_xnor[31:0]));

cla32_ov       U0_cla32_ov(.a(a[31:0]),.b(b[31:0]),.ci(1'b0),.s(w_add[31:0]),.co_prev(co_prev_add),.co(co_add));
cla32_ov       U1_cla32_ov(.a(a[31:0]),.b(b[31:0]),.ci(1'b1),.s(w_sub[31:0]),.co_prev(co_prev_sub),.co(co_sub));
mx8_32bits     U0_mx8_4bits(.a(w_not_a),.b(w_not_b),.c(w_and),.d(w_or),.e(w_xor),.f(w_xnor),.g(w_add),
              .h(w_sub),.s2(op[2]),.s1(op[1]),.s0(op[0]),.y(result[31:0]));

cal_flags32    U0_cal_flags32(.op(op),.result(result),.co_add(co_add),.co_prev_add(co_prev_add),
              .co_sub(co_sub),.co_prev_sub(co_prev_sub),.c(c),.n(n),.z(z),.v(v));
//instance		 
endmodule 