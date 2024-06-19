#include <stdio.h>
#include <stdlib.h>
//Escreva um programa em C que use ponteiros para encontrar o maior e o menor elemento em um array de inteiros.

void MinAndMax(int *array, int size, int *min, int *max) {
    // Inicializa min e max com o primeiro elemento do array
    *min = *max = array[0];

    // Percorre o array para encontrar o menor e o maior elemento
    for (int i = 1; i < size; i++) {
        if (array[i] < *min) {
            *min = array[i];
        }
        else if (array[i] > *max) {
            *max = array[i];
        }
    }
}

int main (void) {
    int size, *array, i = 0, min = 0, max = 0;

    printf("Escolha o tamanho do array: ");
    scanf("%d", &size);
    printf("\n");
    
    array = (int *) malloc (size * sizeof(int));

    for (i = 0; i < size; i++) {
        printf("Digite um número inteiro: ");
        scanf("%d", &array[i]); 
    }

    MinAndMax(array, size, &min, &max);

    printf("\nO maior número do array é %d\n", max);
    printf("O menor número do array é %d\n", min);

    free(array);
    return 0;
}