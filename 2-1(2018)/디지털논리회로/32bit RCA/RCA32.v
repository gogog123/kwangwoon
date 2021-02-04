module RCA32 (S, Cout, A, B, Cin); // module start(input, output)

 input [31:0] A, B; // 32bit A,B Declaration
 input Cin; 
 output [31:0] S;
 output Cout;
 wire [31:0] c; // wire between Fulladder

 fulladder a1(A[0], B[0], Cin, S[0], c[0]);
 fulladder a2(A[1], B[1], c[0], S[1], c[1]);
 fulladder a3(A[2], B[2], c[1], S[2], c[2]);
 fulladder a4(A[3], B[3], c[2], S[3], c[3]);
 fulladder a5(A[4], B[4], c[3], S[4], c[4]);
 fulladder a6(A[5], B[5], c[4], S[5], c[5]);
 fulladder a7(A[6], B[6], c[5], S[6], c[6]);
 fulladder a8(A[7], B[7], c[6], S[7], c[7]);
 fulladder a9(A[8], B[8], c[7], S[8], c[8]);
 fulladder a10(A[9], B[9], c[8], S[9], c[9]);
 fulladder a11(A[10], B[10], c[9], S[10], c[10]);
 fulladder a12(A[11], B[11], c[10], S[11], c[11]);
 fulladder a13(A[12], B[12], c[11], S[12], c[12]);
 fulladder a14(A[13], B[13], c[12], S[13], c[13]);
 fulladder a15(A[14], B[14], c[13], S[14], c[14]);
 fulladder a16(A[15], B[15], c[14], S[15], c[15]);
 fulladder a17(A[16], B[16], c[15], S[16], c[16]);
 fulladder a18(A[17], B[17], c[16], S[17], c[17]);
 fulladder a19(A[18], B[18], c[17], S[18], c[18]);
 fulladder a20(A[19], B[19], c[18], S[19], c[19]);
 fulladder a21(A[20], B[20], c[19], S[20], c[20]);
 fulladder a22(A[21], B[21], c[20], S[21], c[21]);
 fulladder a23(A[22], B[22], c[21], S[22], c[22]);
 fulladder a24(A[23], B[23], c[22], S[23], c[23]);
 fulladder a25(A[24], B[24], c[23], S[24], c[24]);
 fulladder a26(A[25], B[25], c[24], S[25], c[25]);
 fulladder a27(A[26], B[26], c[25], S[26], c[26]);
 fulladder a28(A[27], B[27], c[26], S[27], c[27]);
 fulladder a29(A[28], B[28], c[27], S[28], c[28]);
 fulladder a30(A[29], B[29], c[28], S[29], c[29]);
 fulladder a31(A[30], B[30], c[29], S[30], c[30]);
 fulladder a32(A[31], B[31], c[30], S[31], Cout); 
 // A, B 각 input 입력
 // 전 fulladder Cout이 다음 fulladder의 Cin으로 들어감 

endmodule 


module fulladder(A, B, Cin, S, Cout); // Make fulladder module

 input A, B, Cin;
 output S, Cout; // input, output decalration
 assign S = (A^B^Cin); // S = A(xor)B(xor)Cin
 assign Cout = ((A&B)|(B&Cin)|(A&Cin)); // 

endmodule
