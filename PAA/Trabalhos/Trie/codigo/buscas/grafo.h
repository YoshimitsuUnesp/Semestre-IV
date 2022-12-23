#ifndef GRAFO_H
#define GRAFO_H

#include <vector>

typedef struct vertice{
    int rotulo;
    bool folha = true;
    bool visitado = false;
    struct vertice *adjacente = nullptr;
} vertice;

typedef struct {
    int qtdeDeVertices;
    int qtdeDearestas;
    std::vector<vertice> listaDeAdjacencias;
} grafo;

grafo* criaGrafo(int n, int m);
void adicionaAresta(grafo *G, int u, int v);
void imprimeGrafo(grafo *G);
void deletaGrafo(grafo *G);

int grauVertice(grafo *G, int u);
int grauMaximo(grafo* G);

vertice* recuperaVizinhos(grafo* G, int u);
void buscaEmLargura(grafo* G, int u);

#endif // GRAFO_H
