#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2
#define bool int
#define true 1
#define false 0

#ifndef ARVOREB_H_
#define ARVOREB_H_

typedef struct no
{
  int chave[MAX+1];
  struct no *filha[MAX+1];
  int nregs;
  int ordem;
}NoArvB;

extern NoArvB *raiz;

void InserirValor(int chave, int pos, NoArvB *no, NoArvB *filho);
void divideNo(int chave, int *pval, int pos, NoArvB *no, NoArvB *filho, NoArvB **novoNo);
int setNo(int chave, int *pval, NoArvB *no, NoArvB **filho);
NoArvB *criarNo(int chave, NoArvB *filho);
void inserir(int chave);
int procura(NoArvB *noSelecionado, int chave);
bool RemoveArvB(NoArvB **arvore, int chave);
bool RemoveArvBRec(NoArvB **no, int chave, bool *underflow);
bool BuscaChaveNoArvB(NoArvB *no, int chave, int *pos);
void TrocaChaveComAntecessora(NoArvB *no, int pos);
void TrataNoComMenosChavesQuePermitido(NoArvB **no, int pos);
void RemoveChaveEmNo(NoArvB *no, int pos);
bool NoComMaisChavesQuePossivel(NoArvB *no);
bool NoComMenosChavesQuePermitido(NoArvB *no);

#endif