#include <stdio.h>
#include <stdlib.h>

int main () {
    int *ptr, x=30;
    printf("Consulta de ptr sem malloc\n");
    printf("Endereco: %p \n\n", ptr);

    printf("Consulta X");
    printf("Endereco: %p \nValor: %d\n\n", &x, x);
    
    printf("Consulta ponteiro com malloc aleatorio");
    ptr = (int *) malloc(sizeof (int));
    printf("Endereco: %p \nValor: %d\n\n", ptr, *ptr);


    *ptr = 10;
    printf("Consulta com a atribuicao no valor do ponteiro");
    printf("Endereco: %p \nValor: %d\n\n", ptr, *ptr);

    ptr = &x;
    printf("Consulta com endereco de x sendo passado para o ponteiro");
    printf("Endereco: %p \nValor: %d\n\n", ptr, *ptr);

    //o endereço original do ponteiro se perdeu

    printf("Consulta de um novo malloc para ptr");
    ptr = (int *) malloc(sizeof (int));
    printf("\nEndereco: %p \nValor: %d\n", ptr, *ptr);

}

//Usamos malloc para armazenar memoria suficiente para um vetor