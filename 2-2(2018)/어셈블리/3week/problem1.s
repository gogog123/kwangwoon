	AREA ARMex, CODE, READONLY
		ENTRY
		
start
	ldr r0, tempaddr
	mov r1, #1
	add r2, r1, r1              ;r2=r1+r1=1+1=2
	add r3, r2, r2, lsl #1      ;r3=r2+(r2*2)=2+(2*2)=6
	mov r4, r3, lsl #2          ;r4=r3*4=6*4=24
	add r5, r4, r4, lsl #2      ;r5=r4+(r4*4)=24+24*4=120
	
	mov r6, r5, lsl #2          ;r6=r5*4
	add r6, r6, r5, lsl #1      ;r6=r6+(r5*2)
	
	mov r7, r6, lsl #2          ;r7=r6*4
	add r7, r7, r6, lsl #1      ;r7=r7+(r6*2)
	add r7, r7, r6              ;r7=r7+r6
	
	mov r8, r7, lsl #3          ;r8=r7*8
	add r9, r8, r8, lsl #3      ;r9=r8+(r8*8)
	
	mov r10, r9, lsl #3         ;r10=r9*8
	add r10, r10, r9, lsl #1    ;r10=r9+(r9*2)
	
	str r10, [r0]
	
	mov pc, lr

tempaddr & &40000

	end