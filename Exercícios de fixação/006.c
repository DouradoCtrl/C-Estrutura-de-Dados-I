#include <stdio.h>
#include <stdlib.h>

//Implemente uma pilha em C usando uma lista encadeada. Forneça funções para empilhar, desempilhar e imprimir os elementos da pilha.
#define size 5

struct tipo_pilha {
    int dados[size];
    int topo;
    int ini;
};

struct tipo_pilha pilha;//declarei como tipo global para que possa ser acessado de qualquer lugar do código

void Empilhar (int valor) {
    if (pilha.topo == size) {
        printf("A pilha está cheia, não foi possível adiconar um novo elemento\n");
    }else {
        pilha.dados[pilha.topo] = valor;
        pilha.topo = pilha.topo + 1;

        printf("Elemento %d adicionado a pilha.\n", valor); 
    }
    
}

int Desempilhar () {
    int elemento_desempilhado;
    if(pilha.topo == pilha.ini) {
        printf("Não foi possível concluir a operação pois a pilha está vazia\n");
    }else {
        pilha.topo = pilha.topo - 1;
        elemento_desempilhado = pilha.dados[pilha.topo];
        

        return elemento_desempilhado;
    }
  
}

void Imprimir_pilha () {
    int i;
    printf("Os valores da pilha são: ");
    for (i = pilha.ini; i < pilha.topo; i++) {
        printf("%d,", pilha.dados[i]);
    }
   
}

void TopoDaLista() {
    if (pilha.topo == pilha.ini) {
        printf("A pilha está vazia, não existe último elemento");
    }else {
        printf("O último item da pilha é: %d", pilha.dados[pilha.topo - 1]);
    }
}

int main (void) {
    int op = 0, continuar = 1, valorMain;


    while(continuar == 1) {
        system("clear");
        printf("Voce pode adicionar até 5 números inteiros...\n\n"
               "-== PILHA OPCOES ==--\n"
               "1 - Adicionar item à pilha\n"
               "2 - Remover item do topo da pilha\n"
               "3 - Ver o último item da pilha\n"
               "4 - Listar a pilha inteira\n"
               "5 - Indice do topo da lista\n\n"
               "Escolha: ");

        scanf("%d", &op);
        
        switch(op) {
            case 1:
                printf("Valor inteiro que deseja adicionar: ");
                scanf("%d", &valorMain);
                Empilhar(valorMain);
                break;
            case 2:
                valorMain = Desempilhar();
                printf("O elemento desempilhado foi: %d\n", valorMain);
                break;
            case 3:
                TopoDaLista();
                break;
            case 4:
                Imprimir_pilha();
                break;
            case 5:
                printf("\n\nPilha topo: %d\n\n", pilha.topo);
                break;
            default:
                printf("Ops... O senhor digitou uma opção inválida");
                break;
        }
        //desenvolvimento switch case ou if and if else;

        printf("\nDeseja continuar ? 1 = Sim e 0 = Nao: ");
        scanf("%d", &continuar);
        getchar();
    }
    
    
    printf("Encerrando programa...\n");
            
    return 0;
}

























//CONSULTAR
/*
struct tipo_pilha {
    int dados[3];
    int ini;
    int topo;
};

struct tipo_pilha pilha;

//push
void empilha (int elemento) {
    if(pilha.topo == 3) {
        printf("Pilha está cheia, elemento que tentou adicionar: %d\n", elemento);
    }else {
        pilha.dados[pilha.topo] = elemento; //vai colocar no indice pilha todo o elemento
        pilha.topo = pilha.topo + 1;

        printf("O elemento adicionado foi: %d\n", elemento);
    }
}

//pop
int desempilhar ( ) {
    int elemento;
    if (pilha.topo == pilha.ini) {
        printf("A pilha está vazia\n");

    }else {
        pilha.topo = pilha.topo - 1;
        elemento = pilha.dados[pilha.topo];

        return elemento;
    }
}

int main (void) {
    int desempilhado = 0;
    empilha(12);
    empilha(13);
    empilha(14);
    empilha(30); //pilha cheia

    desempilhado = desempilhar();
    /* desempilhado = 0; */
    

    /* if (desempilhado != 0) {
        printf("O elemento desempilhado foi: %d\n", desempilhado);
    }

    
    return 0;
} */