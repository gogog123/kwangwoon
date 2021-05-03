module o_logic(q, La, Lb); //state output decision
input [1:0] q;
output [1:0] La, Lb;
wire n_q1;

_inv U0_inv(.a(q[1]),.y(n_q1));

assign La[1] = q[1];
_and2 U0_and2(.a(n_q1),.b(q[0]),.y(La[0])); //assign La[0]
assign Lb[1] = n_q1;
_and2 U1_and2(.a(q[1]),.b(q[0]),.y(Lb[0])); //assign Lb[0]
 
endmodule 