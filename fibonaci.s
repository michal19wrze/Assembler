.intel_syntax noprefix
.global main 
.text   

main:
    mov eax, 6
    push eax
    mov eax, 0
        call f
    pop eax

    mov eax,0
    
    
    ret





f: 
    mov ebx, [esp+4]
    cmp ebx,1
        jne skok
    mov eax,1
    
    ret




skok:
    dec ebx
    push ebx
    call f
    pop ebx
    add eax,esp
    ret



    
    
    