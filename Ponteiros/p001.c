#include <stdio.h>
#include <stdlib.h>

int main () {
    int x = 19;
    int *ptr;

    ptr = &x;

    printf("O conteúdo da variável x = %d\n", x);
    printf("O endereço da variável x = %p\n", &x);
    printf("O conteúdo apontado ptr  = %d\n", *ptr);
    printf("O endereço apontado ptr  = %p\n", ptr);
    printf("O endereço do ptr        = %p\n", &ptr);

    return 0;
}

//Ponteiros
// *ptr = O apontado por, conteúdo do endereço da variável que ptr aponta
// ptr = endereço da variável
// &ptr = endereço do ptr
