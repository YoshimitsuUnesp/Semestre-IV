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

// Set the value in the no
int setValueInNode(int valor, int *pval, ArvoreB *no, ArvoreB **filho)
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
    for (posicao = no->contador;
         (valor < no->valor[posicao] && posicao > 1); posicao--)
      ;
    if (valor == no->valor[posicao])
    {
      printf("Duplicates not allowed\n");
      return 0;
    }
  }
  if (setValueInNode(valor, pval, no->link[posicao], filho))
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

// Insertion operation
void insertion(int valor)
{
  int flag, i;
  ArvoreB *filho;

  flag = setValueInNode(valor, &i, raiz, &filho);
  if (flag)
    raiz = criaNo(i, filho);
}

// Copy the successor
void copySuccessor(ArvoreB *myNode, int posicao)
{
  ArvoreB *dummy;
  dummy = myNode->link[posicao];

  for (; dummy->link[0] != NULL;)
    dummy = dummy->link[0];
  myNode->valor[posicao] = dummy->valor[1];
}

// Remove the value
void removeVal(ArvoreB *myNode, int posicao)
{
  int i = posicao + 1;
  while (i <= myNode->contador)
  {
    myNode->valor[i - 1] = myNode->valor[i];
    myNode->link[i - 1] = myNode->link[i];
    i++;
  }
  myNode->contador--;
}

// Do right shift
void rightShift(ArvoreB *myNode, int posicao)
{
  ArvoreB *x = myNode->link[posicao];
  int i = x->contador;

  while (i > 0)
  {
    x->valor[i + 1] = x->valor[i];
    x->link[i + 1] = x->link[i];
  }
  x->valor[1] = myNode->valor[posicao];
  x->link[1] = x->link[0];
  x->contador++;

  x = myNode->link[posicao - 1];
  myNode->valor[posicao] = x->valor[x->contador];
  myNode->link[posicao] = x->link[x->contador];
  x->contador--;
  return;
}

// Do left shift
void leftShift(ArvoreB *myNode, int posicao)
{
  int i = 1;
  ArvoreB *x = myNode->link[posicao - 1];

  x->contador++;
  x->valor[x->contador] = myNode->valor[posicao];
  x->link[x->contador] = myNode->link[posicao]->link[0];

  x = myNode->link[posicao];
  myNode->valor[posicao] = x->valor[1];
  x->link[0] = x->link[1];
  x->contador--;

  while (i <= x->contador)
  {
    x->valor[i] = x->valor[i + 1];
    x->link[i] = x->link[i + 1];
    i++;
  }
  return;
}

// Merge the nodes
void mergeNodes(ArvoreB *myNode, int posicao)
{
  int i = 1;
  ArvoreB *x1 = myNode->link[posicao], *x2 = myNode->link[posicao - 1];

  x2->contador++;
  x2->valor[x2->contador] = myNode->valor[posicao];
  x2->link[x2->contador] = myNode->link[0];

  while (i <= x1->contador)
  {
    x2->contador++;
    x2->valor[x2->contador] = x1->valor[i];
    x2->link[x2->contador] = x1->link[i];
    i++;
  }

  i = posicao;
  while (i < myNode->contador)
  {
    myNode->valor[i] = myNode->valor[i + 1];
    myNode->link[i] = myNode->link[i + 1];
    i++;
  }
  myNode->contador--;
  free(x1);
}

// Adjust the no
void adjustNode(ArvoreB *myNode, int posicao)
{
  if (!posicao)
  {
    if (myNode->link[1]->contador > MIN)
    {
      leftShift(myNode, 1);
    }
    else
    {
      mergeNodes(myNode, 1);
    }
  }
  else
  {
    if (myNode->contador != posicao)
    {
      if (myNode->link[posicao - 1]->contador > MIN)
      {
        rightShift(myNode, posicao);
      }
      else
      {
        if (myNode->link[posicao + 1]->contador > MIN)
        {
          leftShift(myNode, posicao + 1);
        }
        else
        {
          mergeNodes(myNode, posicao);
        }
      }
    }
    else
    {
      if (myNode->link[posicao - 1]->contador > MIN)
        rightShift(myNode, posicao);
      else
        mergeNodes(myNode, posicao);
    }
  }
}

// Delete a value from the no
int delValFromNode(int valor, ArvoreB *myNode)
{
  int posicao, flag = 0;
  if (myNode)
  {
    if (valor < myNode->valor[1])
    {
      posicao = 0;
      flag = 0;
    }
    else
    {
      for (posicao = myNode->contador; (valor < myNode->valor[posicao] && posicao > 1); posicao--)
        ;
      if (valor == myNode->valor[posicao])
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
      if (myNode->link[posicao - 1])
      {
        copySuccessor(myNode, posicao);
        flag = delValFromNode(myNode->valor[posicao], myNode->link[posicao]);
        if (flag == 0)
        {
          printf("Given data is not present in B-Tree\n");
        }
      }
      else
      {
        removeVal(myNode, posicao);
      }
    }
    else
    {
      flag = delValFromNode(valor, myNode->link[posicao]);
    }
    if (myNode->link[posicao])
    {
      if (myNode->link[posicao]->contador < MIN)
        adjustNode(myNode, posicao);
    }
  }
  return flag;
}

// Delete operaiton
void delete(int valor, ArvoreB *myNode)
{
  ArvoreB *tmp;
  if (!delValFromNode(valor, myNode))
  {
    printf("Not present\n");
    return;
  }
  else
  {
    if (myNode->contador == 0)
    {
      tmp = myNode;
      myNode = myNode->link[0];
      free(tmp);
    }
  }
  raiz = myNode;
  return;
}

void searching(int valor, int *posicao, ArvoreB *myNode)
{
  if (!myNode)
  {
    return;
  }

  if (valor < myNode->valor[1])
  {
    *posicao = 0;
  }
  else
  {
    for (*posicao = myNode->contador;
         (valor < myNode->valor[*posicao] && *posicao > 1); (*posicao)--)
      ;
    if (valor == myNode->valor[*posicao])
    {
      printf("%d present in B-tree", valor);
      return;
    }
  }
  searching(valor, posicao, myNode->link[*posicao]);
  return;
}

void traversal(ArvoreB *myNode)
{
  int i;
  if (myNode)
  {
    for (i = 0; i < myNode->contador; i++)
    {
      traversal(myNode->link[i]);
      printf("%d ", myNode->valor[i + 1]);
    }
    traversal(myNode->link[i]);
  }
}

int main()
{
  int valor, ch;

  insertion(8);
  insertion(9);
  insertion(10);
  insertion(11);
  insertion(15);
  insertion(16);
  insertion(17);
  insertion(18);
  insertion(20);
  insertion(23);

  traversal(raiz);

  delete (20, raiz);
  printf("\n");
  traversal(raiz);
}