#include <stdio.h>

typedef struct arvore{
    char letra;
    struct arvore *no;
}Arvore;

typedef struct lista{
    struct lista *prox;
}Lista;