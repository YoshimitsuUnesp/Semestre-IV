void insertionSort(int vetor[], int tamanho) {
	for (int i = 1; i < tamanho; i++) {
		int key = vetor[i];
		int j = i - 1;
		while (key < vetor[j] && j >= 0) {
			vetor[j + 1] = vetor[j];
			- -j;
		}
		vetor[j + 1] = key;
	}
}