module multiplier(clk, reset_n, multiplicand, multiplier, op_start, op_clear, result, op_done);
//top module mulpiplier
input clk, reset_n, op_start, op_clear;
input [31:0] multiplicand, multiplier;
output op_done;
output [63:0] result;

wire [63:0] pre_result;
wire next_op_done;
wire [1:0] state, next_state;
wire [31:0] u, v, x1;
wire [31:0] next_u, next_v, next_x1;
wire x0, next_x0;
wire [5:0] data_count, next_data_count;
wire [31:0] add_u;
//start=op_start
//done=op_done
//product=result
//U :result from each step
//V : overflow bit from U when RSA
//X : show each RSC step

multiplier_ns U0_multiplier_ns(.op_start(op_start), .op_clear(op_clear), .state(state), .data_count(data_count), .next_state(next_state));

_register2_r U0_register2_r(.clk(clk), .reset_n(reset_n), .d(next_state), .q(state));
_register6_r U1_register6_r(.clk(clk), .reset_n(reset_n), .d(next_data_count), .q(data_count));
_register64_r U2_register64_r(.clk(clk),.reset_n(reset_n),.d(pre_result),.q(result));
_register32_r U3_register32_r(.clk(clk),. reset_n(reset_n), .d(next_u), .q(u));
_register32_r U4_register32_r(.clk(clk),. reset_n(reset_n), .d(next_v), .q(v));
_register32_r U5_register32_r(.clk(clk),. reset_n(reset_n), .d(next_x1), .q(x1));
_dff_r U6_dff_r(.clk(clk),. reset_n(reset_n), .d(next_x0), .q(x0));
//connect state, data_count, result, u, v, x1 
multiplier_out U0_multiplier_out(.state(state), .data_count(data_count), .next_data_count(next_data_count), .u(u), .v(v), .x0(x0), .x1(x1), .multiplicand(multiplicand), .multiplier(multiplier),
  .next_u(next_u), .next_v(next_v), .next_x0(next_x0), .next_x1(next_x1), .pre_result(pre_result), .result(result), .op_done(op_done));
//instance submodule(multiplier_ns, register, multiplier_out)  
  
endmodule 


