#include <stdio.h>
#include "menu.h"
#include "aluno.h"

int main()
{

    Aluno *aluno = criaAluno("Matheus Yoshimitsu Tamashiro Pires Lanzo", "Bacharelado em Ciencia da Computacao", 211042579);

    cadastraAluno(aluno);

    return 0;
}