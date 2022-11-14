#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
#include "arvore.h"

#define ASCII 256 // Tabela ASCII (0 a 255 + \0)

// Cria tabela de frequencia
void criaTabela(unsigned int tabela[])
{
    int i;

    for (i = 0; i < ASCII; i++)
        tabela[i] = 0;
}

// Preenche a tabela com o texto
void prencheTabela(unsigned char texto[], unsigned int tabela[])
{
    int i = 0;

    while (texto[i] != '\0')
    {
        tabela[texto[i]]++;
        i++;
    }
}

// Cria a lista dos nos
void criaLista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}

// Insere os nos de forma ordenada na lista
void insereOrdenado(Lista *lista, Arvore *no)
{
    Arvore *aux;

    // Verificacao de lista vazia
    if (!lista->inicio)
        lista->inicio = no;
    // Compara se o no deve ser o novo inicio
    else if (no->freq < lista->inicio->freq)
    {
        no->prox = lista->inicio;
        lista->inicio = no;
    }
    else
    {
        aux = lista->inicio;
        while (aux->prox && aux->prox->freq <= no->freq)
            aux = aux->prox;
        no->prox = aux->prox;
        aux->prox = no;
    }
    lista->tam++;
}

void preencheLista(unsigned int tabela[], Lista *lista)
{
    int i;
    Arvore *novo;
    for (i = 0; i < ASCII; i++)
    {
        if (tabela[i] > 0)
        {
            novo = (Arvore *)malloc(sizeof(Arvore));
            if (novo)
            {
                novo->caracter = i;
                novo->freq = tabela[i];
                novo->dir = NULL;
                novo->esq = NULL;
                novo->prox = NULL;

                insereOrdenado(lista, novo);
            }
            else
            {
                printf("\tERRO: nao foi possivel preencher a lista de caracteres!\n");
                break;
            }
        }
    }
}

// Cria o cabecalho e retorna o ponteiro de seu final
long cabecalho(Lista *lista, char *nomeArquivo)
{
    char arquivoHuf[100] = {0};
    strcpy(arquivoHuf, nomeArquivo);

    strcat(arquivoHuf, ".huf");

    FILE *huf = fopen(arquivoHuf, "w");
    Arvore *aux = lista->inicio;

    fprintf(huf, "HUFFMAN 1.0\n"
                 "%d\n",
            lista->tam);

    while (aux)
    {
        fprintf(huf, "%c %d\n", aux->caracter, aux->freq);
        aux = aux->prox;
    }
    long fimCabecalho = ftell(huf);
    fclose(huf);
    return fimCabecalho;
}

// Remove no inicio
Arvore *removeInicio(Lista *lista)
{
    Arvore *aux = NULL;

    if (lista->inicio)
    {
        aux = lista->inicio;
        lista->inicio = aux->prox;
        aux->prox = NULL;
        lista->tam--;
    }

    return aux;
}

// Cria e retorna a arvore
Arvore *criaArvore(Lista *lista)
{
    Arvore *primeiro, *segundo, *novo;

    while (lista->tam > 1)
    {
        primeiro = removeInicio(lista);
        segundo = removeInicio(lista);
        novo = (Arvore *)malloc(sizeof(Arvore));

        if (novo)
        {
            novo->caracter = '+';
            novo->freq = primeiro->freq + segundo->freq;
            novo->esq = primeiro;
            novo->dir = segundo;
            novo->prox = NULL;

            insereOrdenado(lista, novo);
        }
        else
        {
            printf("\tERRO: nao foi possivel criar a arvore!\n");
            break;
        }
    }
    return lista->inicio;
}

// Retorna a altura da arvore
int alturaArvore(Arvore *raiz)
{
    int esq, dir;

    if (!raiz)
        return -1;
    else
    {
        esq = alturaArvore(raiz->esq) + 1;
        dir = alturaArvore(raiz->dir) + 1;

        if (esq > dir)
            return esq;
        else
            return dir;
    }
}

// Cria o dicionario zerado na memoria
char **criaDicionario(int col)
{
    char **dicionario;
    int i;

    dicionario = (char **)malloc(sizeof(char *) * ASCII);

    for (i = 0; i < ASCII; i++)
        dicionario[i] = (char *)calloc(col, sizeof(char));

    return dicionario;
}

// Traduz a tabela ASCII para binario
void traduzDicionario(char **dicionario, Arvore *raiz, char *caminho, int col)
{
    char esq[col], dir[col];

    if (!raiz->esq && !raiz->dir)
        strcpy(dicionario[raiz->caracter], caminho);
    else
    {
        strcpy(esq, caminho);
        strcpy(dir, caminho);

        strcat(esq, "0");
        strcat(dir, "1");

        traduzDicionario(dicionario, raiz->esq, esq, col);
        traduzDicionario(dicionario, raiz->dir, dir, col);
    }
}

