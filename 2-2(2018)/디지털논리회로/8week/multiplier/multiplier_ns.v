module multiplier_ns(op_start, op_clear, state, data_count, next_state);
//next_state module 
input op_start, op_clear;
input [5:0] data_count;
input [1:0] state;
output reg [1:0] next_state;
//input output 

parameter IDLE_STATE = 2'b00;
parameter EXEC_STATE = 2'b01;
parameter DONE_STATE = 2'b10;
//Encoding states
always @ (op_start, op_clear, state, data_count)
//when input change
begin
case(state)
IDLE_STATE:
if(op_clear == 1)       next_state = IDLE_STATE;
else if(op_start == 1)  next_state = EXEC_STATE;
else                    next_state = state;
//IDLE_STATE -> next?

EXEC_STATE:
if(op_clear == 1)                           next_state = IDLE_STATE;
else if(op_start == 1 && data_count < 32)   next_state = EXEC_STATE;
else if(op_start == 1 && data_count == 32)  next_state = DONE_STATE;
else                                        next_state = state;
//EXEC_STATE -> next?

DONE_STATE: 
if(op_clear == 1)                           next_state = IDLE_STATE;
else if(op_start == 1)                      next_state = IDLE_STATE;
else                                        next_state = state;
//DONE_STATE -> next?

default:                                    next_state = 2'bxx;
endcase
end

endmodule 