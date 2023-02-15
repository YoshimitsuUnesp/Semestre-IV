#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define M 5 // Define a ordem da arvore

void menuPrincipal()
{
    int op;
    ArvoreB arvB;
    arvB.raiz = criaNo();

    do
    {
        printf("\n"
               "| ---------------- |\n"
               "|  MENU PRINCIPAL  |\n"
               "| 1 - Gravar aluno |\n"
               "| 2 - Buscar aluno |\n"
               "| 3 - Fechar       |\n"
               "| ---------------- |\n");
        printf("\nEscolha uma opcao (1-3):\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            cadastraAluno(&arvB);
            break;
        case 2:
            procuraAlunoArvore(&arvB);
            //procuraAlunoArquivo();
            break;
        case 3:
            printf("\nEncerrando programa...\n");
            exit(0);
            break;
        default:
            printf("\nERRO: Escolha uma opcao valida!\n");
            break;
        }
    } while (op != 3);
}

void cadastraAluno(ArvoreB *arvB)
{
    // Aloca um aluno
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));

    if (!aluno)
    {
        printf("\nERRO: memoria insuficiente!\n", "Encerrando programa\n");
        exit(1);
    }

    // Recebe os dados do aluno e salva na struct
    printf("Digite o RA do aluno:\n");
    scanf("%d", &aluno->ra);
    printf("Digite o curso do aluno:\n");
    scanf("%*c");
    fgets(aluno->curso, 58, stdin);
    aluno->curso[strcspn(aluno->curso, "\n")] = 0;
    printf("Digite o nome do aluno:\n");
    fgets(aluno->nome, 58, stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = 0;

    // Abre o arquivo turma a ser escrito
    FILE *turma = fopen("turma.dat", "a");

    if (!turma)
    {
        printf("ERRO: nao foi possivel abrir o arquivo!\n");
        exit(1);
    }

    // Coloca o ponteiro no final do arquivo
    fseek(turma, 0, SEEK_END);
    int inicio = ftell(turma);
    fprintf(turma, "%d|", aluno->ra);
    fprintf(turma, "%s|", aluno->curso);
    fprintf(turma, "%s|", aluno->nome);
    int fim = ftell(turma);

    // Escreve # ao final do registro
    int i;
    for (i = fim; i < (inicio + 128); i++)
        fprintf(turma, "#");

    fclose(turma);
    Aluno novoAluno;
    memcpy(&novoAluno, aluno, sizeof(Aluno));
    insereAluno(arvB, novoAluno);
    printf("\nAluno cadastrado com sucesso!\nPressione qualquer tecla para continuar\n");
    scanf("%*c");
}

void procuraAlunoArvore(ArvoreB *arvB)
{
    int ra;

    printf("\nDigite o RA do aluno a ser procurado:\n");
    scanf("%d", &ra);
    Aluno *encontrado = buscaAluno(arvB, ra);
    if (encontrado != NULL)
    {
        printf("\nAluno encontrado!\nCurso: %s\nNome: %s", encontrado->curso, encontrado->nome);
    }
    else
    {
        printf("\nERRO: Nao foi possivel encontrar o aluno!");
    }
}

void procuraAlunoArquivo()
{
    int ra;

    printf("\nDigite o RA do aluno a ser procurado:\n");
    scanf("%d", &ra);
    Aluno *encontrado = buscaAlunoArquivo(ra);
    if (encontrado != NULL)
    {
        printf("\nAluno encontrado!\nCurso: %s\nNome: %s", encontrado->curso, encontrado->nome);
    }
    else
    {
        printf("\nERRO: Nao foi possivel encontrar o aluno!");
    }
}

// alocar memória para um novo nó
No *criaNo()
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->qtd = 0;
    novoNo->rrn = -1;

    return novoNo;
}

// Insere aluno na árvore
void insereAluno(ArvoreB *arvB, Aluno aluno)
{
    No *raiz = arvB->raiz;

    if (raiz->qtd == M - 1) // Verifica se o nó está cheio
    {
        No *no = criaNo();
        arvB->raiz = no; // Define o novo nó como uma raiz
        no->filho[0] = raiz;
        divideFilho(no, 0);
        insereNoIncompleto(no, aluno);
    }
    else
    {
        insereNoIncompleto(raiz, aluno);
    }
}

