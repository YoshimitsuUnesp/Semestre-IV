#include <bits/stdc++.h>

#include <iostream>
#include <vector>

#include "grafo.h"

void burbbleSort(int vetor[], const int tamanho)
{
    int temp;
    for (int j = 0; j < tamanho - 1; ++j) {
        for (int i = 0; i < tamanho - j - 1; ++i) {
            if (vetor[i] > vetor[i + 1]) {
                temp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;
            }
        }
    }
}

int particionar(int vetor[], int menor, int maior, int valorDoPivo)
{
    int indiceDoPivo = menor;

    for (int i = menor; i <= maior; i++) {
        if (vetor[i] <= valorDoPivo) {
            std::swap(vetor[indiceDoPivo], vetor[i]);
            indiceDoPivo++;
        }
    }
    indiceDoPivo--;
    return indiceDoPivo;
}

void quickSort(int vetor[], int menor, int maior)
{
    if (menor < maior) {
        int valorDoPivo = vetor[maior];
        int indiceDoPivo = particionar(vetor, menor, maior, valorDoPivo);
        quickSort(vetor, menor, indiceDoPivo - 1);
        quickSort(vetor, indiceDoPivo + 1, maior);
    }
}

void insertionSort(int vetor[], int tamanho)
{
    for (int i = 1; i < tamanho; i++) {
        int key = vetor[i];
        int j = i - 1;
        while (key < vetor[j] && j >= 0) {
            vetor[j + 1] = vetor[j];
            --j;
        }
        vetor[j + 1] = key;
    }
}

void shellSort(int vetor[], int tamanho)
{
    // ATENCAO: A escolha das particoes eh arbitraria
    // existem diferentes tempos de algoritmo para diferentes
    // tamanhos de particao.
    for (int particao = tamanho / 2; particao > 0; particao /= 2) {
        // Faz o insertion-sort na particao
        for (int i = particao; i < tamanho; i += 1) {
            int temp = vetor[i];
            int j;
            for (j = i; j >= particao && vetor[j - particao] > temp; j -= particao)
                vetor[j] = vetor[j - particao];
            vetor[j] = temp;
        }
    }
}

void selectionSort(int vetor[], int tamanho)
{
    int i, j, menor, index;
    for (int i = 0; i < tamanho - 1; ++i) {
        menor = vetor[i];
        index = i;
        for (int j = i + 1; j < tamanho; ++j) {
            if (vetor[j] < menor) {
                menor = vetor[j];
                index = j;
            }
        }
        vetor[index] = vetor[i];
        vetor[i] = menor;
    }
}

void genRandom(int vetor[], int tamanho, int max)
{
    for (int i = 0; i < tamanho; i++)
        vetor[i] = rand() % max;
}

void heapify(int vetor[], int tamanho, int posicao)
{
    int posicaoMaior = posicao; // Initialize largest as root
    int filheEsquerda = 2 * posicao + 1; // left = 2*i + 1
    int filheDireita = 2 * posicao + 2; // right = 2*i + 2

    if (filheEsquerda < tamanho && vetor[filheEsquerda] > vetor[posicaoMaior])
        posicaoMaior = filheEsquerda;

    if (filheDireita < tamanho && vetor[filheDireita] > vetor[posicaoMaior])
        posicaoMaior = filheDireita;

    if (posicaoMaior != posicao) {
        std::swap(vetor[posicao], vetor[posicaoMaior]);
        heapify(vetor, tamanho, posicaoMaior);
    }
}

void heapSort(int vetor[], int tamanho)
{
    // Monta o heap
    for (int posicao = tamanho / 2 - 1; posicao >= 0; posicao--)
        heapify(vetor, tamanho, posicao);

    // Ordena o vetor
    for (int i = tamanho - 1; i >= 0; i--) {
        // Move a raiz para o final
        std::swap(vetor[0], vetor[i]);

        // Arruma a arvore
        heapify(vetor, i, 0);
    }
}

// Merge two subarrays L and M into arr
// void merge(int vetor[], int const esquerda, int const meio, int const
// direita)
void merge(int arr[], int p, int q, int r)
{
    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int vetor[], int const inicio, int const fim)
{
    if (inicio >= fim)
        return; // Caso base
    int meio = inicio + (fim - inicio) / 2; // Determina a metade do vetor
    mergeSort(vetor, inicio, meio); // Processa a primeira metade
    mergeSort(vetor, meio + 1, fim); // Processa a segunda metade
    merge(vetor, inicio, meio, fim); // Combina as metades ordenadas
}

int rodarGrafo()
{
    int n, m;
    int u, v;
    grafo* G;

    scanf("%d %d", &n, &m);
    G = criaGrafo(n, m);

    while (m--) {
        scanf("%d %d", &u, &v);
        adicionaAresta(G, u, v);
    }

    std::cout << grauVertice(G, 0) << std::endl;
    imprimeGrafo(G);
    deletaGrafo(G);
    return 0;
}

void rodaOrdenadores()
{
    const int tamanho = 100;
    int teste[tamanho];
    time_t start, end;
    double time_taken;

    genRandom(teste, tamanho, tamanho);

    time(&start);
    mergeSort(teste, 0, tamanho - 1);
    time(&end);
    time_taken = double(end - start);
    std::cout << "Time taken by program is : " << std::fixed << time_taken
              << std::setprecision(5);
    heapSort(teste, tamanho);
    selectionSort(teste, tamanho);
    shellSort(teste, tamanho);
    burbbleSort(teste, tamanho);
    quickSort(teste, 0, tamanho);
    insertionSort(teste, tamanho);
    for (auto item : teste) {
        std::cout << item << std::endl;
    }
}

int main()
{
    // rodaOrdenadores();
    // rodarGrafo();
    int n, m;
    int u, v;
    grafo* G;

    scanf("%d %d", &n, &m);
    G = criaGrafo(n, m);

    while (m--) {
        scanf("%d %d", &u, &v);
        adicionaAresta(G, u, v);
    }

    imprimeGrafo(G);
    buscaEmLargura(G, 0);
}
