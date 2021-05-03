module cntr8(clk, reset_n, inc, load, d_in, d_out, o_state);
//coding the module header
input clk, reset_n, inc, load;
input [7:0] d_in;
output [7:0] d_out;
output [2:0] o_state;

wire [2:0] next_state;
wire [2:0] state;

assign o_state = state;

ns_logic U0_ns_logic(.load(load),.inc(inc),.state(state),.next_state(next_state));
_register3_r U0_register3_r(.clk(clk),.reset_n(reset_n),.d(next_state),.q(state));
os_logic U0_os_logic(.state(state),.d_in(d_in),.d_out(d_out));
//instance of register, next state logic, output logic
endmodule 