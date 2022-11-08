#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "opcoes.h"

int main()
{
    int op;
    do
    {
        menuPrincipal();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            
            break;
        case 2:
            /* code */
            break;
        case 3:
            sair();
            break;
        default:
            printf("ERRO: opcao invalida!\n");
            break;
        }
    } while (op != 3);

    return 0;
}