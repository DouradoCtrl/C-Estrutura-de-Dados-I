#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 100

struct Pilha {
    char itens[MAX_SIZE];
    int topo;
};

void inicializar(struct Pilha *p) {
    p->topo = -1; //p->topo ou (*p).topo
}

int vazia(struct Pilha *p) {
    return p->topo == -1;
}

void push(struct Pilha *p, char item) {
    if (p->topo == MAX_SIZE - 1) {
        printf("Erro: Pilha cheia. Não é possível adicionar o elemento '%c'.\n", item);
    } else {
        p->topo++;
        p->itens[p->topo] = item;
    }
}

char pop(struct Pilha *p) {
    char letra;
    if (p->topo == -1) { 
        printf("Erro: Pilha vazia. Não é possível remover um elemento.\n");
        return '\0';
    } else{
        letra = p->itens[p->topo];
        p->topo--;
        
        return letra;
    }
}

char topo(struct Pilha *p) {
    char recebe;
    if (vazia(p)) { //vazia(p) ou p->topo == -1
        return '\0';
    } else {
        recebe = p->itens[p->topo];
        return recebe;
    }
}

void limpar(struct Pilha *p) {
    p->topo = -1;
}

void imprimir(struct Pilha *p) {
    int i = 0;
    printf("Os dados da pilha são: ");
    for(i = 0; i <= p->topo; i++) {
        printf("%c,", p->itens[i]);
    }
}

int main() {
    int repetidor = 1;
    setlocale(LC_ALL, "");
    struct Pilha p;
    inicializar(&p);

    while (repetidor == 1) {
        system("clear");
        printf(
            "--== ATIVIDADE DE PILHA [MAPA] ==--\n"
            "---==== ESTRUTURA DE DADOS ====---\n\n"
            "1 - Adicionar palavra a pilha\n"
            "2 - Desempilhar a palavra\n"
            "3 = Limpar toda a pilha\n"
            "4 = Exibir o topo da pilha\n"
            "5 = Exibir toda a pilha\n"
            "6 = Remover o topo da pilha\n"
            "0 = SAIR\n"
            );

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
                int indice = 0;
                while (!vazia(&p)) {
                    palavra[indice] = pop(&p);
                    indice++;
                }
                palavra[indice] = '\0';

                if (indice > 0) {
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
                char top = topo(&p);
                if (top == '\0') {
                    printf("\nPilha vazia. Nenhum elemento para mostrar.\n");
                } else {
                    imprimir(&p);
                    printf("\n");
                }

                break;
            }
            case 6: {
                char palavra, indice;
                palavra = pop(&p);
                printf("\nTopo desempilhado: '%c'\n", palavra);
                
                break;
            }
            case 0: {
                repetidor = 0;
                
                break;
            }
            default: {
                printf("\nOpção inválida. Digite 1, 2, 3, 4, 5, 6 ou 0.\n");
            }
            
        }
        printf("\nPressione Enter para continuar...");
        getchar();
        getchar();
    }

    printf("Programa encerrado, até mais !!\n");
    return 0;
}

