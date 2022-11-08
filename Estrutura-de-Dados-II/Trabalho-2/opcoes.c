#include <stdio.h>
#include <stdlib.h>

void menuPrincipal()
{
    limparTela();
    printf(
        "| ---------------- |/n",
        "|  MENU PRINCIPAL  |/n",
        "| 1 - Comprimir    |/n",
        "| 2 - Descomprimir |/n",
        "| 3 - Sair         |/n",
        "| ---------------- |/n");
    printf("Escolha uma opcao (1-3):\n");
}

void sair(){
    printf("Encerrando programa...\n");
    exit(0);
}

void limparTela(){
    #ifdef _WIN32
    system("cls");
    return;
    #elif __linux__
    system("clear");
    return;
    #elif __APPLE__
    system("clear");
    return;
    #else
    printf("\nQue sistema tu ta usando cara?\n");
    return;
    #endif
}
