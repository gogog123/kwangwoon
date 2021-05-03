module ns_logic(q, Ta, Tb, d); //tld next state decision
input [1:0] q;
input Ta, Tb;
output [1:0] d;
wire n_q0, n_q1,n_Ta, n_Tb, w0, w1;

_xor2 U0_xor2(.a(q[1]),.b(q[0]),.y(d[1]));
//output d1
_inv U0_inv(.a(q[0]),.y(n_q0));
_inv U1_inv(.a(q[1]),.y(n_q1));
_inv U2_inv(.a(Tb),.y(n_Tb));
_inv U3_inv(.a(Ta),.y(n_Ta));
_and3 U0_and3(.a(n_q1),.b(n_q0),.c(n_Ta),.y(w0));
_and3 U1_and3(.a(q[1]),.b(n_q0),.c(n_Tb),.y(w1));
_or2 U0_or2(.a(w0),.b(w1),.y(d[0]));
//output d0
endmodule 