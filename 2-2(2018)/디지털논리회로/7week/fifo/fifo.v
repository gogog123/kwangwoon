module _dff_r(clk, reset_n, d, q);
//dflip-flop module 
input clk, reset_n, d;
output reg q;
always @(posedge clk or negedge reset_n)
//clk rising edge, reset_n falling edgd 일 때 항상 
begin
if(reset_n == 0) q <= 1'b0; //reset_n=0 일 때 q=0
else             q <= d;
end
endmodule 

module _dff_3_r(clk, reset_n, d, q);
//3input d flipflop module
input clk, reset_n;
input  [2:0] d;
output [2:0] q;

_dff_r U0_dff_r(.clk(clk), .reset_n(reset_n),.d(d[0]),.q(q[0]));
_dff_r U1_dff_r(.clk(clk), .reset_n(reset_n),.d(d[1]),.q(q[1]));
_dff_r U2_dff_r(.clk(clk), .reset_n(reset_n),.d(d[2]),.q(q[2]));

endmodule 

module _dff_4_r(clk, reset_n, d, q);
//4input d flipflop module
input clk, reset_n;
input  [3:0] d;
output [3:0] q;

_dff_r U0_dff_r(.clk(clk), .reset_n(reset_n),.d(d[0]),.q(q[0]));
_dff_r U1_dff_r(.clk(clk), .reset_n(reset_n),.d(d[1]),.q(q[1]));
_dff_r U2_dff_r(.clk(clk), .reset_n(reset_n),.d(d[2]),.q(q[2]));
_dff_r U3_dff_r(.clk(clk), .reset_n(reset_n),.d(d[3]),.q(q[3]));
endmodule 

module _dff_32_r(clk, reset_n, d, q);
//32input d flipflop module
input clk, reset_n;
input [31:0] d;
output [31:0] q;

_dff_4_r U0_dff_4_r(.clk(clk),.reset_n(reset_n),.d(d[3:0]),.q(q[3:0]));
_dff_4_r U1_dff_4_r(.clk(clk),.reset_n(reset_n),.d(d[7:4]),.q(q[7:4]));
_dff_4_r U2_dff_4_r(.clk(clk),.reset_n(reset_n),.d(d[11:8]),.q(q[11:8]));
_dff_4_r U3_dff_4_r(.clk(clk),.reset_n(reset_n),.d(d[15:12]),.q(q[15:12]));
_dff_4_r U4_dff_4_r(.clk(clk),.reset_n(reset_n),.d(d[19:16]),.q(q[19:16]));
_dff_4_r U5_dff_4_r(.clk(clk),.reset_n(reset_n),.d(d[23:20]),.q(q[23:20]));
_dff_4_r U6_dff_4_r(.clk(clk),.reset_n(reset_n),.d(d[27:24]),.q(q[27:24]));
_dff_4_r U7_dff_4_r(.clk(clk),.reset_n(reset_n),.d(d[31:28]),.q(q[31:28]));
endmodule 

module _mx2(d0,d1,sel,dout);
input [31:0]d0,d1;            
input sel;                
output [31:0]dout;              

assign dout= (sel==1'b1)? d0:d1;
//sel=1일 때 dout=d0, 아닐때 dout=d1 
endmodule

module fifo(clk,reset_n,rd_en,wr_en,d_in,d_out,data_count,full,empty,wr_ack,wr_err,rd_ack,rd_err);
//top module of fifo 
input clk, reset_n, rd_en, wr_en; //rd_en:write enalble, wr_en:write address
input [31:0] d_in; //read address
output [31:0] d_out; //read data
output full, empty; //data full, empty signal
output wr_ack, wr_err, rd_ack, rd_err;
output [3:0] data_count; //data count vector 

wire [2:0] head, next_head;
wire [2:0] tail, next_tail;
wire [2:0] state, next_state;
wire [3:0] next_data_count;
wire we, re;
wire [31:0] to_mux, to_ff;

fifo_ns U0_fifo_ns(.wr_en(wr_en),.rd_en(rd_en),.state(state),.data_count(data_count), .next_state(next_state));
fifo_cal U0_fifo_cal(.state(state),.head(head),.tail(tail),.data_count(data_count),.we(we),.re(re),.next_head(next_head),.next_tail(next_tail),.next_data_count(next_data_count));

_dff_3_r U0_dff_3_r(.clk(clk),.reset_n(reset_n),.d(next_state),.q(state)); //next_state
_dff_3_r U2_dff_3_r(.clk(clk),.reset_n(reset_n),.d(next_head),.q(head));   //next_head
_dff_3_r U3_dff_3_r(.clk(clk),.reset_n(reset_n),.d(next_tail),.q(tail));   //next_tail
_dff_4_r U1_dff_4_r(.clk(clk),.reset_n(reset_n),.d(next_data_count),.q(data_count)); //next_data_count

fifo_out U0_fifo_out(.state(state),.data_count(data_count),.full(full),.empty(empty),.wr_ack(wr_ack),.wr_err(wr_err),.rd_ack(rd_ack),.rd_err(rd_err));
Register_file U0_Register_file(.clk(clk), .reset_n(reset_n), .wAddr(tail), .wData(d_in), .we(we), .rAddr(head), .rData(to_mux));
_mx2 U0_mx2(.d0(to_mux),.d1(32'h0),.sel(re),.dout(to_ff));
_dff_32_r U0_dff_32_r(.clk(clk),.reset_n(reset_n),.d(to_ff),.q(d_out));

//instance of register file, 4dff, output logic, next state logic, calculate address logic
endmodule 


