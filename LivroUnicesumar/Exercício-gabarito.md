## Unidade 1 - Ponteiros

### 1. Faça um pequeno programa para testar seus conhecimentos sobre ponteiros e alocação dinâmica na memória.

a) Defina um ponteiro do tipo inteiro.  
b) Faça alocação dinâmica para o ponteiro recém-criado.  
c) Preencha a memória com o valor 42.  
d) Imprima o endereço do ponteiro na memória e o valor contido nele.  

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    ptr = (int *) malloc(sizeof(int));
    *ptr = 42;
    printf("Endereco: %p\nValor: %d\n\n", ptr, *ptr);
    system("Pause");
    return 0;
}
```

### 2. Uma famosa fábrica de semáforos está testando um novo protótipo, menor, mais barato e eficiente. Foi solicitado à equipe de TI um programa em linguagem C para fazer o teste do novo hardware. O semáforo tem três objetos, cada um contém um atributo cor e outro id. Devido às limitações de memória e processamento, é necessária a criação de um ponteiro que vai percorrendo a memória e imprimindo o valor na tela.

a) Crie uma estrutura que tenha dois atributos: cor (cadeia de caracteres) e id
(inteiro).  
b) Crie três variáveis com o tipo definido no item a.  
c) Crie um ponteiro do mesmo tipo. 

d) Inicialize as estruturas da seguinte forma:  
• cor vermelha, id 1.  
• cor amarela, id 2.  
• cor verde, id 3.  

e) Inicialize o ponteiro apontando para a primeira variável criada.   

f ) Por meio de operações aritméticas com ponteiros, percorra a memória e imprima o valor de cada uma das variáveis criadas nesse programa.  

```c
#include <stdio.h>
#include <stdlib.h>

struct semafaro {
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

    system("Pause");
    return 0;
}
```

### 3. Qual a diferença entre uma variável do tipo inteira de um ponteiro do tipo inteiro?
Uma variável do tipo inteira aponta pra um número inteiro na memória, já um ponteiro do tipo inteiro aponta para o endereço de um inteiro na memória, seja o de uma variável estática ou dinâmica.

### 4. Por que devemos preencher um ponteiro apenas com o endereço de uma variável ou por alocação dinâmica usando funções como malloc?
Porque se tentarmos alocar indiscriminadamente um endereço qualquer a um ponteiro, corremos o risco de estar manipulando uma área da memória que está sendo utilizada por outro programa ou até mesmo pelo sistema operacional, o que pode causar instabilidade no computador.

### 5. Crie um programa que leia uma variável e crie dois vetores dinâmicos, um com o tamanho lido e outro com o dobro desse tamanho. Preencha esses vetores respectivamente com potências de 2 e potências de 3.
a) Crie uma variável inteira e dois ponteiros do tipo inteiro.  
b) Pergunte ao usuário o tamanho do vetor dinâmico e leia esse valor na variável
inteira.  
c) Aloque dinamicamente os dois vetores usando a função malloc.  
d) Faça um laço de repetição para preencher o primeiro vetor com potências
de 2.  
e) Faça um segundo laço de repetição para preencher o outro vetor com potências de 3.  
f ) Não se esqueça de usar a biblioteca math.h para poder usar o cálculo de potência (pow).

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tamanho;
int *vetor1, *vetor2;

int main() {
    int i;

    printf("Escolha o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor1 = (int *) malloc(sizeof(int) * tamanho);
    vetor2 = (int *) malloc(sizeof(int) * (tamanho * 2));

    printf("\nVetor1: \n");
    for (i = 0; i < tamanho; i++) {
        vetor1[i] = pow(2, i);
        printf("Posicao %d: %d\n", i, vetor1[i]);
    }

    printf("\nVetor2: \n");
    for (i = 0; i < tamanho * 2; i++) {
        vetor2[i] = pow(3, i);
        printf("Posicao %d: %d\n", i, vetor2[i]);
    }

    system("Pause");
    return 0;
}
```

### Observações:

