// Estrutura que salva o no da arvore
typedef struct no
{
    unsigned char caracter;
    struct no *esq, *dir;
    int freq;
} Arvore;

typedef struct lista
{
    Arvore *inicio;
    int tam;
} Lista;

void cabecalho(FILE *);
void comprimeArquivo();