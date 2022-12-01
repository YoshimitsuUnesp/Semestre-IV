#define MAX 3
#define MIN 2
#define bool int
#define true 1
#define false 0

typedef struct no
{
  int chave[MAX+1];
  struct no *filha[MAX+1];
  int nregs;
  int ordem;
}NoArvB;

NoArvB *raiz;
