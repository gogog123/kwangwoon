`timescale 1ns/100ps

module tb_register32; //tb_32bit register module
reg tb_clk;
reg [31:0]tb_d;
wire [31:0] tb_q;

_register32 U0_register32(.clk(tb_clk),.d(tb_d[31:0]),.q(tb_q[31:0]));
//instance 
always #12.5 tb_clk=~tb_clk;
initial
begin 
tb_clk=0; tb_d=32'h12345678;
#7.5 tb_d=32'h98765432;
#7.5 tb_d=32'hffeeddcc;
#15 tb_d=32'hbbaaccdd;
#5 tb_d=32'h77665544;
#10 tb_d=32'h33221100;
#10 tb_d=32'h12345678;
#15 $stop;
end 
//testbench
endmodule 