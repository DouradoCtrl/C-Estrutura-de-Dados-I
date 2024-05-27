#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Troca de valores
//1. Escreva uma função em C que troque os valores de duas variáveis int usando ponteiros.
void TrocaDeValores(int *a, int *b);

void main () {    
    srand(time(NULL));

    int n1 = 5, n2 = 4;
    int *ptr1, *ptr2;
    ptr1 = &n1;
    ptr2 = &n2;

    printf("Valores antes da troca: n1 = %d, n2 = %d\n", n1, n2);

    TrocaDeValores(ptr1, ptr2);

    printf("Valores depois da troca: n1 = %d, n2 = %d\n", n1, n2);

}

void TrocaDeValores(int *a, int *b) {
    *a = rand() % 100;
    *b = rand() % 100;
}

