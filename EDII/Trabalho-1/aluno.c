#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

void cadastraAluno()
{
    // Aloca um aluno
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));

    if (!aluno)
    {
        printf("ERRO: memoria insuficiente!\n", "Encerrando programa\n");
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
    FILE *turma = fopen("turma.txt", "a");

    if (!turma)
    {
        printf("ERRO: nao foi possivel abrir o arquivo!\n");
        exit(1);
    }

    int inicio = ftell(turma);
    fprintf(turma, "%d|", aluno->ra);
    fprintf(turma, "%s|", aluno->curso);
    fprintf(turma, "%s|", aluno->nome);
    int fim = ftell(turma);

    // Escreve # ao final do registro
    int i;
    for (i = fim; i < (inicio + 128); i++)
        fprintf(turma, "#");
    fprintf(turma, "\n");

    fclose(turma);

    printf("\nAluno cadastrado com sucesso!\nPressione qualquer tecla para continuar\n");
    scanf("%*c");
}

void buscaAluno(int ra)
{
    FILE *turma = fopen("turma.txt", "r");
    FILE *index = fopen("index.txt", "a");
    char c;

    int inicio = fseek(turma, 0, SEEK_CUR);
    int i = 0;

    while (c != '\n')
    {
        fprintf(index, "%d ", i);
        while (c != '|')
        {
            c = fgetc(turma);
            fputc(c, index);   
        }
        fprintf(index, "\n");
        i++;

    }
}
