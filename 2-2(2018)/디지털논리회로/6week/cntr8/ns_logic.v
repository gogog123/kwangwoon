module ns_logic(load, inc, state, next_state);
//next states logic part 
parameter IDLE_STATE = 3'b000;
parameter LOAD_STATE = 3'b001;
parameter INC_STATE = 3'b010;
parameter INC2_STATE = 3'b011;
parameter DEC_STATE = 3'b100;
parameter DEC2_STATE = 3'b101;
//binary encoding states

input load, inc;
input [2:0] state;
output [2:0] next_state;
reg [2:0] next_state;

always @ (load, inc, state)
//always load, inc, state change
begin
case(state)
IDLE_STATE :
begin 
if(load == 1'b1) next_state <= LOAD_STATE;
else if(inc == 1'b1) next_state <= INC_STATE;
else if(inc == 1'b0) next_state <= DEC_STATE;
else next_state <= IDLE_STATE;
end 
//IDLE_STATE 
LOAD_STATE :
begin
if(load == 1'b1) next_state <= LOAD_STATE;
else if(inc == 1'b1) next_state <= INC_STATE;
else if(inc == 1'b0) next_state <= DEC_STATE;
else next_state <= LOAD_STATE;
end 
//LOAD_STATE 
INC_STATE :
begin
if(load == 1'b1) next_state <= LOAD_STATE;
else if(inc == 1'b1) next_state <= INC2_STATE;
else if(inc == 1'b0) next_state <= DEC_STATE;
else next_state <= INC_STATE;
end
//INC_STATE
INC2_STATE : 
begin
if(load == 1'b1) next_state <= LOAD_STATE;
else if(inc == 1'b1) next_state <= INC_STATE;
else if(inc == 1'b0) next_state <= DEC_STATE;
else next_state <= INC2_STATE;
end
//INC2_STATE
DEC_STATE :
begin
if(load == 1'b1) next_state <= LOAD_STATE;
else if(inc == 1'b1) next_state <= INC_STATE;
else if(inc == 1'b0) next_state <= DEC2_STATE;
else next_state <= DEC_STATE;
end
//DEC_STATE
DEC2_STATE :
begin
if(load == 1'b1) next_state <= LOAD_STATE;
else if(inc == 1'b1) next_state <= INC_STATE;
else if(inc == 1'b0) next_state <= DEC_STATE;
else next_state <= DEC2_STATE;
end
//DEC2_STATE
default : next_state <= 3'bx; 
//next state logic part
endcase 
end 
endmodule 