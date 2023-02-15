#define M 5 // Define a ordem da arvore

// Struct Aluno passada no documento
typedef struct aluno
{
    int ra;
    char nome[58];
    char curso[58];
} Aluno;

// Struct No que salva os alunos
typedef struct no
{
    int qtd;             // Número atual de chaves no nó
    Aluno chave[M - 1];  // Alunos no nó
    struct no *filho[M]; // Ponteiros para os filhos
    int rrn;             // RRN do nó
} No;

// Struct Arvore B que salva a raiz
typedef struct arvB
{
    No *raiz; // Ponteiro para a raiz
} ArvoreB;

// Inicializa as funções da arvore
No *criaNo();
void insereAluno(ArvoreB *arvB, Aluno aluno);
void insereNoIncompleto(No *no, Aluno aluno);
void divideFilho(No *no, int i);
Aluno *buscaAluno(ArvoreB *arvB, int ra);
Aluno *buscaNo(No *no, int ra);
int novoRrn();

// Inicializa as funções de arquivo
void cadastraAluno(ArvoreB *arvB);
void procuraAlunoArvore(ArvoreB *arvB);
void procuraAlunoArquivo();
Aluno *buscaAlunoArquivo(int ra);
void menuPrincipal();
void escreveIndice(No *no);

