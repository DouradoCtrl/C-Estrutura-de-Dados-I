#include <stdio.h>
#include <stdlib.h>

void executa(int x, int *ptr) 
{
    printf("O conteúdo da variável x = %d\n", x);
    printf("O endereço da variável x = %p\n", &x);
    printf("O conteúdo apontado ptr  = %d\n", *ptr);
    printf("O endereço apontado ptr  = %p\n", ptr);
    printf("O endereço do ptr        = %p\n", &ptr);
}

int main () {
    int x = 19;
    int *ptr;
    
    ptr = &x;
    executa(x, ptr);

    *ptr = 25;
    printf("\n============================================\n\n");
    executa(x, ptr);
    return 0;
}

