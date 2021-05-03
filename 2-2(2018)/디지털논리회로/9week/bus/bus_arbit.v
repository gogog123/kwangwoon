module bus_arbit(clk, reset_n, M0_req, M1_req, M0_grant, M1_grant);
//grant에 따라 master를 결정 
input clk, reset_n, M0_req, M1_req;
output reg M0_grant, M1_grant;
reg state;
reg next_state; 

parameter M0_STATE = 1'b0;
parameter M1_STATE = 1'b1;

always @ (posedge clk or negedge reset_n)
begin
if(reset_n==0) begin
state <= M0_STATE;
end
else state <= next_state;
end
//초기값 M0_STATE

always @ (M0_req, M1_req, M0_grant, M1_grant, state)
begin
case(state)
M0_STATE: begin 
M0_grant <= 1'b1;
M1_grant <= 1'b0;
if(M0_req==0 && M1_req==1) next_state <= M1_STATE;
else                       next_state <= M0_STATE;
end 
M1_STATE:begin 
M0_grant <= 1'b0;
M1_grant <= 1'b1;
if(M1_req==0) next_state <= M0_STATE;
else          next_state <= M1_STATE;
end 
default: begin
next_state <= 1'bx;
end 
endcase 
end 
//next_state 결정 
endmodule 
