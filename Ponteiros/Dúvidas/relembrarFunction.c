#include <stdio.h>
#include <stdlib.h>

float soma (float n1, float n2); 
//Obrigada a função ao final do código ser lida.

void main () {
    float t1, t2, valorFinal;
    printf("Número 1: ");
    scanf("%f", &t1);
    printf("Número 2: ");
    scanf("%f", &t2);
    
    valorFinal = soma(t1, t2);
    printf("Valor = %2.f\n", valorFinal);
}

float soma (float n1, float n2) {
    float soma;
    soma = n1 + n2;
    /* printf("Soma = %2.f", soma); */
    return soma;
}
