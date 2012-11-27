section .text
	global malami 			;its do atoi, turn string into int
malami:
	push	ebp				;insert ebp to the stack for remainder
	mov	ebp, esp			;insert esp to ebp, we dont konw what esp have
	sub	esp, 4				;decrement 4 from esp
	mov	DWORD [ebp-4], 0	;we belive it take 0 as a word into [ebp-4]
	jmp	.L2					;do what L2 wants
	
.L3:
	mov	eax, DWORD [ebp-4] 	;input
	mov ebx, eax ;times 10
	sal eax, 3
	sal ebx, 1
	add eax, ebx
	mov	ebx, DWORD [ebp+8] 	;moving somthing
	movzx	ebx, BYTE [ebx]	;keep moving
	movsx	ebx, bl			;die hard 4
	add	eax, ebx			;sum whatever
	sub	eax, 48				;dec 48 to get int
	mov	DWORD [ebp-4], eax	;	put the new eax to input
	add	DWORD [ebp+8], 1	;   go to next char
.L2:
	mov	eax, DWORD [ebp+8]	;return value 
	movzx	eax, BYTE [eax] ;enter input
	test	al, al			;test the string == cmp al,0
	jne	.L3					;loop if it not equal
	mov	eax, DWORD [ebp-4]  ;what we accumilate to eax
	mov esp, ebp			;the return value to esp
	pop ebp					;pop ebp
	ret						;return erly ebp
