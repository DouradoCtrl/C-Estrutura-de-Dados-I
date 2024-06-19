#include <stdio.h>
#include <stdlib.h>

//criando estrutura de dados tipo pilha

struct tipo_pilha {
    int dados[3];
    int ini;
    int topo;
};

struct tipo_pilha pilha; //declarado fora pois se torna do tipo global

//push
void empilha (int elemento) {
    if(pilha.topo == 3) {
        printf("Pilha está cheia, elemento que tentou adicionar: %d\n", elemento);
    }else {
        pilha.dados[pilha.topo] = elemento; //vai colocar no indice pilha todo o elemento
        pilha.topo = pilha.topo + 1;

        printf("O elemento adicionado foi: %d\n", elemento);
    }
}

//pop
int desempilhar ( ) {
    int elemento;
    if (pilha.topo == pilha.ini) {
        printf("A pilha está vazia\n");

    }else {
        pilha.topo = pilha.topo - 1;
        elemento = pilha.dados[pilha.topo];

        return elemento;
    }
}

int main (void) {
    int desempilhado = 0;
    empilha(12);
    empilha(13);
    empilha(14);
    empilha(30); //pilha cheia

    desempilhado = desempilhar();
    /* desempilhado = 0; */
    

    if (desempilhado != 0) {
        printf("O elemento desempilhado foi: %d\n", desempilhado);
    }

    
    return 0;
}