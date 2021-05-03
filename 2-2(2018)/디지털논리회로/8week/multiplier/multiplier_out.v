module multiplier_out(state,data_count,next_data_count,u,v,x0,x1,multiplicand,multiplier,next_u,next_v,next_x0,next_x1,pre_result,result,op_done);
//result output module
input [1:0] state;
input [5:0] data_count;
input [31:0] u, v; 
input x0;
input [31:0] x1;
input [31:0] multiplicand, multiplier;
output reg [31:0] next_u, next_v;
output reg next_x0;
output reg [31:0] next_x1;
output reg [63:0] pre_result;
input [63:0] result;
output reg op_done;
output reg [5:0]next_data_count;
wire [31:0] add_u;
wire [31:0] sub_u;

cla32 U0_cla32(.a(u),.b(multiplicand),.ci(0),.s(add_u));
cla32 U1_cla32(.a(u),.b(~multiplicand),.ci(1),.s(sub_u));
//instance of cla (add, sub)

parameter IDLE_STATE = 2'b00;
parameter EXEC_STATE = 2'b01;
parameter DONE_STATE = 2'b10;
//binary encoding state

always @ (u,v,x0,x1,multiplicand,multiplier,state,data_count, add_u, result)
//always input change
begin
case(state)
IDLE_STATE: begin
next_data_count <= 6'b0;
op_done <= 1'b0;
next_u <= 32'b0;
next_v <= 32'b0;
next_x0 <= 1'b0;
next_x1 <= multiplier;
pre_result <= 64'b0;
end
//IDLE_STATE output 초기화 

EXEC_STATE:
if(x1[0]==0 && x0==0) begin
next_data_count <= data_count + 6'b000001;
op_done <= 0;
next_u <= {u[31],u[31:1]};
next_v <= {u[0],v[31:1]};
next_x0 <= x1[0];
next_x1 <= {x1[0],x1[31:1]};
pre_result <= {u[31:0],v[31:0]};
end

else if(x1[0]==0 && x0==1)begin
next_data_count <= data_count + 6'b000001;
op_done <= 0;
next_u <= {add_u[31],add_u[31:1]};
next_v <= {add_u[0],v[31:1]};
next_x0 <= x1[0];
next_x1 <= {x1[0],x1[31:1]};
pre_result <= {u[31:0],v[31:0]};
end

else if(x1[0]==1 && x0==0) begin     
next_data_count <= data_count + 6'b000001;
op_done <= 0;
next_u <= {sub_u[31],sub_u[31:1]};
next_v <= {sub_u[0],v[31:1]};
next_x0 <= x1[0];
next_x1 <= {x1[0],x1[31:1]};
pre_result <= {u[31:0],v[31:0]};
end

else begin
next_data_count <= data_count + 6'b000001;
op_done <= 0;
next_u <= {u[31],u[31:1]};
next_v <= {u[0],v[31:1]};
next_x0 <= x1[0];
next_x1 <= {x1[0],x1[31:1]};
pre_result <= {u[31:0],v[31:0]};
end 
//EXEC_STATE end 
//x1[0],x0를 비교햐여 operation 수행

DONE_STATE:
if(data_count==6'b100000)begin
next_u <= u; 
next_v <= v; 
next_data_count <= 6'b0; 
next_x1 <= multiplier; 
next_x0 <= 1'b0; 
op_done <= 1'b1;
pre_result <= {u[31:0],v[31:0]};
end
else begin
next_u <= 32'b0; 
next_v <= 32'b0; 
next_data_count <= 6'b0; 
pre_result <= result; 
next_x1 <= multiplier; 
next_x0 <= 1'b0;
op_done <= 1'b1;
end
//multiplier result 출력 

default: begin
next_data_count <= 6'bx;
op_done <= 1'bx;
next_u <= 32'bx;
next_v <= 32'bx;
next_x0 <= 1'bx;
next_x1 <= 32'bx;
pre_result <= 64'bx;
end  

endcase
end
endmodule
