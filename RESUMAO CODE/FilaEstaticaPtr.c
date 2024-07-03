#include <stdio.h>
#include <stdlib.h>

#define tamanho 5

struct tfila {
    int dados[tamanho];
    int fim;
};

void inicializar(struct tfila *p) {
    p->fim = 0;

}

int enfileirar(struct tfila *p, int item) {
    if (p->fim == tamanho) {
        printf("A fila está cheia...\n");
    }else {
        p->dados[p->fim] = item;
        p->fim++;

        return p->dados[p->fim - 1];
    }
}

int desenfileirar (struct tfila *p) {
    int elemento;
    if (p->fim == 0) {
        printf("A fila está vazia, não existe nada a ser desempilhado...\n");
    }else {
        elemento = p->dados[0];
        for (int i = 0; i < tamanho; i++) {
            p->dados[i] = p->dados[i + 1];
        }
        /* p->dados[p->fim] = 0; */
        p->fim--;

        return elemento;
    }
}

void imprimir(struct tfila *p) {
    if(p->fim == 0) {
        printf("Fila vazia, não existe nada a ser impresso...\n");
    }else {
        printf("Os elementos da listas são: ");
        for(int i = 0; i < p->fim; i++) {
            printf("%d,", p->dados[i]);
        }
        printf("\n");
    }
}


int main () {
    struct tfila ptr;
    int teste;
    inicializar(&ptr);

    
    teste = enfileirar(&ptr, 69);
    printf("O elemento enfileirado foi %d\n ", teste);
    
    teste = enfileirar(&ptr, 19);
    printf("O elemento enfileirado foi %d\n ", teste);

    teste = enfileirar(&ptr, 2);
    printf("O elemento enfileirado foi %d\n ", teste);

    teste = enfileirar(&ptr, 34);
    printf("O elemento enfileirado foi %d\n ", teste);

    teste = enfileirar(&ptr, 43);
    printf("O elemento enfileirado foi %d\n ", teste);

    imprimir(&ptr);

    teste = desenfileirar(&ptr);
    printf("O elemento desenfilerado foi foi %d\n ", teste);

    imprimir(&ptr);

    return 0;
}

//fazer typedef struct aluno adicionando e acessando os dados como se fosse na atividade de semáfaro