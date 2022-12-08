#include "grafo.h"
#include <climits>
#include <iostream>

grafo *criaGrafo(int vertices, int arestas)
{
    grafo *G = new grafo;
    G->qtdeDeVertices = vertices;
    G->qtdeDearestas = arestas;
    G->listaDeAdjacencias.resize(vertices);
    return G;
}

void adicionaAresta(grafo *G, int u, int v)
{
    vertice *ultimo = &G->listaDeAdjacencias[u];

    if (ultimo->folha)
    {
        vertice *novaFolha = new vertice;
        novaFolha->rotulo = -1;
        novaFolha->folha = true;
        novaFolha->adjacente = nullptr;

        ultimo->rotulo = u;
        ultimo->folha = false;
        ultimo->adjacente = novaFolha;
    }

    while (!ultimo->folha)
    {
        if (ultimo->rotulo == v)
            return;
        ultimo = ultimo->adjacente;
    }

    vertice *novaFolha = new vertice;
    novaFolha->rotulo = -1;
    novaFolha->folha = true;
    novaFolha->adjacente = nullptr;

    ultimo->rotulo = v;
    ultimo->folha = false;
    ultimo->adjacente = novaFolha;

    /////////////////----/////////////////////

    ultimo = &G->listaDeAdjacencias[v];

    if (ultimo->folha)
    {
        vertice *novaFolha = new vertice;
        novaFolha->rotulo = -1;
        novaFolha->folha = true;
        novaFolha->adjacente = nullptr;

        ultimo->rotulo = v;
        ultimo->folha = false;
        ultimo->adjacente = novaFolha;
    }

    while (!ultimo->folha)
    {
        if (ultimo->rotulo == u)
            return;
        ultimo = ultimo->adjacente;
    }

    novaFolha = new vertice;
    novaFolha->rotulo = -1;
    novaFolha->folha = true;
    novaFolha->adjacente = nullptr;

    ultimo->rotulo = u;
    ultimo->folha = false;
    ultimo->adjacente = novaFolha;
}

void imprimeGrafo(grafo *G)
{
    for (vertice v : G->listaDeAdjacencias)
    {
        std::cout << v.rotulo << " -> ";

        v = *v.adjacente;

        while (!v.folha)
        {
            std::cout << v.rotulo << " ";
            v = *v.adjacente;
        }
        std::cout << std::endl;
    }
}

void deletaGrafo(grafo *G)
{
    vertice *x, *y;
    for (int indiceDoVertice = 0; indiceDoVertice < G->qtdeDeVertices;
         indiceDoVertice++)
    {
        x = &G->listaDeAdjacencias[indiceDoVertice];
        while (x)
        {
            y = x->adjacente;
            delete x;
            x = nullptr;
            x = y;
        }
    }
    delete G;
}

int grauVertice(grafo *G, int indice)
{
    int grau = 0;

    vertice v = G->listaDeAdjacencias[indice];
    v = *v.adjacente;
    while (!v.folha)
    { // Theta(dg(v) ou O(V(G))
        grau++;
        v = *v.adjacente;
    }
    return grau;
}

int grauMaximo(grafo *G) //
{
    int max = INT_MIN; // Theta(1)
    int temp;          // Theta(1)
    for (auto v : G->listaDeAdjacencias)
    {                                    // Theta(V(G)+dg(G)) ou Theta(V(G)+A(G))
        temp = grauVertice(G, v.rotulo); // O(V(G))
        if (max < temp)
        {               // Theta(1)
            max = temp; // Theta(1)
        }
    }

    return max; // Theta(1)
}

/* Pseudocodigo de busca em largura */
void buscaEmLargura(grafo *G, vertice u){
    /* Passo 1: escolhemos um vertice
    Passo 2: colocamos esse vertice na fila, por ser o primeiro vertice, seu ANTERIOR sera nulo
    Passo 3: adicionamos os vertices adjacentes na fila
    Passo 4: pegamos seu vertice mais antigo, e marcamos ANTERIOR como o vertice escolhido
    Passo 5: pegamos o proximo vertice da fila e fazemos os mesmos passos até que zere a fila
    Passo 6: pegamos os vertices adjacentes do ultimo item da fila
    Passo 7: repetimos os passos 3 a 6 até que acabem todos os vértices conectados entre si*/



}

/* Pseudocodigo de busca em profundidade */
void buscaEmProfundidade(grafo *G, vertice u){
    /* Parecido com o busca em largura, mas ao invés de usar uma fila e pegar o item mais antigo, 
    usa uma pilha e pega o item mais recente*/
    
}