* Este código demonstra conceitos básicos de ponteiros e alocação dinâmica em C.
* Em cenários reais, a gestão de memória e o tratamento de erros devem ser mais robustos.
* O código pode ser adaptado para diferentes tipos de dados e tarefas.

### Lembre-se:

* A prática é fundamental para dominar os conceitos de ponteiros e alocação dinâmica.
* Existem diversos recursos online e tutoriais disponíveis para auxiliar no aprendizado.
* Utilize ferramentas de depuração para identificar e corrigir erros no código.

## Unidade 2 - Pilhas e Filas

### 1. Quando um livro é devolvido na Biblioteca do Unicesumar, o funcionário responsável pelo recebimento coloca o livro em cima de uma pilha de livros na mesa ao lado da recepção. O auxiliar de bibliotecário pega o livro do topo da pilha, verifica o seu código e leva-o para o seu devido local no acervo. No atual sistema de informação, é possível verificar se o livro está disponível ou se está emprestado. Entretanto, o livro que acabou de ser devolvido ainda não se encontra na prateleira, pois existe um intervalo de tempo entre a devolução do mesmo e o momento em que ele é guardado na estante. A sugestão do departamento de TI é de criar um programa que faça o controle na pilha, assim, pode-se verificar se o livro ainda não foi guardado e qual a sua posição dentro da pilha de livros que aguardam ao lado da recepção.

a) Crie uma estrutura para a pilha de livros. Lembre-se de que ela tem que ter um vetor para armazenar os dados (código, nome do livro e autor) e dois números inteiros, um para controlar o início e outro o final da pilha.  
b) Defina a variável que será um vetor do tipo pilha de livros.  
c) Faça uma função de empilhamento, lembrando-se de verificar se a pilha atingiu o tamanho máximo de livros (a mesa não aguenta muito peso).   
d) Crie uma função para desempilhamento de livros. Não se esqueça de que é necessário verificar se ainda existem livros para ser guardados.   
e) Elabore uma função que apresente na tela a lista de todos os livros que se encontram empilhados ao lado da recepção.  

```c
#include <string.h>

// Constantes
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

//Variáveis globais
tpilha pilha;

//Adicionar um elemento no final da Pilha
void pilha_entrar(){
    if (pilha.fim == tamanho) {
        printf("\nA pilha está cheia, impossível empilhar!\n\n");
        system("pause");
    }
    else {
        printf("\nDigite o código do livro: ");
        scanf("%d", &pilha.dados[pilha.fim].codigo);
        printf("\nDigite o nome do livro: ");
        scanf("%s", pilha.dados[pilha.fim].nome);
        printf("\nDigite o nome do autor: ");
        scanf("%s", pilha.dados[pilha.fim].autor);
        pilha.fim++;
    }
}

//Retirar o último elemento da Pilha
void pilha_sair() {
    if (pilha.ini == pilha.fim) {
        printf("\nA pilha está vazia, impossível desempilhar!\n\n");
        system("pause");
    }
    else {
        pilha.dados[pilha.fim-1].codigo = 0;
        strcpy(pilha.dados[pilha.fim-1].nome, "");
        strcpy(pilha.dados[pilha.fim-1].autor, "");
        pilha.fim--;
    }
}

//Mostrar o conteúdo da Pilha
void pilha_mostrar() {
    int i;
    printf("[ ");
    for (i = 0; i < tamanho; i++) {
        
    }
    printf("]\n\n");
}
```

### 2. Uma agência bancária quer inovar seu atendimento, criando mais conforto para seus clientes. Para isso, foram colocadas diversas cadeiras na recepção do banco. Quando um cliente chega, o atendente lança no computador o seu nome e o horário que chegou. Assim que um caixa fica livre, a recepcionista olha no sistema e chama o primeiro cliente da fila. Dessa forma, é possível que os clientes esperem confortavelmente sentados pelo seu atendimento, não importando o local onde se encontrem dentro da agência bancária.

