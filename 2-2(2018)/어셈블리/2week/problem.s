	AREA ARMex, CODE, READONLY
		ENTRY

Main
	LDR r7, Address1
	MOV r0, #1
	LSL r1, r0, #1
	LSL r2, r1, #1
	LSL r2, r2, #1
	ADD r3, r0, r1
	ADD r3, r3, r2
	ADD r6, r2, r1
	
Loop
	ADD r4, r4, r3
	ADD r3, r3, r1
	ADD r5, r5, #1
	CMP r5, r6
	BEQ Endline
	B Loop
Endline 
	STRB r4, [r7]
	MOV pc, lr
Address1 & &00004000
	END