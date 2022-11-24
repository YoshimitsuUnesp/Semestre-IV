#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "opcoes.h"

#define ASCII 256

int main()
{
    int op;
    unsigned char *texto;
    unsigned int tabela_frequencia[ASCII];
    Lista lista;
    Arvore *arvore;
    int colunas, tam;
    char **dicionario;
    char *codificado, *decodificado;
    char nomeArquivo[100];

    
    printf("Digite o nome do arquivo com a extensao a ser compactado:\n");
    scanf("%s", nomeArquivo);

    tam = tamanhoArquivo(nomeArquivo);

    texto = (unsigned char *)calloc(tam + 2, sizeof(unsigned char));
    leArquivo(nomeArquivo, texto);

    criaTabela(tabela_frequencia);
    prencheTabela(texto, tabela_frequencia);

    criaLista(&lista);
    preencheLista(tabela_frequencia, &lista);
    long fimCabecalho = cabecalho(&lista, nomeArquivo);
    arvore = criaArvore(&lista);

    colunas = alturaArvore(arvore) + 1;
    dicionario = criaDicionario(colunas);
    traduzDicionario(dicionario, arvore, "", colunas);

    codificado = codifica(dicionario, texto);

    decodificado = decodifica(codificado, arvore);

    printf("\n\n");

    // Permanece em loop ate que o usuario deseje sair
    do
    {
        menuPrincipal();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            compacta(codificado, nomeArquivo);
            break;
        case 2:
            descompacta(arvore, fimCabecalho, nomeArquivo);
            break;
        case 3:
            sair();
            break;
        default:
            printf("\nERRO: opcao invalida!\n\n");
            break;
        }
    } while (op != 3);

    free(texto);
    free(codificado);
    free(decodificado);

    return 0;
}