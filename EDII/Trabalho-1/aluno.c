#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno
{
    char *nome[50];
    char *curso[40];
    int nro_UNESP;
};

Aluno *criaAluno(char *nome, char *curso, int nro_UNESP)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));

    if (!aluno)
    {
        printf("ERRO: memória insuficiente!\n");
        exit(1);
    }
    
    aluno->nro_UNESP = nro_UNESP;
    strcpy(aluno->nome, nome);
    strcpy(aluno->curso, curso);

    return aluno;
}

void cadastraAluno(Aluno *aluno){
    FILE *file = fopen("turma.txt", "w");

    if(!file){
        printf("ERRO: nao foi possivel abrir o arquivo!\n");
        exit(1);
    }

    fprintf(file, "%d\n", aluno->nro_UNESP);
    fprintf(file, "%s\n", aluno->nome);
    fprintf(file, "%s\n", aluno->curso);

    fclose(file); 
}

void listaAluno(){

}
