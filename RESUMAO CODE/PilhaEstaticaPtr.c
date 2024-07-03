#include <stdio.h>
#include <stdlib.h>

#define tamanho 5

struct tpilha {
    int dados[tamanho];
    int topo;
};

int empilhar (struct tpilha *p, int item) {
    if (p->topo == tamanho) {//(*p).topo é uma outra forma de escrita
        printf("Pilha está cheia, nada a imprimir\n");

    }else {
        p->dados[p->topo] = item;
        p->topo++;

        return p->dados[p->topo - 1]; //mostra o item que acabei de adicionar
    }

}

int desempilhar (struct tpilha *p) {
    if(p->topo == 0) {
        printf("Filha está vazia, nada a desempilhar...\n");

    }else {
        
        p->topo--;
        return p->dados[p->topo];;
    }
}

void imprimir (struct tpilha *p) {
    if(p->topo == 0) {
        printf("Pilha está vazia, nada a imprimir...\n");

    }else {
        printf("Os elemento da pilha são: ");

        for(int i = 0; i < tamanho; i++) {
            printf("%d, ", p->dados[i]);
        }
        printf("\n");
    }
}

void LimparPilha (struct tpilha *p) {
    while(p->topo != -1) {
        p->dados[p->topo] = 0;
        p->topo--;
    }
}

/* void LimparPilha (struct tpilha *p) {
    p->topo = -1;
} */


int main (void) {
    struct tpilha teste;
    int retorno;

    retorno = empilhar(&teste, 12);
    printf("Item %d adicionado\n", retorno);

    retorno = empilhar(&teste, 15);
    printf("Item %d adicionado\n", retorno);

    retorno = empilhar(&teste, 20);
    printf("Item %d adicionado\n", retorno);

    retorno = empilhar(&teste, 2);
    printf("Item %d adicionado\n", retorno);

    retorno = desempilhar(&teste);
    printf("Item %d desempilhado\n", retorno);

    imprimir(&teste);
    LimparPilha(&teste);

    imprimir(&teste);

    return 0;
}