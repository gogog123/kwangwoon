`timescale 1ns/100ps

module tb_seg_dec;
  reg [3:0] tb_iHex;
  wire [6:0] tb_oSEG7;
  
  seg_dec U0_seg_dec(.iHex(tb_iHex), .oSEG7(tb_oSEG7));
  
  initial
  begin
      tb_iHex = 4'h0; //0
		#10; tb_iHex = 4'h1;	//1
		#10; tb_iHex = 4'h2;	//2
		#10; tb_iHex = 4'h3;	//3
		#10; tb_iHex = 4'h4;	//4
		#10; tb_iHex = 4'h5;	//5
		#10; tb_iHex = 4'h6;	//6
		#10; tb_iHex = 4'h7;	//7
		#10; tb_iHex = 4'h8;	//8
		#10; tb_iHex = 4'h9;	//9
		#10; tb_iHex = 4'hA;	//A
		#10; tb_iHex = 4'hb;	//b
		#10; tb_iHex = 4'hC;	//C
		#10; tb_iHex = 4'hd;	//d
		#10; tb_iHex = 4'hE;	//E
		#10; tb_iHex = 4'hF;	//F
		#10; $stop;

	end

endmodule 