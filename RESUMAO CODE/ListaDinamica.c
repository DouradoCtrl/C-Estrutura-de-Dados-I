#include <stdio.h>
#include <stdlib.h>

struct NO {
    int dado;
    struct NO *prox;
};


void imprimir (struct NO *ptr) {
    while(ptr != NULL) {
        printf("%d,", ptr->dado);
        ptr = ptr->prox;
    }
      
}


int main (void) {
    

    return 0;
}


//na lista nao temos restricoes podemos imprimir no inicio/meio/fim, tanto faz
//A lista é como se fosse uma pilha ou uma fila porém, sem restrições.
//acima só tem a funcao de como imprimir