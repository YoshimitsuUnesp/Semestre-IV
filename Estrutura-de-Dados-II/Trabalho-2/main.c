#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "opcoes.h"

int main()
{
    int op;
    // Permanece em loop ate que o usuario deseje sair
    do
    {
        menuPrincipal();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            comprimeArquivo(); 
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