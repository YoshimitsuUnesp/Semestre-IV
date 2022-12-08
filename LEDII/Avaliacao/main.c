#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2

typedef struct no
{
  int valor[MAX + 1], contador;
  struct no *link[MAX + 1];
} ArvoreB;

// Variavel global para demarcar a raiz
ArvoreB *raiz;

// Cria o no
ArvoreB *criaNo(int valor, ArvoreB *filho)
{
  ArvoreB *novoNo;
  novoNo = (ArvoreB *)malloc(sizeof(ArvoreB));
  novoNo->valor[1] = valor;
  novoNo->contador = 1;
  novoNo->link[0] = raiz;
  novoNo->link[1] = filho;

  return novoNo;
}

// Adiciona o valor ao no
void adicionaValor(int valor, int posicao, ArvoreB *no, ArvoreB *filho)
{
  int i;

  for (i = no->contador; i > posicao; i--)
  {
    no->valor[i + 1] = no->valor[i];
    no->link[i + 1] = no->link[i];
  }

  no->valor[i + 1] = valor;
  no->link[i + 1] = filho;
  no->contador++;
}

// Separa o no pela mediana
void split(int valor, int *pval, int posicao, ArvoreB *no, ArvoreB *filho, ArvoreB **novoNo)
{
  int mediana, i;

  if (posicao > MIN)
    mediana = MIN + 1;
  else
    mediana = MIN;

  *novoNo = (ArvoreB *)malloc(sizeof(ArvoreB));

  for (i = mediana + 1; i <= MAX; i++)
  {
    (*novoNo)->valor[i - mediana] = no->valor[i];
    (*novoNo)->link[i - mediana] = no->link[i];
  }

  no->contador = mediana;
  (*novoNo)->contador = MAX - mediana;

  if (posicao <= MIN)
    adicionaValor(valor, posicao, no, filho);
  else
    adicionaValor(valor, posicao - mediana, *novoNo, filho);

  *pval = no->valor[no->contador];
  (*novoNo)->link[0] = no->link[no->contador];
  no->contador--;
}

// Seta o valor no no
int setValor(int valor, int *pval, ArvoreB *no, ArvoreB **filho)
{
  int posicao;
  if (!no)
  {
    *pval = valor;
    *filho = NULL;
    return 1;
  }

  if (valor < no->valor[1])
  {
    posicao = 0;
  }
  else
  {
    for (posicao = no->contador; (valor < no->valor[posicao]) && (posicao > 1); posicao--)
      ;
    if (valor == no->valor[posicao])
    {
      printf("ERRO: Valores duplicados nao sao permitidos!\n");
      return 0;
    }
  }
  if (setValor(valor, pval, no->link[posicao], filho))
  {
    if (no->contador < MAX)
    {
      adicionaValor(*pval, posicao, no, *filho);
    }
    else
    {
      split(*pval, pval, posicao, no, *filho, filho);
      return 1;
    }
  }
  return 0;
}

// Insere o valor na arvore
void insercao(int valor)
{
  int flag, i;
  ArvoreB *filho;

  flag = setValor(valor, &i, raiz, &filho);
  if (flag)
    raiz = criaNo(i, filho);
}

// Copia o sucessor
void copiaSucessor(ArvoreB *no, int posicao)
{
  ArvoreB *aux;

  for (aux = no->link[posicao]; aux->link[0] != NULL;)
    aux = aux->link[0];
  no->valor[posicao] = aux->valor[1];
}

// Remove o valor
void removeValor(ArvoreB *no, int posicao)
{
  int i;
  for (i = posicao + 1; i <= no->contador; i++)
  {
    no->valor[i - 1] = no->valor[i];
    no->link[i - 1] = no->link[i];
  }
  no->contador--;
}

// Faz a troca pela direita
void trocaDireita(ArvoreB *no, int posicao)
{
  ArvoreB *x = no->link[posicao];
  int i = x->contador;

  while (i > 0)
  {
    x->valor[i + 1] = x->valor[i];
    x->link[i + 1] = x->link[i];
  }
  x->valor[1] = no->valor[posicao];
  x->link[1] = x->link[0];
  x->contador++;

  x = no->link[posicao - 1];
  no->valor[posicao] = x->valor[x->contador];
  no->link[posicao] = x->link[x->contador];
  x->contador--;
  return;
}

