void mergeSort(int vetor[], int const inicio, int const fim)
{
	if (inicio >= fim) return; // Caso base
	int meio = inicio + (fim - inicio) / 2; // Determina a metade do vetor
	mergeSort(vetor, inicio, meio); // Processa a primeira metade
	mergeSort(vetor, meio + 1, fim); // Processa a segunda metade
	merge(vetor, inicio, meio, fim); // Combina as metades ordenadas
}