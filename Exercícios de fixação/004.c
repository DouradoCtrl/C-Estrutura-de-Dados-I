#include <stdio.h>
#include <stdlib.h>

//Implemente uma função em C chamada mediaArray que aceita um ponteiro para um array de números inteiros e seu tamanho como argumentos, e retorna a média dos valores no array.

float MediaArray (int *array, int size) {
    int soma = 0; 
    float media = 0;

    for (int i = 0; i < size; i++) {
        soma = soma + array[i];
    }

    media = (float)soma/size;
    return media;
}

int main (void) {
    int size, *array, i = 0; float media_main;
    printf("Escolha o tamanho do array: ");
    scanf("%d", &size);
    printf("\n");
    
    array = (int *) malloc (size * sizeof(int));

    for (i = 0; i < size; i++) {
        printf("Digite um número inteiro: ");
        scanf("%d", &array[i]); 
    }

    media_main = MediaArray(array, size);
    printf("A média do array é: %.2f \n", media_main);


    free(array);
    return 0;
}