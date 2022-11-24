#include <stdio.h>
#include <stdlib.h>
#define MAX 3
#define MIN 2
typedef struct No
{
    int item[MAX + 1], count;
    struct No *link[MAX + 1];
} No;

No *raiz;

void InserirValor(int item, int pos, No *no, No *filho)
{
    int j = no->count;
    while (j > pos)
    {
        no->item[j + 1] = no->item[j];
        no->link[j + 1] = no->link[j];
        j--;
    }
    no->item[j + 1] = item;
    no->link[j + 1] = filho;
    no->count++;
}

void divideNo(int item, int *pval, int pos, No *no,
              No *filho, No **novoNo)
{
    int mediana, j;
    if (pos > MIN)
        mediana = MIN + 1;
    else
        mediana = MIN;
    *novoNo = (No *)malloc(sizeof(No));
    j = mediana + 1;
    while (j <= MAX)
    {
        (*novoNo)->item[j - mediana] = no->item[j];
        (*novoNo)->link[j - mediana] = no->link[j];
        j++;
    }
    no->count = mediana;
    (*novoNo)->count = MAX - mediana;
    if (pos <= MIN)
    {
        InserirValor(item, pos, no, filho);
    }
    else
    {
        InserirValor(item, pos - mediana, *novoNo, filho);
    }
    *pval = no->item[no->count];
    (*novoNo)->link[0] = no->link[no->count];
    no->count--;
}

int setNo(int item, int *pval, No *no, No **filho)
{
    int pos;
    if (!no)
    {
        *pval = item;
        *filho = NULL;
        return 1;
    }
    if (item < no->item[1])
    {
        pos = 0;
    }
    else
    {
        for (pos = no->count; (item < no->item[pos] && pos > 1);
             pos--)
            ;
        if (item == no->item[pos])
        {
            printf("Não permite valor duplicado\n");
            return 0;
        }
    }
    if (setNo(item, pval, no->link[pos], filho))
    {
        if (no->count < MAX)
        {
            InserirValor(*pval, pos, no, *filho);
        }
        else
        {
            divideNo(*pval, pval, pos, no, *filho, filho);
            return 1;
        }
    }
    return 0;
}

No *criarNo(int item, No *filho)
{
    No *novoNo;
    novoNo = (No *)malloc(sizeof(No));
    novoNo->item[1] = item;
    novoNo->count = 1;
    novoNo->link[0] = raiz;
    novoNo->link[1] = filho;
    return novoNo;
}

void inserir(int item)
{
    int flag, i;
    No *filho;
    flag = setNo(item, &i, raiz, &filho);
    if (flag)
        raiz = criarNo(i, filho);
}

int procura(No *noSelecionado, int item)
{
    int i;
    if (noSelecionado)
    {
        for (i = 0; i < noSelecionado->count; i++)
        {
            if (procura(noSelecionado->link[i], item))
                return 1;
            if (noSelecionado->item[i + 1] == item)
                return 1;
        }
        if (noSelecionado->link[i], item)
            return 1;
    }
    return 0;
}

int main()
{
    int item, ch, achou;
    int op;
    do
    {
        putchar('\n');
        printf("----------------------\n"
               "|   Menu de opcoes:  |\n"
               "----------------------\n"
               "| 1 - Inserir item   |\n"
               "| 2 - Localizar item |\n"
               "| 3 - Sair           |\n"
               "----------------------\n");
        printf("Escolha uma opcao (1-3):\n");
        scanf(" %d", &op);
        switch (op)
        {
        case 1:
            printf("Digite o valor a ser inserido:\n");
            scanf("%d", &item);
            inserir(item);
            break;
        case 2:
            printf("Digite o item a ser localizado:\n");
            scanf("%d", &ch);
            achou = procura(raiz, item);
            if (achou == 1)
                printf("Item encontrado!\n");
            else
                printf("ERRO: nao foi possivel encontrar o item!\n");
            break;
        case 3:
            printf("Encerrando programa...\n");
            exit(0);
            break;
        default:
            break;
        }
    } while (op != 3);
}