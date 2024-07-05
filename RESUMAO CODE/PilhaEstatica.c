#include <stdio.h>
#include <stdlib.h>

#define tamanho 5 //constante de tamanho 5

struct tpilha {
    int item[tamanho]; //vetor com 5 de tamanho no máximo
    int topo; 
};

struct tpilha pilha;

int empilha(int elemento) {
    if (pilha.topo == tamanho) { //se o topo for igual ao tamanho pilha cheia 
        printf("pilha cheia nada a adicionar...\n");
    }else {
        pilha.item[pilha.topo] = elemento;
        pilha.topo = pilha.topo + 1; //empilha.topo++

        return elemento;
    }
}

void imprimir () {
    int i = 0;
    if (pilha.topo == 0) {
        printf("Pilha está vazia... Nada a imprimir\n");
    }else {
        printf("Elementos da pilha: ");
        while(i < pilha.topo) { //vai imprimir só enquanto o valor do topo
            printf("%d, ", pilha.item[i]);
            i++;
        }
        printf("\n");
    }
}

int desempilhar () {
    if (pilha.topo == 0 ) {
        printf("Nada a desempilhar...\n");
    
    }else {
        pilha.topo = pilha.topo - 1;//ou pilha.topo--;

        return pilha.item[pilha.topo];
    }


}

//ver topo
void vertopo() {
    printf("O meu topo é :%d", pilha.topo);
}

int main () {
    int desempilhado;
    pilha.topo = 0;
    empilha(12);
    empilha(13);
    empilha(5);
    empilha(6);
    empilha(8);

    vertopo();
    imprimir();

    desempilhado = desempilhar();
    printf("Elemento desempilhado foi: %d\n", desempilhado);

    imprimir();
    return 0;
}