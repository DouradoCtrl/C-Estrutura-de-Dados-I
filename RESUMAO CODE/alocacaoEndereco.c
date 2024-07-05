#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int vetor[20];
    int tamanho_vetor = sizeof(vetor);
    int tamanhoDoInteiro = sizeof(tamanho_vetor);
    
    printf("O tamanho da minha variável vetor é %d\n", tamanho_vetor);
    printf("O tamanho da minha variável inteira é %d\n", tamanhoDoInteiro);

    return 0;
}