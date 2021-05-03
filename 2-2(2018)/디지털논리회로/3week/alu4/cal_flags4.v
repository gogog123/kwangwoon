module cal_flags4 (op, result, co_add, c3_add, co_sub, c3_sub, c, n, z, v);
input [2:0] op;
input [3:0] result;
input co_add, c3_add, co_sub, c3_sub;
output c,n,z,v;

assign c=(op[2:1]!=2'b11)?1'b0:((op[0]==1'b0)?co_add:co_sub);
//op=110 return co_add, op=111 return co_sub
assign n=result[3];
//return result
assign z=(result==4'b0000)?1'b1:1'b0;

assign v=(op[2:1]!=2'b11)?1'b0:((op[0]==1'b0)?co_add^c3_add:co_sub^c3_sub);
//op=110 return co_add^c3add, op=111 return co_sub^c3_sub
// assign conditional operator

endmodule 