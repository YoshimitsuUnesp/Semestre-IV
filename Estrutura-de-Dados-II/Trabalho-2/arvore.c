#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

Arvore *criaArvore()
{
    Arvore *novo = malloc(sizeof(Arvore));
    novo->caracter = NULL;
    novo->dir = NULL;
    novo->esq = NULL;
    novo->freq = 0;
    return novo;
}