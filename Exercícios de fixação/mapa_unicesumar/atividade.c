#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Pilha {
    char itens[MAX_SIZE];
    int topo;
};

void inicializar(struct Pilha *p) {
    p->topo = -1;
}

int vazia(struct Pilha *p) {
    return p->topo == -1;
}

void push(struct Pilha *p, char item) {

    if (p->topo == MAX_SIZE) {
        printf("Não foi possível adicionar, pilha está cheia !\n");
    }else {
        p->topo++;
        p->itens[p->topo] = item;

    }
}


char pop(struct Pilha *p) {
    p->topo--;
}

char topo(struct Pilha *p) {
   
}

void limpar(struct Pilha *p) {
    
}

void imprimir(struct Pilha *p) {
    int i = 0;
    printf("Os dados da pilha são: ");
    for(i = 0; i <= p->topo; i++) {
        printf("%c,", p->itens[i]);
    }
}


int main (){
    struct Pilha p;
    inicializar(&p);

    while (1) {\
        system("clear");
        printf("\nDigite 1 para adicionar uma palavra à pilha\n");
        printf("Digite 2 para desempilhar a palavra\n");
        printf("Digite 3 para limpar a pilha\n");
        printf("Digite 4 para exibir o topo da pilha\n");
        printf("Digite 5 para imprimir a pilha\n");
        printf("Digite 0 para sair\n");

        int opcao;
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                char palavra[MAX_SIZE];
                printf("\nDigite a palavra a ser adicionada: ");
                scanf("%s", palavra);
                for (int i = 0; i < strlen(palavra); i++) {
                    push(&p, palavra[i]);
                }
                printf("\nPalavra '%s' adicionada à pilha.\n", palavra);
                break;
            }
            case 2: {
                char palavra[MAX_SIZE];
                while (!vazia(&p)) {
                    pop(&p);
                }
                
                if (i>0) {
                    printf("\nPalavra desempilhada: '%s'\n", palavra);
                } else {
                    printf("\nPilha vazia. Nenhum elemento para mostrar.\n");
                }
                break;


            }
            case 3: {
                limpar(&p);
                printf("\nPilha limpa.\n");
                break;
            }
            case 4: {
                char top = topo(&p);
                if (top == '\0') {
                    printf("\nPilha vazia. Nenhum elemento para mostrar.\n");
                } else {
                    printf("\nElemento no topo da pilha: %c\n", top);
                }
                break;
            }
            case 5: {
                imprimir(&p);

                break;
            }
            case 0: {
                return 0;
            }
            default: {
                printf("\nOpção inválida. Digite 1, 2, 3, 4, 5 ou 0.\n");
            }
        }

        printf("\nPressione Enter para continuar...");
        getchar();
        getchar();
    }

    return 0;
}