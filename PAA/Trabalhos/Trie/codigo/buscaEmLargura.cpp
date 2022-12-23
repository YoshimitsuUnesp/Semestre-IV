void buscaEmLargura(grafo* G, int item)
{
	// Cria fila vazia
	std::queue<vertice*> fila; // Theta(1)
	
	// Marca o primeiro como visitado
	G->listaDeAdjacencias[item].visitado = true; // Theta(1)
	
	// Enfileira
	fila.push(&G->listaDeAdjacencias[item]); // Theta(1)
	
	// Enquanto a fila nao esta vazia -> Theta(V(G)) ja que cada vertice eh enfileirado apenas UMA vez
	while (!fila.empty()) {
		
		// Desinfileira
		auto u = fila.front();
		fila.pop();
		
		// Para todo vertice vizinho de u -> Para percorrer todos os elementos das listas de adjacencias gasta-se O(A)
		auto vizinho = u->adjacente;
		while (vizinho) {
			if (G->listaDeAdjacencias[vizinho->rotulo].folha || vizinho->folha)
			break;
			if (!G->listaDeAdjacencias[vizinho->rotulo].visitado) {
				
				// Adiciona na fila
				fila.push(&G->listaDeAdjacencias[vizinho->rotulo]);
				
				// Marca como visitado -> O(V(G)) pelos motivos acima
				G->listaDeAdjacencias[vizinho->rotulo].visitado = true;
				
				// Exibe -> O(V(G)) pelos motivos acima
				std::cout << " -> " << vizinho->rotulo << std::flush;
			}
			vizinho = vizinho->adjacente;
		}
	}
}