#include <stdio.h>

int menuPrincipal(int op)
{
    printf(
        "| ---------------- |/n",
        "|  MENU PRINCIPAL  |/n",
        "| 1 - Comprimir    |/n",
        "| 2 - Descomprimir |/n",
        "| 3 - Sair         |/n",
        "| ---------------- |/n");
    printf("Escolha uma opcao (1-3):\n");

    return op;
}
