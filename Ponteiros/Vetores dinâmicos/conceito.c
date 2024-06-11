#include <stdio.h>
#include <stdlib.h>

int main () {
    int tam, *vetor, i=0;

    printf("Tamanho do vetor: ");
    scanf("%d", &tam);

    vetor = (int *) malloc(sizeof (int)*tam);

    for(i = 0; i < tam; i++) {
        printf("Posicao %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

}

//exemplo de vetor dinâmico