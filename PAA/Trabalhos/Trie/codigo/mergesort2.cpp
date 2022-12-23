void merge(int vetor[], int const esquerda, int const meio, int const direita){
	int const tamanhoVetor1 = meio - esquerda + 1;
	int const tamanhoVetor2 = direita - meio;
	int *vetorEsquerdo = new int[tamanhoVetor1];
	int *vetorDireito = new int[tamanhoVetor2];
	for (int i = 0; i < tamanhoVetor1; i++) vetorEsquerdo[i] = vetor[esquerda + i];
	for (int j = 0; j < tamanhoVetor2; j++) vetorDireito[j] = vetor[meio + 1 + j];
	int posicaoVetor1 = 0;
	int posicaoVetor2 = 0;
	int posicaoVetorMesclado = esquerda;
	while (posicaoVetor1 < tamanhoVetor1 && posicaoVetor2 < tamanhoVetor2) {
		if (vetorEsquerdo[posicaoVetor1] <= vetorDireito[posicaoVetor2]) {
			vetor[posicaoVetorMesclado] = vetorEsquerdo[posicaoVetor1];
			posicaoVetor1++;
		} else {
			vetor[posicaoVetorMesclado] = vetorDireito[posicaoVetor2];
			posicaoVetor2++;
		}
		posicaoVetorMesclado++;
	}
	while (posicaoVetor1 < tamanhoVetor1) { // Copia os elementos restantes do esquerdo
		vetor[posicaoVetorMesclado] = vetorEsquerdo[posicaoVetor1];
		posicaoVetor1++;
		posicaoVetorMesclado++;
	}
	while (posicaoVetor2 < tamanhoVetor2) { // Copia os elementos restantes do direito
		vetor[posicaoVetorMesclado] = vetorDireito[posicaoVetor2];
		posicaoVetor2++;
		posicaoVetorMesclado++;
	}
	delete[] vetorEsquerdo;
	delete[] vetorDireito;
}