// Calcula e retorna o tamanho do texto
int tamanhoTexto(char **dicionario, unsigned char *texto)
{
    int i = 0, tam = 0;

    while (texto[i] != '\0')
    {
        tam = tam + strlen(dicionario[texto[i]]);
        i++;
    }
    return tam + 1;
}

// Codifica o texto e o retorna
char *codifica(char **dicionario, unsigned char *texto)
{

    int i = 0, tam = tamanhoTexto(dicionario, texto);
    char *codigo = (char *)calloc(tam, sizeof(char));

    while (texto[i] != '\0')
    {
        strcat(codigo, dicionario[texto[i]]);
        i++;
    }
    return codigo;
}

// Decodifica o texto e o retorna
char *decodifica(char texto[], Arvore *raiz)
{
    int i = 0;
    Arvore *aux = raiz;
    char temp[2];
    char *decodificado = (char *)calloc(strlen(texto), sizeof(char));

    while (texto[i] != '\0')
    {
        if (texto[i] == '0')
            aux = aux->esq;
        else
            aux = aux->dir;

        if (aux->esq == NULL && aux->dir == NULL)
        {
            temp[0] = aux->caracter;
            temp[1] = '\0';
            strcat(decodificado, temp);
            aux = raiz;
        }

        i++;
    }
    return decodificado;
}

void compacta(char texto[], char *nomeArquivo)
{
    char huf[100] = {0};
    strcpy(huf, nomeArquivo);
    strcat(huf, ".huf");

    // Bloco de 8 bits por caracter
    int i = 0, j = 7;
    unsigned char mascara, byte = 0;
    FILE *arquivo = fopen(huf, "a");

    if (arquivo)
    {
        while (texto[i] != '\0')
        {
            mascara = 1;
            if (texto[i] == '1')
            {
                mascara = mascara << j;
                byte = byte | mascara;
            }
            j--;

            if (j < 0)
            { // bloco formado
                fwrite(&byte, sizeof(unsigned char), 1, arquivo);
                byte = 0;
                j = 7;
            }

            i++;
        }
        if (j != 7)
            fwrite(&byte, sizeof(unsigned char), 1, arquivo);
        fclose(arquivo);
    }
    else
        printf("\nERRO: ARQUIVO INEXISTENTE!\nNao foi possivel compactar o arquivo!\n");
}

// Verifica e retorna se o bit for um
unsigned int bitUm(unsigned char byte, int i)
{
    unsigned char mascara = (1 << i);
    return byte & mascara;
}

void descompacta(Arvore *raiz, long comeco, char *huf)
{
    char nomeHuf[100] = {0};
    strcpy(nomeHuf, huf);
    strcat(nomeHuf, ".huf");

    FILE *arquivo = fopen(nomeHuf, "rb");
    FILE *descompactado = fopen("descompactado.txt", "wb");
    Arvore *aux = raiz;
    unsigned char *text;
    long pos;
    int i, j;

    if (arquivo)
    {

        fseek(arquivo, 0, SEEK_END);
        pos = ftell(arquivo);

        text = (unsigned char *)calloc((pos - comeco) + 1, sizeof(unsigned char));

        fseek(arquivo, comeco, SEEK_SET);

        fread(text, pos - comeco, 1, arquivo);

        j = 0;
        while (j < (pos - comeco))
        {
            for (i = 7; i >= 0; i--)
            {
                if (bitUm(text[j], i))
                    aux = aux->dir;
                else
                    aux = aux->esq;

                if (aux->esq == NULL && aux->dir == NULL)
                {
                    fprintf(descompactado, "%c", aux->caracter);
                    aux = raiz;
                }
            }
            j++;
        }
        fclose(descompactado);
        fclose(arquivo);
    }
    else
        printf("\nERRO: ARQUIVO INEXISTENTE!\nNao foi possivel descompactar o arquivo!\n");
}

// Retorna o tamanho do arquivo
int tamanhoArquivo(char *nome)
{
    FILE *arq = fopen(nome, "r");
    int tam = 0;

    if (arq)
    {
        while (fgetc(arq) != -1)
            tam++;
        fclose(arq);
    }
    else
        printf("\nERRO: ARQUIVO INEXISTENTE!\nNao foi possivel descobrir o tamanho do arquivo!\n");
    return tam;
}

void leArquivo(char *nome, unsigned char *texto)
{
    FILE *arq = fopen(nome, "r");
    unsigned char caracter;
    int i = 0;

    if (arq)
    {
        while (!feof(arq))
        {
            caracter = fgetc(arq);
            if (caracter != -1)
            {
                texto[i] = caracter;
                i++;
            }
        }

        texto[i - 1] = '\0';

        fclose(arq);
    }
    else
        printf("\nERRO: ARQUIVO INEXISTENTE!\nNao foi possivel ler o arquivo!\n");
}