a) Faça uma estrutura para o controle da fila. Você precisa guardar o nome e a hora que o cliente chegou. Use um vetor para armazenar os dados e dois números inteiros, um para controlar o início e outro o final da fila.  
b) Defina a variável que será um vetor do tipo fila de clientes.  
c) Crie uma função enfileirar, lembrando que é preciso verificar se há espaço na fila (o número de cadeiras na recepção é limitado).  
d) Elabore a função desenfileirar cliente, não se esqueça de que é necessário verificar se ainda existem clientes para serem atendidos.  
e) Faça uma função que apresente na tela a lista de todos os clientes que estão aguardando atendimento na recepção.

```c
#include <string.h>
//Constantes
#define tamanho 5
//Estrutura do Cliente
struct tcliente {
    char nome[50];
    char hora[6];
};
//Estrutura da Fila
    struct tfila {
    struct tcliente dados[tamanho];
    int ini;
    int fim;
};

//Variáveis globais
struct tfila fila;

//Adicionar um elemento no final da Fila
void fila_entrar(){
    if (fila.fim == tamanho) {
        printf("\nA fila está cheia, volte outro dia!\n\n");
        system("pause");
    }
    else {
        printf("\nDigite o nome do cliente que chegou: ");
        scanf("%s", fila.dados[fila.fim].nome);
        printf("\nDigite a hora da chegada do cliente: ");
        scanf("%s", fila.dados[fila.fim].hora);
        fila.fim++;
    }
}

//Retirar o primeiro elemento da Fila
void fila_sair() {
    if (fila.ini == fila.fim) {
        printf("\nFila vazia, mas logo aparece alguém!\n\n");
        system("pause");
    }
    else {
        int i;
        for (i = 0; i < tamanho; i++) {
            strcpy(fila.dados[i].nome, fila.dados[i+1].nome);
            strcpy(fila.dados[i].hora, fila.dados[i+1].hora);
        }
        strcpy(fila.dados[fila.fim].nome, "");
        strcpy(fila.dados[fila.fim].hora, "");
        fila.fim--;
    }
}

//Mostrar o conteúdo da Fila
void fila_mostrar() {
    int i;
    printf("[ ");
    for (i = 0; i < tamanho; i++) {
        printf("Cliente %s ", fila.dados[i].nome);
        printf("chegou as %s horas \n", fila.dados[i].hora);
    }
    printf("]\n\n");
}
```

### Observações:

- Este código demonstra conceitos básicos de pilhas e filas em C.
- Em cenários reais, a gestão de dados e o tratamento de erros devem ser mais robustos.
- O código pode ser adaptado para diferentes tipos de dados e tarefas.

### Lembre-se:

- A prática é fundamental para dominar os conceitos de pilhas e filas.
- Existem diversos recursos online e tutoriais disponíveis para auxiliar no aprendizado.
- Utilize ferramentas de depuração para identificar e corrigir erros no código.

## Unidade 3 - Listas dinâmicas

### 1. É possível criar uma lista de forma estática usando um vetor?
Sim, a lista pode ser implementada de forma estática num vetor ou dinamicamente na memória. O que caracteriza a lista dinâmica é o fato de seus nós possuírem o endereço do próximo elemento, permitindo assim a sua organização independente do índice do vetor.

### 2. Crie a estrutura de um nó para uma lista encadeada.
```c
struct no {
    int dado;
    struct no *proximo;
};
```

### 3. Crie a estrutura de um nó para uma lista duplamente encadeada.
```c
struct no {
    int dado;
    struct no *anterior;
    struct no *proximo;
};
```

### 4. Qual a vantagem de uma lista duplamente encadeada em relação a uma lista simples?
Na lista simples, os nós possuem apenas o endereço do próximo elemento. Dessa forma, podemos navegar do primeiro ao último nó em um único sentido. Na lista duplamente encadeada, os nós possuem o endereço do elemento anterior
e do elemento posterior. Dessa forma, podemos fazer a navegação em ambos os sentidos, tanto do início para o final como do final para o início.

### 5. Como sabemos qual é o nó inicial de uma lista simples?
Só é possível saber onde começa uma lista dinâmica se tivermos uma variável do tipo ponteiro que aponte para o início da lista.
### 6. Como sabemos qual é o nó final de uma lista simples?
Sabemos se um nó é o último de uma lista se o atributo que aponta para o próximo elemento estiver com o valor nulo (null).

