#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "menu.h"

int main()
{
    int op, ra;

    // Loop para manter o programa rodando
    do
    {
        menuPrincipal();
        scanf(" %d", &op);

        switch (op)
        {
        case 1:
            cadastraAluno();
            break;
        case 2:
            printf("Digite o RA do aluno:\n");
            scanf("%d", &ra);
            buscaAluno(ra);
            break;
        case 3:
            printf("Encerrando programa...\n");
            exit(0);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (op != 3);

    return 0;
}