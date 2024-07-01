## 1 : Unidade 2

```c
#include <stdio.h>
#include <string.h>

#define tamanho 5

// Estrutura do Livro
struct tlivro {
    int codigo;
    char nome[50];
    char autor[50];
};

// Estrutura da Pilha
struct tpilha {
    struct tlivro dados[tamanho];
    int ini;
    int fim;
};

// Variável global da Pilha
struct tpilha pilha;

// Protótipos das Funções
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();

// Função principal
int main() {
    int opcao;

    // Inicializar a Pilha
    pilha.ini = 0;
    pilha.fim = 0;

    do {
        // Menu de opções
        printf("\n\nMenu de Pilha de Livros:\n");
        printf("1. Adicionar Livro\n");
        printf("2. Remover Livro\n");
        printf("3. Mostrar Pilha\n");
        printf("4. Sair\n");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                pilha_entrar();
                break;
            case 2:
                pilha_sair();
                break;
            case 3:
                pilha_mostrar();
                break;
            case 4:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

// Função para adicionar um livro à pilha
void pilha_entrar() {
    if (pilha.fim == tamanho) {
        printf("\nA pilha está cheia, impossível empilhar!\n\n");
        getchar(); // Limpar o buffer de entrada
        return;
    }

    printf("\nDigite o código do livro: ");
    scanf("%d", &pilha.dados[pilha.fim].codigo);
    printf("\nDigite o nome do livro: ");
    getchar(); // Limpar o buffer de entrada antes de ler a string
    fgets(pilha.dados[pilha.fim].nome, 50, stdin);
    pilha.dados[pilha.fim].nome[strcspn(pilha.dados[pilha.fim].nome, "\n")] = '\0'; // Remover o \n do final da string
    printf("\nDigite o nome do autor: ");
    fgets(pilha.dados[pilha.fim].autor, 50, stdin);
    pilha.dados[pilha.fim].autor[strcspn(pilha.dados[pilha.fim].autor, "\n")] = '\0'; // Remover o \n do final da string

    pilha.fim++;
}

// Função para remover um livro da pilha
void pilha_sair() {
    if (pilha.ini == pilha.fim) {
        printf("\nA pilha está vazia, impossível desempilhar!\n\n");
        getchar(); // Limpar o buffer de entrada
        return;
    }

    pilha.fim--;
    pilha.dados[pilha.fim].codigo = 0;
    pilha.dados[pilha.fim].nome[0] = '\0';
    pilha.dados[pilha.fim].autor[0] = '\0';
}

// Função para mostrar o conteúdo da pilha
void pilha_mostrar() {
    int i;
    printf("\nPilha de Livros:\n");
    if (pilha.ini == pilha.fim) {
        printf("Pilha vazia.\n");
    } else {
        for (i = pilha.ini; i < pilha.fim; i++) {
            printf("Código: %d, Nome: %s, Autor: %s\n", pilha.dados[i].codigo, pilha.dados[i].nome, pilha.dados[i].autor);
        }
    }
}
```

# 2 : Unidade 2
```c
#include <stdio.h>
#include <string.h>

// Constantes
#define tamanho 5

// Estrutura do Cliente
struct tcliente {
    char nome[50];
    char hora[6];
};

// Estrutura da Fila
struct tfila {
    struct tcliente dados[tamanho];
    int ini;
    int fim;
};

// Variável global da Fila
struct tfila fila;

// Funções para Fila
void fila_entrar();
void fila_sair();
void fila_mostrar();

// Função principal
int main() {
    int opcao;

    // Inicializar a Fila
    fila.ini = 0;
    fila.fim = 0;

    do {
        // Menu de opções
        printf("\n\nMenu de Fila de Clientes:\n");
        printf("1. Adicionar Cliente\n");
        printf("2. Atender Cliente\n");
        printf("3. Mostrar Fila\n");
        printf("4. Sair\n");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                fila_entrar();
                break;
            case 2:
                fila_sair();
                break;
            case 3:
                fila_mostrar();
                break;
            case 4:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

// Função para adicionar um cliente à fila
void fila_entrar() {
    if (fila.fim == tamanho) {
        printf("\nA fila está cheia, volte outro dia!\n\n");
        system("pause");
    } else {
        printf("\nDigite o nome do cliente que chegou: ");
        scanf("%s", fila.dados[fila.fim].nome);
        printf("\nDigite a hora da chegada do cliente: ");
        scanf("%s", fila.dados[fila.fim].hora);
        fila.fim++;
    }
}

// Função para atender o primeiro cliente da fila
void fila_sair() {
    if (fila.ini == fila.fim) {
        printf("\nFila vazia, mas logo aparece alguém!\n\n");
        system("pause");
    } else {
        printf("\nAtendedo o cliente: %s\n\n", fila.dados[fila.ini].nome);

        int i;
        for (i = 0; i < tamanho - 1; i++) {
            strcpy(fila.dados[i].nome, fila.dados[i + 1].nome);
            strcpy(fila.dados[i].hora, fila.dados[i + 1].hora);
        }
        strcpy(fila.dados[fila.fim].nome, "");
        strcpy(fila.dados[fila.fim].hora, "");
        fila.fim--;
    }
}

// Função para mostrar o conteúdo da fila
void fila_mostrar() {
    int i;
    printf("[ ");
    for (i = fila.ini; i < fila.fim; i++) {
        printf("Cliente %s ", fila.dados[i].nome);
        printf("chegou as %s horas \n", fila.dados[i].hora);
    }
    printf("]\n\n");
}
```