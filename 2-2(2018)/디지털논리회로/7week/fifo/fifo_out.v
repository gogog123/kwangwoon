module fifo_out(state,data_count,full,empty,wr_ack,wr_err,rd_ack,rd_err);
//output logic module 
input [2:0] state;
input [3:0] data_count;
output full, empty, wr_ack, wr_err, rd_ack, rd_err;
reg full, empty, wr_ack, wr_err, rd_ack, rd_err;

parameter INIT_STATE     =3'b000;
parameter NO_OP_STATE    =3'b001;
parameter WRITE_STATE    =3'b010;
parameter WR_ERROR_STATE =3'b011;
parameter READ_STATE     =3'b100;
parameter RD_ERROR_STATE =3'b101;

always @ (state, data_count)
//always state,data_count change
begin
case(state)

INIT_STATE:
if(data_count==0)begin
full=1'b0; empty= 1'b1; wr_ack=1'b0; wr_err=1'b0; rd_ack=1'b0; rd_err=1'b0; end //010000
else if(data_count==8)begin
full=1'b1; empty= 1'b0; wr_ack=1'b0; wr_err=1'b0; rd_ack=1'b0; rd_err=1'b0; end //100000
else begin
full=1'b0; empty= 1'b0; wr_ack=1'b0; wr_err=1'b0; rd_ack=1'b0; rd_err=1'b0; end //000000


NO_OP_STATE:
if(data_count == 0) begin
full=1'b0; empty= 1'b1; wr_ack=1'b0; wr_err=1'b0; rd_ack=1'b0; rd_err=1'b0; end //010000
else if(data_count == 8) begin
full=1'b1; empty= 1'b0; wr_ack=1'b0; wr_err=1'b0; rd_ack=1'b0; rd_err=1'b0; end //100000
else begin
full=1'b0; empty= 1'b0; wr_ack=1'b0; wr_err=1'b0; rd_ack=1'b0; rd_err=1'b0; end //000000

WRITE_STATE:
if(data_count==8)begin
full=1'b1; empty= 1'b0; wr_ack=1'b1; wr_err=1'b0; rd_ack=1'b0; rd_err=1'b0; end //101000
else begin
full=1'b0; empty= 1'b0; wr_ack=1'b1; wr_err=1'b0; rd_ack=1'b0; rd_err=1'b0; end //001000

WR_ERROR_STATE: begin
full=1'b1; empty= 1'b0; wr_ack=1'b0; wr_err=1'b1; rd_ack=1'b0; rd_err=1'b0; end //100100

READ_STATE:
if(data_count==0)begin
full=1'b0; empty= 1'b1; wr_ack=1'b0; wr_err=1'b0; rd_ack=1'b1; rd_err=1'b0; end //010010
else begin
full=1'b0; empty= 1'b0; wr_ack=1'b0; wr_err=1'b0; rd_ack=1'b1; rd_err=1'b0; end //000010

RD_ERROR_STATE: begin
full=1'b0; empty= 1'b1; wr_ack=1'b0; wr_err=1'b0; rd_ack=1'b0; rd_err=1'b1; end //010001

default : begin
full=1'bx; empty= 1'bx; wr_ack=1'bx; wr_err=1'bx; rd_ack=1'bx; rd_err=1'bx; end //xxxxxx
endcase 

//full,empty,wr_ack,wr_err,rd_ack,rd_err 순서대로 
end
endmodule 