### 7. Se o nó de uma lista duplamente encadeada possui dois ponteiros, um para o próximo elemento e um para o anterior, qual informação está contida nesses ponteiros do primeiro nó da lista?
O primeiro nó de uma lista duplamente encadeada tem dois ponteiros, assim como todos os demais nós. O ponteiro criado para apontar para o elemento anterior estará apontando para nulo, já que como é o primeiro nó, não há um nó anterior. O outro ponteiro estará apontando para o próximo nó. Se por acaso só haja um nó nessa lista duplamente encadeada, ambos os ponteiros estarão apontando para nulo.

### Observações:

- Listas dinâmicas permitem um uso mais eficiente da memória, ajustando-se conforme a necessidade.
- Estruturas como listas encadeadas e duplamente encadeadas são fundamentais para a compreensão de algoritmos mais complexos.
- Praticar a implementação dessas listas ajuda a entender melhor a manipulação de ponteiros e a alocação dinâmica.

### Lembre-se:

- A prática é essencial para dominar os conceitos de listas dinâmicas.
- Existem muitos recursos online e tutoriais disponíveis para auxiliar no aprendizado.
- Utilize ferramentas de depuração para identificar e corrigir erros no código.
- Compreender listas dinâmicas é um passo importante para se aprofundar em estruturas de dados mais avançadas.
- Aprofundar-se em listas dinâmicas melhora a eficiência na resolução de problemas e no desenvolvimento de software.


## Unidade 4 - Grafos

Dados os seguintes conjuntos G = (V,E):

a) V= {a}, E= {∅}  
b) V= {a,b}, E= {(a,b)}  
c) V= {a,b}, E= {<b,a>}  
d) V= {a,b,c}, E= {(a,b), (b,c)}  
e) V= {a,b,c}, E= {<a,b>, <c,b>, <a,c>, <c,a>}  
f ) V= {a,b,c,d}, E= {<a,b>, <d,a>}  
g) V= {a,b,c,d}, E= {(a,b), (a,c), (a,d)}  

### 1. Desenhe a representação em Grafo de cada conjunto G = (V,E).
a) V= {a}, E= {∅}  
![alt text](assets/images/image-1.png)

b) V= {a,b}, E= {(a,b)}  
![alt text](assets/images/image-2.png)

c) V= {a,b}, E= {<b,a>}  
![alt text](assets/images/image-3.png)

d) V= {a,b,c}, E= {(a,b), (b,c)}  
![alt text](assets/images/image-4.png)

e) V= {a,b,c}, E= {<a,b>, <c,b>, <a,c>, <c,a>}  
![alt text](assets/images/image-5.png)

f ) V= {a,b,c,d}, E= {<a,b>, <d,a>}  
![alt text](assets/images/image-6.png)

g) V= {a,b,c,d}, E= {(a,b), (a,c), (a,d)}  
![alt text](assets/images/image-7.png)

### 2. Classifique cada um dos conjuntos G = (V,E) como sendo orientado, não orientado, conexo e desconexo.
a) V= {a}, E= {∅}  
Conexo, não orientado. Também conhecido como grafo trivial por conter
apenas um vértice e nenhuma aresta.

b) V= {a,b}, E= {(a,b)}  
Conexo, não orientado.

c) V= {a,b}, E= {<b,a>}  
Conexo, orientado.

d) V= {a,b,c}, E= {(a,b), (b,c)}  
Conexo, não orientado.

e) V= {a,b,c}, E= {<a,b>, <c,b>, <a,c>, <c,a>}  
Conexo, orientado.

f ) V= {a,b,c,d}, E= {<a,b>, <d,a>}  
Desconexo, orientado.

g) V= {a,b,c,d}, E= {(a,b), (a,c), (a,d)}  
Conexo, não orientado.

### 3. Crie a matriz de adjacência para cada conjunto G = (V,E).
a) V= {a}, E= {∅}  
M= {∅}

