#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

struct Pilha {
    int itens[MAX_SIZE];
    int topo;
};

void inicializar(struct Pilha *p) { //reseta o topo da pilha para zero, faz com que a pilha inteira seja zerada e os dados posterior perdidos
    p->topo = -1; //também pode ser reescrito como (*p).topo = -1;

}

int vazia(struct Pilha *p) {
    return p->topo == -1;
}

void push(struct Pilha *p, int valor) {
    if (p->topo == MAX_SIZE - 1) {
        printf("Pilha está cheia\n");
    }else {
        p->topo++;
        p->itens[p->topo] = valor;
        printf("Dado %d adicionado à pilha.\n", valor);
    }
}

void imprimir(struct Pilha* p) {
    int i = 0;
    printf("Os dados da pilha são: ");
    for(i = 0; i <= p->topo; i++) {
        printf("%d,", p->itens[i]);
    }
}

void pop(struct Pilha *p) {
    int elemento_removido;

    if(p->topo == -1) {
        printf("Não foi possível remover porque a pilha está vazia");
    }else {
        elemento_removido = p->itens[p->topo];
        p->topo--;
        printf("Item %d removido\n", elemento_removido);
    }

}


int main () {
    int loop = 1, op=0, valorMain;
    struct Pilha p;
    inicializar(&p);

    while (loop) {
        system("clear");
        printf( 
            "-== Pilhas Sintaxe nova ==-\n\n"
            "1- Adicionar item a pilha\n"
            "2- Imprimir a pilha\n"
            "3- Remover último item da pilha\n"
            "4- Imprimir último item da pilha\n"
            "0- Sair\n\n"
            "Escolha: "
        );
        scanf("%d", &op);
        switch (op) {
            case(1):
                printf("Elemento a ser adicionado: ");
                scanf("%d", &valorMain);
                push(&p, valorMain);
                break;
            case(2):
                imprimir(&p);
                printf("\n");
                break;
            case(3):
                pop(&p);
                break;
            case(4):
                if(p.topo == -1) {
                    printf("A pilha está vazia, não existe nada a imprimir\n");
                }else {
                    printf("O último item da pilha é %d", p.itens[p.topo]);
                }
                break;
            case(0):
                loop = 0;
                break;
            default:
                printf("A opção informada não é valida\n");
                break;
        }

        printf("\nPressione Enter para continuar...");
        getchar();
        getchar();
    }
    printf("Au revoir...\n");
    return 0;
}