// Faz a troca pela esquerda
void trocaEsquerda(ArvoreB *no, int posicao)
{
  int i;
  ArvoreB *x = no->link[posicao - 1];

  x->contador++;
  x->valor[x->contador] = no->valor[posicao];
  x->link[x->contador] = no->link[posicao]->link[0];

  x = no->link[posicao];
  no->valor[posicao] = x->valor[1];
  x->link[0] = x->link[1];
  x->contador--;

  for (i = 1; i <= x->contador; i++)
  {
    x->valor[i] = x->valor[i + 1];
    x->link[i] = x->link[i + 1];
  }

  return;
}

// Une os nos necessarios
void unirNos(ArvoreB *no, int posicao)
{
  int i;
  ArvoreB *x1 = no->link[posicao], *x2 = no->link[posicao - 1];

  x2->contador++;
  x2->valor[x2->contador] = no->valor[posicao];
  x2->link[x2->contador] = no->link[0];

  for (i = 1; i <= x1->contador; i++)
  {
    x2->contador++;
    x2->valor[x2->contador] = x1->valor[i];
    x2->link[x2->contador] = x1->link[i];
  }

  for (i = posicao; i < no->contador; i++)
  {
    no->valor[i] = no->valor[i + 1];
    no->link[i] = no->link[i + 1];
  }
  no->contador--;
  free(x1);
}

// Ajusta o no
void ajustaNo(ArvoreB *no, int posicao)
{
  if (!posicao)
  {
    if (no->link[1]->contador > MIN)
    {
      trocaEsquerda(no, 1);
    }
    else
    {
      unirNos(no, 1);
    }
  }
  else
  {
    if (no->contador != posicao)
    {
      if (no->link[posicao - 1]->contador > MIN)
      {
        trocaDireita(no, posicao);
      }
      else
      {
        if (no->link[posicao + 1]->contador > MIN)
        {
          trocaEsquerda(no, posicao + 1);
        }
        else
        {
          unirNos(no, posicao);
        }
      }
    }
    else
    {
      if (no->link[posicao - 1]->contador > MIN)
        trocaDireita(no, posicao);
      else
        unirNos(no, posicao);
    }
  }
}

// Deleta um valor do no
int deletaValor(int valor, ArvoreB *no)
{
  int posicao, flag = 0;
  if (no)
  {
    if (valor < no->valor[1])
    {
      posicao = 0;
      flag = 0;
    }
    else
    {
      for (posicao = no->contador; (valor < no->valor[posicao] && posicao > 1); posicao--)
        ;
      if (valor == no->valor[posicao])
      {
        flag = 1;
      }
      else
      {
        flag = 0;
      }
    }
    if (flag)
    {
      if (no->link[posicao - 1])
      {
        copiaSucessor(no, posicao);
        flag = deletaValor(no->valor[posicao], no->link[posicao]);
        if (flag == 0)
        {
          printf("ERRO: nao foi possivel encontrar o valor!\n");
        }
      }
      else
      {
        removeValor(no, posicao);
      }
    }
    else
    {
      flag = deletaValor(valor, no->link[posicao]);
    }
    if (no->link[posicao])
    {
      if (no->link[posicao]->contador < MIN)
        ajustaNo(no, posicao);
    }
  }
  return flag;
}

// Deleta o no
void delete(int valor, ArvoreB *no)
{
  ArvoreB *tmp;
  if (!deletaValor(valor, no))
  {
    printf("ERRO: no nao existente!\n");
    return;
  }
  else
  {
    if (no->contador == 0)
    {
      tmp = no;
      no = no->link[0];
      free(tmp);
    }
  }
  raiz = no;
  return;
}

void procura(int valor, int *posicao, ArvoreB *no)
{
  if (!no)
  {
    return;
  }

  if (valor < no->valor[1])
  {
    *posicao = 0;
  }
  else
  {
    for (*posicao = no->contador; (valor < no->valor[*posicao]) && (*posicao > 1); (*posicao)--)
      ;
    if (valor == no->valor[*posicao])
    {
      printf("O valor %d foi encontrado!", valor);
      return;
    }
  }
  procura(valor, posicao, no->link[*posicao]);
  return;
}

void imprimeArvore(ArvoreB *no)
{
  int i;
  if (no)
  {
    for (i = 0; i < no->contador; i++)
    {
      imprimeArvore(no->link[i]);
      printf("%d ", no->valor[i + 1]);
    }
    imprimeArvore(no->link[i]);
  }
}

int main()
{
  int valor, ch;

  insercao(8);
  insercao(9);

  insercao(20);
  insercao(23);

  imprimeArvore(raiz);

  delete (20, raiz);
  printf("\n");
  imprimeArvore(raiz);
}