b) V= {a,b}, E= {(a,b)}  
|   | a | b |
|---|---|---|
| a | 0 | 1 |
| b | 1 | 0 |

c) V= {a,b}, E= {<b,a>}  
|   | a | b |
|---|---|---|
| a | 0 | 1 |
| b | 0 | 0 |

d) V= {a,b,c}, E= {(a,b), (b,c)}  
|   | a | b | c |
|---|---|---|---|
| a | 0 | 1 | 0 |
| b | 1 | 0 | 1 |
| c | 0 | 1 | 0 |

e) V= {a,b,c}, E= {<a,b>, <c,b>, <a,c>, <c,a>}  
|   | a | b | c |
|---|---|---|---|
| a | 0 | 1 | 1 |
| b | 0 | 0 | 0 |
| c | 1 | 1 | 0 |

f ) V= {a,b,c,d}, E= {<a,b>, <d,a>}  
|   | a | b | c | d |
|---|---|---|---|---|
| a | 0 | 1 | 0 | 0 |
| b | 0 | 0 | 0 | 0 |
| c | 0 | 0 | 0 | 0 |
| d | 1 | 0 | 0 | 0 |


g) V= {a,b,c,d}, E= {(a,b), (a,c), (a,d)}  
|   | a | b | c | d |
|---|---|---|---|---|
| a | 0 | 1 | 1 | 1 |
| b | 1 | 0 | 0 | 0 |
| c | 1 | 0 | 0 | 0 |
| d | 1 | 0 | 0 | 0 |

### Observações:

- A compreensão de grafos é crucial em áreas como ciência da computação, redes, e matemática aplicada.
- Grafos são representações poderosas para modelar problemas complexos de forma visual e estruturada.

### Lembre-se:

- A prática na construção e análise de grafos fortalece habilidades analíticas e de resolução de problemas.
- Recursos como software especializado e bibliotecas podem auxiliar na visualização e manipulação de grafos.
- Entender as propriedades dos grafos ajuda na aplicação de algoritmos para solução de problemas do mundo real.

## Unidade 5 - Busca em Grafos

### 1. Qual é a principal diferença entre a Busca em Largura e a Busca em Profundidade?
A busca em largura visita primeiramente os vértices mais próximos antes de se aprofundar no grafo. Já a busca em profundidade segue um caminho até o final antes de optar por uma nova ramificação.
Isso se dá pela forma como os vértices visitados são armazenados. A busca em xprofundidade armazena os dados numa pilha e a busca em largura, em uma fila.

### 2. Em que caso a Busca em Largura é mais eficiente que a Busca em Profundidade?
A busca em largura é mais eficiente quando sabemos que o valor procurado está nas proximidades da região de pesquisa. A busca em profundidade pode obter um melhor resultado se o resultado da pesquisa estiver mais distante.

### 3. O que diferencia o algoritmo de Dijkstra e a busca em largura?
O algoritmo de Dijkstra leva em consideração uma matriz de valores em que estão armazenados os pesos das arestas. Durante a investigação dos vizinhos de um nó, a técnica prioriza adicionar somente o vértice mais próximo, ou seja,
aquele que tem a aresta com o menor custo.

### 4. Digite no seu computador o Programa 5.4. Entre com o Grafo (ou parte dele) a seguir e faça simulações de busca de caminho mais curto entre duas cidades.

![alt text](assets/images/image.png)

### Observações:

- Compreender as diferenças entre algoritmos de busca é fundamental para escolher o mais adequado para um problema específico.
- A aplicação de algoritmos como Dijkstra e busca em largura é comum em sistemas de navegação, redes e otimização.
- A visualização e simulação de grafos auxiliam na compreensão prática do comportamento desses algoritmos.

### Lembre-se:

- A eficiência na escolha do algoritmo de busca depende das características do problema e da estrutura do grafo.
- Pratique a implementação e simulação de algoritmos de busca para consolidar o entendimento teórico.
- Utilize ferramentas de visualização de grafos para acompanhar o processo de busca e otimização.


