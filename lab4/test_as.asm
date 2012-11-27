SECTION .data

SECTION .text                   ; stuff below goes into the TEXT segment of the processor
        ALIGN 16                ; align segments on a 16-byte boundary
        BITS  32                ; generate code for 32 bits processor
        
        GLOBAL _llmultiply      ; llmultiply will be used somewhere else(in our case a C file and in tht fil it'll be defined EXTERN

_llmultiply
        ;; subroutine prologue
        push ebp                ;save old pts value
        mov ebp,esp             ;set the new base ptr value

        ;; saving the registers to be modified in the code
        push eax
        push ecx
        push edx
        push edi
        push esi

        ;; start the subroutine
        mov eax,[ebp+8]        ; get Al
        mov ebx,[ebp+16]        ; get Bl..so ebx is NOT a pointer to Bl...it directly has the value..since we've used square brackets around ebp+16!

        mul ebx                 ; multiply Bl with Al. EDX:EAX = upper(Al*Bl):lower(Al*Bl)

        mov edi,eax             ; store lower 32 bits of Al*Bl into edi
        mov esi,edx             ; store upper 32 bits of Al*Bl into esi

        mov eax, [ebp+12]       ; get Ah
        mul ebx                 ; multiply Bl with Ah, EDX:EAX upper(Bl*Ah):lower(Bl*Ah)

        add eax,esi             ; Add upper(Al*Bl) with lower(Bl*Ah)
        adc edx,0               ; now edx contains the carry out from the previous addition plus upper(Bl*Ah)

        mov esi,eax             ; mov lower32 of above addition to esi
        mov ecx,edx             ; mov upper(Bl*Ah) and carry from above add to ecx

        mov eax, [ebp+20]       ; get Bh
        mov ebx, [ebp+8]        ; get Al
        
        mul ebx                 ; multiply Bh * Al, EDX:EAX upper(Bh*Al):lower(Bh*Al)

        add eax,esi             ; add lower(Bh*Al) with upper(Al*Bl) and lower(Bl*Ah) 
        adc edx,ecx             ; add upper(Bh*Al) with the carry(from above addition)

        mov esi,eax             ; lower word of partial product goes into esi
        mov ecx,edx             ; higher word of partial product goes into ecx

        mov eax, [ebp+12]       ; get Ah
        mov ebx, [ebp+20]       ; get Bh
        
        mul ebx                 ; multiply Bh * Ah, EDX:EAX upper(Bh*Ah):lower(Bh*Ah)

        add eax,ecx             ; add higher word of partial product with lower word of Ah*Bh. result in eax
        adc edx,0               ; add carry from previous addition with higher word of Ah*Bh and result in EDX

        ;; now our product looks like edx:eax:esi:edi and we need to somehow get {[ebp + 24] to [ebp + 28]} to show us the location of the result       

        ;; now [ebp+27] is only an eight bit data. what happens when I transfer it to ebx?..what abt the remaining 24bits? Im assuming they get filled with zeros automatically.
        mov ebx, 0x00000000     ; clear register ebx
        add ebx,[ebp+27]        ; now ebx contains the MSB of  start address of result, so basically ebx is like a ptr tp ptr in C         
        shl ebx,24              ; shift the MSB to the 'right' location in the register

        mov ecx, 0x00000000     ; clear register ecx
        add ecx,[ebp+26]        ; get the next MSB into ecx
        shl ecx,16              ; shift the MSB to the corresponding location in the reg

        add ebx,ecx             ; Now ebx contains the upper word of the start address

        mov ecx, 0x00000000     ; clear register ecx
        add ecx,[ebp+25]        ; get the next MSB into ecx
        shl ecx,8               ; shift the MSB to the corresponding location in the reg

        add ebx,ecx             ; Now ebx contains the upper 24bits of the start address at the proper bit locations

        mov ecx, 0x00000000     ; clear register ecx
        add ecx,[ebp+24]        ; get the LSB into ecx

        add ebx,ecx             ; Now ebx contains the proper start address of 'result'

        ;; now we move the various 32bit wide chunks of the result into the actual 'result' variable

        mov [ebx],edi           ; lower 32bits of the result start from result(0)
        mov [ebx + 8],esi       ; next 32bits of the result start from result(8)
        mov [ebx + 16],eax      ; next 32bits of the result start from result(16)
        mov [ebx + 24],edx      ; final 32bits of the result start from result(24)

        ;; subroutine epilogue -- now we pop the values out in the reverse order and restore the state of the machine
        pop esi
        pop edi
        pop edx
        pop ecx
        pop eax
        pop ebp

        ret
        