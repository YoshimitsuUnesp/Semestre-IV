#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2
#define bool int
#define true 1
#define false 0

typedef struct no
{
    int chave[MAX + 1];
    struct no *filha[MAX + 1];
    int nregs;
    int ordem;
    int altura;
} NoArvB;

NoArvB *raiz;

void InserirValor(int chave, int pos, NoArvB *no, NoArvB *filho);
void divideNo(int chave, int *pval, int pos, NoArvB *no, NoArvB *filho, NoArvB **novoNo);
int setNo(int chave, int *pval, NoArvB *no, NoArvB **filho);
NoArvB *criarNo(int chave, NoArvB *filho);
void inserir(int chave);
int procura(NoArvB *noSelecionado, int chave);

void InserirValor(int chave, int pos, NoArvB *no, NoArvB *filho)
{
    int j = no->nregs;
    while (j > pos)
    {
        no->chave[j + 1] = no->chave[j];
        no->filha[j + 1] = no->filha[j];
        j--;
    }
    no->chave[j + 1] = chave;
    no->filha[j + 1] = filho;
    no->nregs++;
}

void divideNo(int chave, int *pval, int pos, NoArvB *no, NoArvB *filho, NoArvB **novoNo)
{
    int mediana, j;
    if (pos > MIN)
        mediana = MIN + 1;
    else
        mediana = MIN;
    *novoNo = (NoArvB *)malloc(sizeof(NoArvB));
    j = mediana + 1;
    while (j <= MAX)
    {
        (*novoNo)->chave[j - mediana] = no->chave[j];
        (*novoNo)->filha[j - mediana] = no->filha[j];
        j++;
    }
    no->nregs = mediana;
    (*novoNo)->nregs = MAX - mediana;
    if (pos <= MIN)
    {
        InserirValor(chave, pos, no, filho);
    }
    else
    {
        InserirValor(chave, pos - mediana, *novoNo, filho);
    }
    *pval = no->chave[no->nregs];
    (*novoNo)->filha[0] = no->filha[no->nregs];
    no->nregs--;
}

int setNo(int chave, int *pval, NoArvB *no, NoArvB **filho)
{
    int pos;
    if (!no)
    {
        *pval = chave;
        *filho = NULL;
        return 1;
    }
    if (chave < no->chave[1])
    {
        pos = 0;
    }
    else
    {
        for (pos = no->nregs; (chave < no->chave[pos] && pos > 1);
             pos--)
            ;
        if (chave == no->chave[pos])
        {
            printf("ERRO: Nao sao permitidos valores duplicados\n");
            return 0;
        }
    }
    if (setNo(chave, pval, no->filha[pos], filho))
    {
        if (no->nregs < MAX)
        {
            InserirValor(*pval, pos, no, *filho);
        }
        else
        {
            no->altura++;
            printf("ATENCAO: Fazendo um split...\n");
            divideNo(*pval, pval, pos, no, *filho, filho);
            return 1;
        }
    }
    return 0;
}

NoArvB *criarNo(int chave, NoArvB *filho)
{
    NoArvB *novoNo;
    novoNo = (NoArvB *)malloc(sizeof(NoArvB));
    novoNo->chave[1] = chave;
    novoNo->nregs = 1;
    novoNo->filha[0] = raiz;
    novoNo->filha[1] = filho;
    novoNo->ordem = MAX;
    novoNo->altura = 0;
    return novoNo;
}

void inserir(int chave)
{
    int flag, i;
    NoArvB *filho;
    flag = setNo(chave, &i, raiz, &filho);
    if (flag)
        raiz = criarNo(i, filho);
}

// Lista todos os nós da árvore
void listaArvore(NoArvB *noSelecionado)
{
    int i;

    if (noSelecionado)
    {
        for (i = 0; i < noSelecionado->nregs; i++)
        {
            listaArvore(noSelecionado->filha[i]);
            printf("%d ", noSelecionado->chave[i + 1]);
            printf("Altura do no: %d ", noSelecionado->altura);
        }
        putchar('\n');
        listaArvore(noSelecionado->filha[i]);
    }
}

int procura(NoArvB *noSelecionado, int chave)
{
    int i;
    if (noSelecionado)
    {
        for (i = 0; i < noSelecionado->nregs; i++)
        {
            if (noSelecionado->chave[i + 1] == chave)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int chave, ch, achou;
    int op;
    do
    {
        putchar('\n');
        printf("----------------------\n"
               "|   Menu de opcoes:   |\n"
               "----------------------\n"
               "| 1 - Inserir chave   |\n"
               "| 2 - Localizar chave |\n"
               "| 3 - Listar arvore   |\n"
               "| 4 - Sair            |\n"
               "----------------------\n");
        printf("Escolha uma opcao (1-4):\n");
        scanf(" %d", &op);
        switch (op)
        {
        case 1:
            printf("Digite o valor a ser inserido:\n");
            scanf("%d", &chave);
            inserir(chave);
            break;
        case 2:
            printf("Digite o chave a ser localizado:\n");
            scanf("%d", &ch);
            achou = procura(raiz, ch);
            if (achou == 1)
                printf("Item encontrado!\n");
            else
                printf("ERRO: nao foi possivel encontrar o chave!\n");
            break;
        case 3:
            listaArvore(raiz);
            break;
        case 4:
            printf("Encerrando programa...\n");
            exit(0);
            break;
        default:
            break;
        }
    } while (op != 4);
}