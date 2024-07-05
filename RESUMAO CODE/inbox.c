#include <stdio.h>
#include <stdlib.h>

/* struct semafaro {
    char cor[10];
    int id;
};

struct semafaro s1 = {"Vermelho", 1};
struct semafaro s2 = {"Amarelo", 2};
struct semafaro s3 = {"Verde", 3};
struct semafaro *ptr_s;

int main() {
    ptr_s = &s1;
    printf("%d - %s\n", ptr_s->id, ptr_s->cor);

    ptr_s++;
    printf("%d - %s\n", ptr_s->id, ptr_s->cor);

    ptr_s++;
    printf("%d - %s\n", ptr_s->id, ptr_s->cor);
    return 0;
}
 */

struct aluno {
    char nome[10];
    int idade;
};

struct aluno aluno1 = {"Samuel", 20};
struct aluno aluno2 = {"Sabrina", 21};
struct aluno aluno3 = {"Joao", 23};
struct aluno aluno4 = {"Lucas", 18};
struct aluno *andarilho; // Ponteiro para aluno

int main() {
    andarilho = &aluno1; // Inicializa o ponteiro para apontar para aluno1

    printf("Meu nome é %s, tenho %d anos\n", andarilho->nome, andarilho->idade);
    andarilho++; // Avança para o próximo aluno
    printf("Meu nome é %s, tenho %d anos\n", andarilho->nome, andarilho->idade);
    andarilho++; // Avança para o próximo aluno
    printf("Meu nome é %s, tenho %d anos\n", andarilho->nome, andarilho->idade);
    andarilho++; // Avança para o próximo aluno
    printf("Meu nome é %s, tenho %d anos\n", andarilho->nome, andarilho->idade);


    return 0;
}


//funciona, mais tem um limite de 2 tipo de dados no struct