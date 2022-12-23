void shellSort(int vetor[], int tamanho)
{
	// ATENCAO: A escolha das particoes eh arbitraria
	// existem diferentes tempos de algoritmo para diferentes
	// tamanhos de particao.
	for (int particao = tamanho/2; particao > 0; particao /= 2)
	{
		// Faz o insertion-sort na particao
		for (int i = particao; i < tamanho; i += 1)
		{
			int temp = vetor[i];
			int j;
			for (j = i; j >= particao && vetor[j - particao] > temp; j -= particao)
			vetor[j] = vetor[j - particao];
			vetor[j] = temp;
		}
	}
}