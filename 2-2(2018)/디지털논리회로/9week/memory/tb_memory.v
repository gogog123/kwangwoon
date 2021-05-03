`timescale 1ns/100ps

module tb_memory;
reg tb_clk;
reg tb_cen, tb_wen;
reg [4:0] tb_addr;
reg [31:0] tb_din;
wire [31:0] tb_dout;

memory U0_memory(.clk(tb_clk),.cen(tb_cen),.wen(tb_wen),.addr(tb_addr),.din(tb_din),.dout(tb_dout));
//instance memory

always #2.5 tb_clk=~tb_clk;

initial
begin
tb_clk=0; tb_cen=0; tb_wen=0; tb_addr=5'b0; tb_din=32'b0;
#8 tb_cen=1'b1; tb_wen=1'b1;
#5 tb_addr=5'h01; tb_din=32'h1;
#5 tb_addr=5'h02; tb_din=32'h2;
#5 tb_addr=5'h03; tb_din=32'h3;
#5 tb_addr=5'h04; tb_din=32'h4;
#5 tb_addr=5'h05; tb_din=32'h5;
#5 tb_addr=5'h06; tb_din=32'h6;
#5 tb_addr=5'h07; tb_din=32'h7;
#5 tb_addr=5'h08; tb_din=32'h8;
#5 tb_addr=5'h09; tb_din=32'h9;
#5 tb_addr=5'h0a; tb_din=32'ha;
#5 tb_addr=5'h0b; tb_din=32'hb;
#5 tb_addr=5'h0c; tb_din=32'hc;
#5 tb_addr=5'h0d; tb_din=32'hd;
#5 tb_addr=5'h0e; tb_din=32'he;
#5 tb_addr=5'h0f; tb_din=32'hf;
#5 tb_addr=5'h10; tb_din=32'h10;
#5 tb_addr=5'h11; tb_din=32'h11;
#5 tb_addr=5'h12; tb_din=32'h12;
#5 tb_addr=5'h13; tb_din=32'h13;
#5 tb_addr=5'h14; tb_din=32'h14;
#5 tb_addr=5'h15; tb_din=32'h15;
#5 tb_addr=5'h16; tb_din=32'h16;
#5 tb_addr=5'h17; tb_din=32'h17;
#5 tb_addr=5'h18; tb_din=32'h18;
#5 tb_addr=5'h19; tb_din=32'h19;
#5 tb_addr=5'h1a; tb_din=32'h1a;
#5 tb_addr=5'h1b; tb_din=32'h1b;
#5 tb_addr=5'h1c; tb_din=32'h1c;
#5 tb_addr=5'h1d; tb_din=32'h1d;
#5 tb_addr=5'h1e; tb_din=32'h1e;
#5 tb_addr=5'h1f; tb_din=32'h1f;
//addr로 들어온 주소에 din값을 작성 
#5 tb_cen=1'b0; tb_wen=1'b0; tb_addr=5'b0; tb_din=32'b0;
#10 tb_cen=1'b1;
#5 tb_addr=5'h01;
#5 tb_addr=5'h02;
#5 tb_addr=5'h03; 
#5 tb_addr=5'h04;
#5 tb_addr=5'h05;
#5 tb_addr=5'h06;
#5 tb_addr=5'h07;
#5 tb_addr=5'h08;
#5 tb_addr=5'h09; 
#5 tb_addr=5'h0a;
#5 tb_addr=5'h0b;
#5 tb_addr=5'h0c;
#5 tb_addr=5'h0d;
#5 tb_addr=5'h0e;
#5 tb_addr=5'h0f;
#5 tb_addr=5'h10;
#5 tb_addr=5'h11;
#5 tb_addr=5'h12; 
#5 tb_addr=5'h13;
#5 tb_addr=5'h14;
#5 tb_addr=5'h15;
#5 tb_addr=5'h16;
#5 tb_addr=5'h17;
#5 tb_addr=5'h18;
#5 tb_addr=5'h19;
#5 tb_addr=5'h1a;
#5 tb_addr=5'h1b;
#5 tb_addr=5'h1c;
#5 tb_addr=5'h1d;
#5 tb_addr=5'h1e;
#5 tb_addr=5'h1f;
//addr로 들어온 주소에 있는 값을 dout으로 출력 
#10 $stop;
end
//memory testbench
endmodule 


