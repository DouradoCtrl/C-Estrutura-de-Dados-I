# include <stdio.h>
# include <stdlib.h>

//Escreva um programa em C que aloque dinamicamente um array de inteiros de tamanho especificado pelo usuário e preencha-o com números inseridos pelo usuário. Em seguida, imprima os elementos do array usando ponteiros.

int main (void) {
    int n1, *array, i = 0;
    printf("Escolha o tamanho do array: ");
    scanf("%d", &n1);
    printf("\n");
    
    array = (int *) malloc (n1 * sizeof(int));

    for (i = 0; i < n1; i++) {
        printf("Digite um número inteiro: ");
        scanf("%d", &array[i]); 
    }

    printf("\n");
    printf("A sua lista é: ");
    
    for (i = 0; i < n1; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}