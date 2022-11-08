#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

Arvore *criaArvore()
{
    Arvore *novo = malloc(sizeof(Arvore));
    novo->caracter = '\0';
    novo->dir = NULL;
    novo->esq = NULL;
    novo->freq = 0;

    return novo;
}

void comprimeArquivo(){
    FILE *arq_txt = fopen("arquivo.txt", "a");
    FILE *arq_huf = fopen("arquivo.huf", "a");

    fclose(arq_txt);
    fclose(arq_huf);
}

void descomprimeArquivo(){
    FILE *arq_huf = fopen("arquivo.huf", "a");
    FILE *arq_descomprimido = fopen("arquivo_descomprimido.txt", "a");
}