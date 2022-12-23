void emOrdem(node* vertice) {
	if (vertice == NULL) return;
	emOrdem(vertice->esquerda);
	printf("%f\n", *vertice->valor);
	emOrdem(vertice->direita);
}

void preOrdem(node* vertice) {
	if (vertice == NULL) return;
	printf("%f\n", *vertice->valor);
	preOrdem(vertice->esquerda);
	preOrdem(vertice->direita);
}

void posOrdem(node* vertice) {
	if (vertice == NULL) return;
	posOrdem(vertice->esquerda);
	posOrdem(vertice->direita);
	printf("%f\n", *vertice->valor);
}