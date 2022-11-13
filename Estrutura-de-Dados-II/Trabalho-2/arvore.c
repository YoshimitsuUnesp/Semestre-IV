#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "arvore.h"

/* Converte uma cadeia de bits (vet eh um vetor de caracteres 0’s e 1's)
de n=8 (bits) (tamanho do vetor + '\0’ para fim de string). A funcao
converte o vetor de caracteres 0’s e 1’s em um byte (simbolo ASCII) */
char convert_byte(char *vet, int n)
{
    char rtno = 0,
         i = 0;

    while (i < n)
    {
        rtno += pow(2, i) * (vet[(n - 1) - i] - 48);
        i++;
    }
    return rtno;
}

/* Converte um 1 byte (simbolo char ch) em um vetor de caracteres 0's e
1's (*Vet)*/
void convert(char ch, char *Vet)
{
    int i = 7; // indice auxiliar

    while (i >= 0)
    {
        if (ch & 1)
            Vet[i] = '1';
        else
            Vet[i] = '0';

        i--;
        ch >>= 1;
    }
}

// Cria e retorna a arvore
Arvore *criaArvore()
{
    Arvore *novo = malloc(sizeof(Arvore));
    novo->caracter = '\0';
    novo->dir = NULL;
    novo->esq = NULL;
    novo->freq = 0;

    return novo;
}

// Sera necessario mover para dentro da funcao comprimeArquivo posteriormente
// Escreve o cabecalho do arquivo compactado
void cabecalho(FILE *huf){
    fprintf(huf, "HUFFMAN 1.0\n");
}

// Usa as funcoes auxiliares para comprimir o arquivo
void comprimeArquivo()
{
    FILE *arq_txt = fopen("arquivo.txt", "a");
    FILE *arq_huf = fopen("arquivo.huf", "w");

    cabecalho(arq_huf);

    fclose(arq_txt);
    fclose(arq_huf);
}

//
void descomprimeArquivo()
{
    FILE *arq_huf = fopen("arquivo.huf", "a");
    FILE *arq_descomprimido = fopen("arquivo_descomprimido.txt", "w");
}