section.text 

  global main 
  extern old_main 
  extern cmp_files


main:
    push ebp
    mov ebp, esp
    push DWORD [ebp+12]
    push DWORD [ebp+8]
    call old_main
    
    
    ;push [ebp+12]
    ;push db
    ;call fopen
 

   mov esp, ebp
   pop ebp 
   ret


    ;push ebp
    ;mov ebp, esp
    ;push DWORD [ebp+12]
    ;push db
    ;call fopen
    
 

   ;mov esp, ebp
   ;pop ebp
   ;ret


;section.data
   ; romode db  "r", 0

