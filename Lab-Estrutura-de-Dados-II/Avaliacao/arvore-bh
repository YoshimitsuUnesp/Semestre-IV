#define MAX 3
#define MIN 2

typedef struct No
{
    int item[MAX + 1], count;
    struct No *link[MAX + 1];
} No;

No *raiz;

No *criarNo(int item, No *filho);
void InserirValor(int item, int pos, No *no, No *filho);
void divideNo(int item, int *pval, int pos, No *no, No *filho, No **novoNo);
int setNo(int item, int *pval, No *no, No **filho);
void inserir(int item);
void procura(No *noSelecionado);

