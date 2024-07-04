#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int dados;
    struct NO *prox;
}NO;

typedef struct fila {
    NO *ini;
    NO *fim;
}fila;

fila *f;

int enfileirar(int item) {
    NO *ponteiro = (NO *)malloc(sizeof(NO));
    ponteiro->dados = item;
    ponteiro->prox = NULL;
    if(f->ini == NULL) {
        f->ini = ponteiro;
    }else {
        f->fim->prox = ponteiro;
    }
    f->fim = ponteiro;
    return ponteiro->dados;
}

int desempilhar() {
    NO *ponteiro;
    ponteiro = f->ini;

    if (ponteiro == NULL) {
        printf("Fila já está vazia, nada a desempilhar...\n");
    }else {
        
        f->ini = ponteiro->prox;
        ponteiro->prox = NULL;
        return ponteiro->dados;
        free(ponteiro);
    }

    
}

void imprimir () {
    NO *ponteiro;
    ponteiro = f->ini;

    if(ponteiro == NULL) {
        printf("Não existe fila a imprimir...\n");
    }else {
        printf("\nFILA: ");
        while(ponteiro != NULL) {
            printf("%d, ", ponteiro->dados);
            ponteiro = ponteiro->prox;
        }
        printf("\n");
    }
}


int main (void) {
    system("clear");
    f = (fila *) malloc(sizeof(fila));

    int teste;
    teste = enfileirar(12);

    printf("O elemento adicionado foi %d\n", teste);
    teste = enfileirar(1);

    printf("O elemento adicionado foi %d\n", teste);
    teste = enfileirar(3);

    printf("O elemento adicionado foi %d\n", teste);

    imprimir();

    teste = desempilhar();

    printf("O elemento desenfileirado foi %d\n", teste);

    imprimir();

    return 0;
}
