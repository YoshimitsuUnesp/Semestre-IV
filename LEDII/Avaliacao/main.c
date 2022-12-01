#include "arvoreB.h"

int main()
{
    int chave, ch, achou;
    int op;
    do
    {
        putchar('\n');
        printf("----------------------\n"
               "|   Menu de opcoes:  |\n"
               "----------------------\n"
               "| 1 - Inserir chave   |\n"
               "| 2 - Localizar chave |\n"
               "| 3 - Sair           |\n"
               "----------------------\n");
        printf("Escolha uma opcao (1-3):\n");
        scanf(" %d", &op);
        switch (op)
        {
        case 1:
            printf("Digite o valor a ser inserido:\n");
            scanf("%d", &chave);
            inserir(chave);
            break;
        case 2:
            printf("Digite o chave a ser localizado:\n");
            scanf("%d", &ch);
            achou = procura(raiz, ch);
            if (achou == 1)
                printf("Item encontrado!\n");
            else
                printf("ERRO: nao foi possivel encontrar o chave!\n");
            break;
        case 3:
            printf("Encerrando programa...\n");
            exit(0);
            break;
        default:
            break;
        }
    } while (op != 3);
}