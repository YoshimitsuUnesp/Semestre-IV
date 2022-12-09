#include <stdio.h>
#include <stdlib.h>
typedef struct No
{
    int valor;
    struct No *proximo;
} No;
typedef struct
{
    No *inicio;
    int tam;
} Lista;

void criar_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}

void inicio(Lista *lista, int num)
{
    No *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else
        printf("Erro de memoria!\n");
}

void fim(Lista *lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;
        if (lista->inicio == NULL)
            lista->inicio = novo;
        else
        {
            aux = lista->inicio;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro de memoria!\n");
}

void meio(Lista *lista, int num, int anterior)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->valor = num;
        if (lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            while (aux->valor != anterior && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro memoria!\n");
}

void listar(Lista lista){
    No *no = lista.inicio;
    printf("\n\tLista tamanho %d: \n", lista.tam);
    printf("\t");
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

No* remover(Lista *lista, int valor){
    No *aux, *remover = NULL;
    if(lista->inicio){
        if(lista->inicio->valor == valor){
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tam--;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->valor != valor)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->tam--;
            }
        }
    }
    return remover;
}


int main()
{
    int opcao, valor, anterior;
    Lista lista;
    No *noRemovido;
    criar_lista(&lista);
    do
    {
        printf("\n\t0 - Sair\n\t1 - Inicio \n\t2 - Fim\n\t3 - Meio\n\t4 - Lista\n\t5 - Remover\n");
        scanf("%d", &opcao);
        system("clear"); // system("cls") para windows
        switch (opcao)
        {
        case 1:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            inicio(&lista, valor);
            break;
        case 2:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            fim(&lista, valor);
            break;
        case 3:
            printf("Digite o valor e a posicao anterior: ");
            scanf("%d%d", &valor, &anterior);
            meio(&lista, valor, anterior);
            break;
        case 4:
            listar(lista);
            break;
        case 5:
            printf("Digite o valor do item a ser removido: ");
            scanf("%d", &valor);
            noRemovido = remover(&lista, valor);
            if (noRemovido)
            {
                printf("Valor %d removido com sucesso!", noRemovido->valor);
                free(noRemovido);
            }
            else
                printf("Valor inexistente!\n");
        default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
