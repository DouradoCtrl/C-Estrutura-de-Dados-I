# include <stdlib.h>
# include <stdio.h>

#define tamanho 10

int main() {
    int pilha[tamanho]; // Array para armazenar os elementos da pilha
    int indice = -1; // Índice do topo da pilha

    int escolha, valor;

    // Código para operações na pilha
    do {
        system("clear");
        printf("\nEscolha uma opção:\n");
        printf("1 - Mostrar último item\n");
        printf("2 - Adicionar item\n");
        printf("3 - Remover último item\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if (indice == -1) {
                    printf("Erro: pilha vazia\n");
                } else {
                    printf("Último elemento da pilha: %d\n", pilha[indice]);
                }
                break;
            case 2:
                if (indice == tamanho - 1) {
                    printf("Erro: pilha cheia\n");
                } else {
                    printf("Digite o valor a ser adicionado: ");
                    scanf("%d", &valor);
                    pilha[indice = indice - 1] = valor;
                }
                break;
            case 3:
                if (indice == -1) {
                    printf("Erro: pilha vazia\n");
                } else {
                    printf("Item removido: %d\n", pilha[indice = indice -1]);
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
        printf("Pressione \"enter\" para continuar, lembrando que o resultado impresso será apagado...");
        getchar(); // Aguarda a entrada de uma tecla antes de limpar a tela
        getchar(); // Aguarda a entrada de uma tecla antes de limpar a tela
    } while (escolha != 0);

    return 0;
}



