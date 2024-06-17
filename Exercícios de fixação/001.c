# include <stdio.h>
# include <stdlib.h>

//Escreva um programa em C que declare uma variável inteira num, atribua um valor a ela e, em seguida, imprima o valor e o endereço de num usando ponteiros.


int main () {
    int num = 10, *ptr;
    ptr = &num;

    printf("O endereco de num é %p\n", ptr );
    printf("O endereco o valor de num é %d\n", *ptr);

    return 0;
}