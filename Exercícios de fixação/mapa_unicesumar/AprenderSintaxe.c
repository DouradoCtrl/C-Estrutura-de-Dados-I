#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Pilha {
    int dados[MAX_SIZE];
    int topo;
};

struct Pilha pilha; // declarada globalmente para acesso em todo o código

void inicializar() {
    pilha.topo = -1; // pilha vazia inicialmente
}

int vazia() {
    return pilha.topo == -1;
}

int cheia() {
    return pilha.topo == MAX_SIZE - 1;
}

void empilhar(int valor) {
    if (cheia()) {
        printf("A pilha está cheia, não foi possível adicionar um novo elemento\n");
    } else {
        pilha.dados[++pilha.topo] = valor;
        printf("Elemento %d adicionado à pilha.\n", valor);
    }
}

int desempilhar() {
    if (vazia()) {
        printf("Não foi possível concluir a operação pois a pilha está vazia\n");
        return -1; // valor de erro
    } else {
        return pilha.dados[pilha.topo--];
    }
}

void imprimirPilha() {
    if (vazia()) {
        printf("A pilha está vazia, não há elementos para imprimir\n");
    } else {
        printf("Os valores da pilha são: ");
        for (int i = 0; i <= pilha.topo; i++) {
            printf("%d ", pilha.dados[i]);
        }
        printf("\n");
    }
}

int topoDaPilha() {
    if (vazia()) {
        printf("A pilha está vazia, não existe último elemento\n");
        return -1; // valor de erro
    } else {
        return pilha.dados[pilha.topo];
    }
}

int main() {
    inicializar();

    int opcao, continuar = 1, valorMain;

    while (continuar == 1) {
        system("clear");
        printf("Você pode adicionar até %d números inteiros...\n\n", MAX_SIZE);
        printf("-== PILHA OPÇÕES ==-\n");
        printf("1 - Adicionar item à pilha\n");
        printf("2 - Remover item do topo da pilha\n");
        printf("3 - Ver o último item da pilha\n");
        printf("4 - Listar a pilha inteira\n");
        printf("5 - Índice do topo da lista\n");
        printf("0 - Sair\n\n");

        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Valor inteiro que deseja adicionar: ");
                scanf("%d", &valorMain);
                empilhar(valorMain);
                break;
            case 2: {
                int valorDesempilhado = desempilhar();
                if (valorDesempilhado != -1) {
                    printf("O elemento desempilhado foi: %d\n", valorDesempilhado);
                }
                break;
            }
            case 3: {
                int valorTopo = topoDaPilha();
                if (valorTopo != -1) {
                    printf("O último item da pilha é: %d\n", valorTopo);
                }
                break;
            }
            case 4:
                imprimirPilha();
                break;
            case 5:
                printf("Pilha topo: %d\n", pilha.topo);
                break;
            case 0:
                continuar = 0;
                break;
            default:
                printf("Opção inválida. Digite novamente.\n");
                break;
        }

        printf("\nPressione Enter para continuar...");
        getchar();
        getchar(); // captura o Enter
    }

    printf("Encerrando programa...\n");

    return 0;
}