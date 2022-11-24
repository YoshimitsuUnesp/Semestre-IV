// Estrutura que salva o no da arvore
typedef struct no
{
    unsigned char caracter;
    struct no *esq, *dir, *prox;
    int freq;
} Arvore;

typedef struct lista
{
    Arvore *inicio;
    int tam;
} Lista;

void criaTabela(unsigned int []);
void prencheTabela(unsigned char [], unsigned int []);
void criaLista(Lista *);
void insereOrdenado(Lista *, Arvore *);
void preencheLista(unsigned int [], Lista *);
long cabecalho(Lista *, char *);
Arvore* removeInicio(Lista *);
Arvore* criaArvore(Lista *);
int alturaArvore(Arvore *);
char** criaDicionario(int);
void traduzDicionario(char **, Arvore *, char *, int);
int tamanhoTexto(char **, unsigned char *);
char* codifica(char **, unsigned char *);
char* decodifica( char texto[], Arvore *raiz);
void compacta( char texto[], char *);
unsigned int bitUm(unsigned char byte, int i);
void descompacta(Arvore *raiz, long, char *huf);
int tamanhoArquivo(char *);
void leArquivo(char *, unsigned char *);

