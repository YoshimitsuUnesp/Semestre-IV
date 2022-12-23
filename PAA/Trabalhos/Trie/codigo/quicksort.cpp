int particionar(int vetor[], int menor, int maior, int valorDoPivo){
	int indiceDoPivo = menor;
	for(int i=menor;i<=maior;i++) {
		if(vetor[i]<=valorDoPivo) {
			std::swap(vetor[indiceDoPivo],vetor[i]);
			indiceDoPivo++;
		}
	}
	indiceDoPivo--;
	return indiceDoPivo;
}
void quickSort(int vetor[], int menor, int maior){
	if(menor < maior) {
		int valorDoPivo = vetor[maior];
		int indiceDoPivo = particionar(vetor, menor, maior, valorDoPivo);
		quickSort(vetor, menor, indiceDoPivo-1);
		quickSort(vetor, indiceDoPivo+1, maior);
	}
}