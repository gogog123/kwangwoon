	AREA ARMex, CODE, READONLY
		ENTRY
Main
	LDR r0, =Valuel
	LDR r1, Address1
	MOV r8, #10

Loop
	LDR r2, [r0], #4
	STRB r2, [r1], #-1
	
	ADD r7, r7, #1
	CMP r7, r8
	BEQ Endline
	B Loop
Endline

	MOV pc, lr
	
Valuel DCD 10,9,8,7,6,5,4,3,2,1
Address1 DCD &00004009
	END