# include <stdio.h>

// Crie uma função em C chamada trocaValores que aceita dois ponteiros para inteiros como argumentos e troca os valores das variáveis apontadas pelos ponteiros.

int main (void) {
    int n1 = 20, n2 = 30;

    printf("Valores antes da troca\n A: %d, B: %d\n", n1, n2);

    int TrocaDeValores(int *ptr1, int *ptr2);
    TrocaDeValores(&n1, &n2);

    printf("Valores depois da troca\n A: %d, B: %d\n", n1, n2);


    return 0;
}

int TrocaDeValores (int *ptr1, int *ptr2) {
    int qualquer;
    qualquer = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = qualquer;
}

//OBS: Foi repassado a função os enderecos de n1 e n2, pelo código o retorno foi toda a operação dentro da função.