void selectionSort(int vetor[], int tamanho)
{
	int i, j, menor, index;
	for (int i = 0; i < tamanho -1 ; ++i) {
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