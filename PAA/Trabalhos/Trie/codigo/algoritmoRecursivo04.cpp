/**
 * Busca binaria
 * x - Valor procurado
 * vetor - Vetor onde procurar
 * esq - Limite inferior do vetor
 * dir - Limite superior do vetor
 * return -1 se item nao encontrado ou a localizacao do item
 */
int binSearch(int x, std::vector<int> vetor, int esq, int dir)
{
	int meio = (esq + dir) / 2;
	
	if(esq > dir){
		return -1; // Item nao encontrado
	}

	if(x == vetor[meio]) return meio;
	
	if(x < vetor[meio]) 
		return binSearch(x, vetor, esq, meio-1);
	else 
		return binSearch(x, vetor, meio+1, dir);
}