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