	AREA ARMex, CODE, READONLY
		ENTRY	
Main
	LDR r0, =Values1
	LDR r1, =Values2
	LDR r6, Address1
	
Loop
	LDRB r2, [r0], #1
	LDRB r3, [r1], #1
	CMP r2, #0
 	BEQ printA
	CMP r2, r3
	BEQ Loop
	B printB
printA
	MOV r7, #0x0A
	STRB r7, [r6]
	B Endline
	
printB
	MOV r7, #0x0B
	STRB r7, [r6]
	B Endline
	
Endline
	MOV pc, lr
	
Values1 DCB "Hello",0
Values2 DCB "Hello",0

Address1 DCD &00004000
	END