#include <stdio.h>
#include <stdlib.h>

#define tamanho 5

struct tfila {
    int dado[tamanho];
    int fim;
};

struct tfila fila;

int enfileirar(int elemento) {
    if (fila.fim == tamanho) {
        printf("Fila cheia...\n");

    }else {
        fila.dado[fila.fim] = elemento;
        fila.fim++;

        return fila.dado[fila.fim - 1];
    }
}

int desenfileirar () {
    int elemento;
    if(fila.fim == 0){
        printf("Fila vazia, nada a mostrar");
    }else {
        elemento = fila.dado[0];
        for(int i = 0; i < tamanho; i++) {
            fila.dado[i] = fila.dado[i + 1];
        }
        fila.dado[fila.fim] = 0; //somente pra zerar o final
        fila.fim--;
        return elemento;
    }
}

void imprimir() {
    if(fila.fim == 0) {
        printf("Fila está vazia, nada a mostrar\n");
    }else {
        printf("A sua fila é: ");
        for(int i = 0; i < fila.fim; i++) {
            printf("%d,", fila.dado[i]);
        }
        printf("\n");
    }
}

int main () {
    int n1 = enfileirar(12);

    printf("Elemento retornado %d \n", n1);
    n1 = enfileirar(123);
    printf("Elemento retornado %d \n", n1);
    n1 = enfileirar(112);
    printf("Elemento retornado %d \n", n1);
    imprimir();

    n1 = desenfileirar();
    printf("Elemento desempilhado foi %d \n", n1);
    imprimir();

    n1 = enfileirar(1123);
    printf("Elemento retornado %d \n", n1);
    imprimir();

    n1 = desenfileirar();
    printf("Elemento desempilhado foi %d \n", n1);
    imprimir();

    

    return 0;
}


//fazer o teste de esvaziar pilha depois