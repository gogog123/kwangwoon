	AREA ARMex, CODE, READONLY
		ENTRY
Main
	LDR r0, =Valuel
	LDR r1, Address1
	MOV r6, #10

Loop
	LDR r2, [r0], #4
	ADD r3, r3, r2
	
	ADD r5, r5, #1
	CMP r5, r6
	BEQ Endline
	B Loop
	
Endline
	STRB r3, [r1]
	MOV pc,lr
	
Valuel DCD 11,13,15,17,19,21,23,25,27,29
	
Address1 DCD &00004000
	END