// Insere aluno se o nó não estiver cheio
void insereNoIncompleto(No *no, Aluno aluno)
{
    int i = no->qtd - 1;

    // Verifica se o filho esta sem chaves
    if (no->filho[0] == NULL)
    {
        // Caso o aluno a ser inserido tenha o RA menor do que a chave, avança uma posição e decrementa i
        while (i >= 0 && aluno.ra < no->chave[i].ra)
        {
            no->chave[i + 1] = no->chave[i];
            i--;
        }

        no->chave[i + 1] = aluno;
        no->qtd++;

        // Novo RRN do nó
        no->rrn = novoRrn();
        escreveIndice(no);
    }
    else
    {
        // Mesma verificação que a anterior, mas apenas zera i
        while (i >= 0 && aluno.ra < no->chave[i].ra)
        {
            i--;
        }

        i++; // i = 1

        if (no->filho[i]->qtd == M - 1)
        {
            divideFilho(no, i);

            if (aluno.ra > no->chave[i].ra)
            {
                i++;
            }
        }

        insereNoIncompleto(no->filho[i], aluno);
    }
}

// Divide o filho de um no
void divideFilho(No *no, int i)
{
    No *filho = no->filho[i];
    No *novo = criaNo();
    novo->qtd = M / 2 - 1;
    int j;

    // Verificação para undeflow
    for (j = 0; j < M / 2 - 1; j++)
    {
        novo->chave[j] = filho->chave[j + M / 2];
    }
    if (filho->filho[0] != NULL)
    {
        for (j = 0; j < M / 2; j++)
        {
            novo->filho[j] = filho->filho[j + M / 2];
        }
    }

    // filho->qtd recebe o mínimo para não ocorrer undeflow
    filho->qtd = M / 2 - 1;

    for (j = no->qtd; j >= i + 1; j--)
    {
        no->filho[j + 1] = no->filho[j];
    }

    no->filho[i + 1] = novo;
    for (j = no->qtd - 1; j >= i; j--)
    {
        no->chave[j + 1] = no->chave[j];
    }
    no->chave[i] = filho->chave[M / 2 - 1];
    no->qtd++;

    // Atualizar o RRN dos nós
    filho->rrn = novoRrn();
    novo->rrn = novoRrn();
    escreveIndice(filho);
    escreveIndice(novo);
}

// Da um novo RRN ao no
int novoRrn()
{
    int rrnArquivo = -1;
    FILE *arquivo = fopen("ibtree.idx", "r");
    int rrn, ra;

    while (fscanf(arquivo, "%d %d", &rrn, &ra) == 2)
    {
        rrnArquivo = rrn;
    }
    fclose(arquivo);

    return rrnArquivo + 1;
}

void escreveIndice(No *no)
{
    int i = 0;
    FILE *arquivo = fopen("ibtree.idx", "a");

    for (i; i < no->qtd; i++)
        ;

    // A posição atual de i está acima do numero atual de chaves, então é necessário decrementá-lo
    fprintf(arquivo, "%d %d\n", no->rrn, no->chave[i - 1].ra);
    fclose(arquivo);
}

// Busca o aluno na árvore
Aluno *buscaAluno(ArvoreB *arvB, int ra)
{
    No *raiz = arvB->raiz;
    return buscaNo(raiz, ra);
}

// Busca o aluno no arquivo de dados de acordo com o indice
Aluno *buscaAlunoArquivo(int ra)
{
    FILE *indice = fopen("ibtree.idx", "r");
    FILE *turma = fopen("turma.dat", "r");
    int rrn, raArquivo;
    char buffer[128 + 1];
    char *curso, *nome;
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));

    if (!aluno)
    {
        printf("\nERRO: memoria insuficiente!\n", "Encerrando programa\n");
        exit(1);
    }

    // Percorre o arquivo até o final
    while (!feof(indice))
    {
        fscanf(indice, "%d %d\n", &rrn, &raArquivo);
        if (raArquivo == ra)
        {
            fseek(turma, rrn * 128, SEEK_SET);
            fread(buffer, sizeof(char), 128, turma);
            buffer[128] = '\0'; // Adiciona null no buffer, por conta do fread
            strtok(buffer, "|"); // Pula o primeiro parametro (RA)
            curso = strtok(NULL, "|");
            nome = strtok(NULL, "|");
            strcpy(aluno->curso, curso);
            strcpy(aluno->nome, nome);
            aluno->ra = ra;
            return aluno;
        }
    }

    fclose(indice);
    fclose(turma);

    return NULL;
}

// Busca o aluno em um nó
Aluno *buscaNo(No *no, int ra)
{
    int i = 0;
    while (i < no->qtd && ra > no->chave[i].ra)
    {
        i++;
    }
    if (i < no->qtd && ra == no->chave[i].ra)
    {
        return &no->chave[i];
    }
    else if (no->filho[0] == NULL)
    {
        return NULL;
    }
    else
    {
        return buscaNo(no->filho[i], ra);
    }
}