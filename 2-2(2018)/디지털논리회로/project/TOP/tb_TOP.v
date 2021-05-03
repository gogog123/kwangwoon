module tb_TOP; // testbench of TOP

reg 			clk, reset_n; // reg value
reg 			M0_req, M0_wr; // reg value
reg	[7:0]	M0_address; // reg value
reg	[31:0]	M0_dout; // reg value
reg wr; // reg value

wire			M0_grant, M1_grant; // wire value
wire	[31:0]	M_din; // wire value
wire			m_interrupt, multi_opdone; // wire value

TOP U0_TOP(clk, reset_n, M0_req, M0_wr, M0_address, M0_dout, M0_grant, M1_grant, M_din, m_interrupt, multi_opdone); // TOP module instance
always #5 clk = ~clk; // clock purse

initial // testbench start
begin
clk=0; reset_n=0; M0_req=0; M0_wr=0; M0_address=0; M0_dout=0; wr=0; #10; // initial set
M0_req=1; reset_n = 1; #10; //testbench master

M0_wr=1;  M0_address=32; M0_dout=10; #10;
M0_wr=1;  M0_address=33; M0_dout=11; #10;
M0_wr=1;  M0_address=34; M0_dout=12; #10;
M0_wr=1;  M0_address=35; M0_dout=13; #10;//A Matrix write


M0_wr=1;  M0_address=64; M0_dout=14; #10;
M0_wr=1;  M0_address=65; M0_dout=16; #10;
M0_wr=1;  M0_address=66; M0_dout=15; #10;
M0_wr=1;  M0_address=67; M0_dout=17; #10;//B Matrix write

M0_wr=0;  M0_address=32; M0_dout=10; #10;
M0_wr=1;  M0_address=0; M0_dout=0; #10;
M0_wr=0;  M0_address=33; M0_dout=11; #10;
M0_wr=1;  M0_address=0; M0_dout=0; #10;
M0_wr=0;  M0_address=32; M0_dout=10; #10;
M0_wr=1;  M0_address=0; M0_dout=0; #10;
M0_wr=0;  M0_address=33; M0_dout=11; #10;
M0_wr=1;  M0_address=0; M0_dout=0; #10;
M0_wr=0;  M0_address=34; M0_dout=12; #10;
M0_wr=1;  M0_address=0; M0_dout=0; #10;
M0_wr=0;  M0_address=35; M0_dout=13; #10;
M0_wr=1;  M0_address=0; M0_dout=0; #10;
M0_wr=0;  M0_address=34; M0_dout=12; #10;
M0_wr=1;  M0_address=0; M0_dout=0; #10;
M0_wr=0;  M0_address=35; M0_dout=13; #10;
M0_wr=1;  M0_address=0; M0_dout=0; #10;//A Matrix read and send MATRIX_top's A_FIFO

M0_wr=0; M0_address=64; M0_dout=14; #10;
M0_wr=1;  M0_address=1; M0_dout=0; #10;
M0_wr=0; M0_address=65; M0_dout=16; #10;
M0_wr=1;  M0_address=1; M0_dout=0; #10;
M0_wr=0; M0_address=66; M0_dout=15; #10;
M0_wr=1;  M0_address=1; M0_dout=0; #10;
M0_wr=0; M0_address=67; M0_dout=17; #10;
M0_wr=1;  M0_address=1; M0_dout=0; #10;
M0_wr=0; M0_address=64; M0_dout=14; #10;
M0_wr=1;  M0_address=1; M0_dout=0; #10;
M0_wr=0; M0_address=65; M0_dout=16; #10;
M0_wr=1;  M0_address=1; M0_dout=0; #10;
M0_wr=0; M0_address=66; M0_dout=15; #10;
M0_wr=1;  M0_address=1; M0_dout=0; #10;
M0_wr=0; M0_address=67; M0_dout=17; #10;
M0_wr=1;  M0_address=1; M0_dout=0; #10;//B Matrix read and send MATRIX_top's B_FIFO
M0_address=8'b00000011; M0_wr=1'b1; M0_req=1'b0; M0_dout=32'b1; // multi switch

while(multi_opdone!=1'b1) // multiplication
begin
#10;
end
M0_address=8'b000000010; // enable of m_interrupt
#10 M0_address=8'b00000100; // adder switch
while(m_interrupt!=1'b1) // addering
begin
#10;
end


#10 M0_address=8'b00000110; M0_wr=1'b0; // read register file
while(M1_grant!=1'b0) // M1 master
begin
#10;
end
#90 M0_address=8'b00000101; // clearing
#10 M0_wr=0;  M0_address=8'b01100000; M0_dout=10; // check result memory value
#10 M0_wr=0;  M0_address=8'b01100001; M0_dout=11; // check result memory value 
#10 M0_wr=0;  M0_address=8'b01100010; M0_dout=12;  // check result memory value
#10 M0_wr=0;  M0_address=8'b01100011; M0_dout=13;  // check result memory value
#20 $stop;
end
endmodule
