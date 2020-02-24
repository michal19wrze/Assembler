#include <stdio.h>
int main(){
   
    char s[] ="AVBDdcadA";  
    char *b =s;

        asm volatile(
        ".intel_syntax noprefix;"
        "mov ebx, %1;"
        "mov ecx, %0;"
        "xor edx,edx;"
        "dec ecx;"

        "petla:"
            "mov al, [ebx+edx];"
            "cmp al, 0;"
            "je koniec;"
            "inc edx;"
            "cmp al, 'A';"
            "jb petla;"
            "cmp al, 'Z';"
            "ja petla;"
            "add al, 0x20;"
            "mov [ecx+edx],al;"
            "jmp petla;"
            
        "koniec:"
        ".att_syntax prefix;"
        :"=r"(b)
        :"r" (b)
        :"eax","ebx","ecx","edx"

            );

        printf("s= %s\n",b);
        return 0;




}