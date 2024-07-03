#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int dado;
    struct NO *prox;
}NO;

typedef struct PILHA {
    NO *topo;
}PILHA;

PILHA *p;

int empilhar (int item){
    NO *ponteiro = (NO *)malloc(sizeof(NO));
    ponteiro->dado = item;
    ponteiro->prox = p->topo;
    p->topo = ponteiro;

    return ponteiro->dado;
}

//PASSO A PASSO EMPILHAMENTO
/* 
    1 - CRIAR NOVO NÓ (ALOCAR MEMÓRIA)
    2 - PREENCHER O VALOR NO PONTEIRO->DADO
    3 - FAZER O PROX DO PONTEIRO CRIADO APONTAR PARA O TOPO DA PILHA
    4 - FAZER O TOPO DA PILHA APONTAR PARA O NOVO NÓ

    EMPILHADO


 */

int desempilhar() {
    NO *ponteiro;
    ponteiro = p->topo;

    if(ponteiro == NULL) {
        printf("Nenhum elemento a ser a desempilhado...\n");
    }else {
        p->topo = ponteiro->prox;
        ponteiro->prox == NULL;
        return ponteiro->dado;

        free(ponteiro);
    }
}

//PASSO A PASSO DESEMPILHAMENTO
/* 
    1 - VERIFICA ESSA LISTA NÁO ESTA VAZIA
    2 - FAÇA O PONTEIRO APONTAR PARA O TOPO DA PILHA OU SEJA ELE MESMO
    3 - ARMAZENE O DADO QUE VAI SER DESEMPILHADO PARA RETORNAR AO USUARIO
    4 - FAÇA O TOPO APONTAR PARA O PROX DO PONTEIRO
    5 - ATRIBUA NULL PARA O PROX DO PONTEIRO, ISSO FARÁ COM QUE ELE SEJA REMOVIDO DA PILHA
    6 - LIBERE A MEMÓRIA

    EMPILHADO


 */

void listarPilha () {
    NO *ponteiro;
    ponteiro = p->topo;
    if(ponteiro == NULL) {
        printf("Lista está vazia...\n");
    }else {
        printf("Os elementos da sua lista são: ");
        while(ponteiro != NULL) {
            printf("%d,", ponteiro->dado);
            ponteiro = ponteiro->prox;
        }
        printf("\n");
    }
}

//PASSO PARA IMPRIMIR A PILHA
/* 
    1 - FAÇA O PONTEIRO APONTAR PARA O TOPO, OU SEJA, ELE MESMO
    2 - VERIFIQUE SE A PILHA NAO TA VAZIA
    3 - COLOQUE EM LACO DE REPETIÇÃO PARA PRINTAR O PONTEIRO->DADO ENQUANTO FOR DIFERENTE DE NULL
    4 - A CADA PRINT FAÇA O PONTEIRO APONTAR PARA O PROX, DESSA FORMA ELE NAVEGARÁ ENTRE OS NÓS E ACABAR

 */



int main () {
    p = (PILHA *) malloc (sizeof(PILHA));
    int teste;

    teste = empilhar(4);
    printf("O item empilhado foi: %d\n", teste);
    teste = empilhar(3);
    printf("O item empilhado foi: %d\n", teste);
    teste = empilhar(1);
    printf("O item empilhado foi: %d\n", teste);

    listarPilha();

    teste = desempilhar();
    printf("O item desempilhado foi: %d\n", teste);

    listarPilha();

    return 0;

}

