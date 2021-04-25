cr equ 0x0d

	AREA problem, CODE, READONLY
		ENTRY
	
main
	LDR r0, =Table
	LDR r3, Address1
	eor r1, r1, r1
	
Loop
	LDRB r2, [r0], #1
	cmp r2, #cr
	BEQ Done
	ADD r1, r1, #1
	STRB r2, [r3], #1
	BAL Loop
	
Done
	STR r1, CharCount
	mov pc, #0
	
	AREA Data1, DATA
		
Table
	ALIGN
	DCB "Hello, World", cr
	
	AREA Result, DATA
	
CharCount
	DCB 0
	
Address1 & &00004000
	END