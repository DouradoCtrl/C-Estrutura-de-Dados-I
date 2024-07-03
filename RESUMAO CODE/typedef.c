typedef struct {
    int dado;
    struct NO *prox;

}NO;

//ou 

typedef struct NO {
    int dados;
    struct NO *prox;
}NO;

//A segunda é mais correta porque eu uso referencio a struct em si mesma;