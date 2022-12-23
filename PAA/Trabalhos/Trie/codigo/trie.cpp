#include "trie.h"
#include <stdexcept>

Trie::Trie(unsigned alphabetSize)
: amountOfKeysStored(0)
{
	TrieNode::alphabetSize = alphabetSize;
}

bool Trie::search(const std::string key)
{
	
	/* Nao sao permitidas buscas nulas */
	if (key.empty())
	throw std::invalid_argument("The string must have some chars");
	
	/* chama o metodo recursivo get que fara a busca na arvore */
	TrieNode* x = get(trieRoot, key, 0);
	
	/* Chave nao encontrada */
	if (x == nullptr)
	return false;
	
	/* se isLeaf == true entao a chave foi encontrada */
	return true;
}

TrieNode* Trie::get(TrieNode* x, const std::string key, int trieLevel)
{
	/* No nulo a chave nao se encontra na arvore */
	if (x == nullptr)
	return nullptr;
	
	/*
	* Se a profundidade da arvore (trieLevel) for igual a quantidade de caracteres
	* (key.length()) entao a chave tem um cadidato a "hit" se este no for uma folha
	* (isLeaf == true) entao se tem um "hit" se nao se tem um "miss"
	*/
	if (trieLevel == key.length()) {
		if (x->isLeaf)
		return x;
		else
		return nullptr;
	}
	
	/*
	* Elemento nao encontrado, recupera o proximo caractere e reinicia as
	* verificacoes com uma chamada recursiva
	*/
	char c = key[trieLevel];
	return get(x->arrSubTries[c], key, trieLevel + 1);
}

void Trie::insert(const std::string key)
{
	/* Nao sao permitidas insercoes nulas */
	if (key.empty())
	throw std::invalid_argument("The string must have some chars");
	
	/* chama o metodo recursivo get que fara a insercao na arvore */
	trieRoot = add(trieRoot, key, 0);
}

TrieNode* Trie::add(TrieNode* x, const std::string key, int trieLevel)
{
	/*
	* Se o no e nulo entao a chave completa nao esta na arvore, e necessario criar
	* um novo no para alocar tal caractere, perceba que este no deve ser do tamanho
	* do alfabeto adotado
	*/
	if (x == nullptr) {
		x = new TrieNode();
		x->setAlphabetSize(TrieNode::alphabetSize);
	}
	
	/*
	* Se a profundidade da arvore (trieLevel) for igual a quantidade de caracteres
	* (key.length()) entao a chave esta completa dentro da arvore;
	*/
	if (trieLevel == key.length()) {
		
		/*
		* Ha que se verificar se a chave encontrada NAO e uma folha. Caso NAO seja
		* incrementa o indicador de quantidade de chaves armazenadas
		*/
		if (!x->isLeaf) {
			this->amountOfKeysStored++;
		}
		
		/* Marca como folha */
		x->isLeaf = true;
		
		/* Retorna a folha inserida */
		return x;
	}
	
	/*
	* Se a profundidade da arvore (trieLevel) ainda nao for igual a quantidade de
	* caracteres (key.length()) entao prepara uma chamada recursiva para
	* verficacao/criacao de um novo no
	*/
	char c = key[trieLevel];
	x->arrSubTries[c] = add(x->arrSubTries[c], key, trieLevel + 1);
	
	/* Retorna a folha inserida */
	return x;
}

void Trie::deleteNode(const std::string key)
{
	
	/* Nao sao permitidas insercoes nulas */
	if (key.empty())
		throw std::invalid_argument("The string must have some chars");
	
	/* chama o metodo recursivo get que fara a remocao na arvore */
	trieRoot = deleteNode(trieRoot, key, 0);
}

TrieNode* Trie::deleteNode(TrieNode* x, std::string key, int trieLevel)
{
	
	/* No nulo a chave nao se encontra na arvore */
	if (x == nullptr)
	return nullptr;
	
	/*
	* Se a profundidade da arvore (trieLevel) for igual a quantidade de caracteres
	* (key.length()) entao a chave tem um cadidato a remocao.
	*/
	if (trieLevel == key.length()) {
		/*
		* Se este no for uma folha (isLeaf == true) entao o no e desmarcado como
		* folha e a contagem de item da trie e decrementada
		*/
		if (x->isLeaf)
		amountOfKeysStored--;
		
		x->isLeaf = false;
	} else {
		
		/*
		* Se a profundidade da arvore (trieLevel) ainda nao for igual a quantidade de
		* caracteres (key.length()) entao prepara uma chamada recursiva para
		* verficacao/remocao de proximo no
		*/
		char c = key[trieLevel];
		x->arrSubTries[c] = deleteNode(x->arrSubTries[c], key, trieLevel + 1);
	}
	
	/*
	* Na volta das chamadas recursivas, no momento em que uma folha for encontrada a
	* delecao da arvore e terminada retornando-se um no valido
	*/
	if (x->isLeaf)
	return x;
	
	/*
	* Se o no nao e valido, anula todos os nos abaixo deste e, em seguinda, retorna
	* um endereco nulo para o nivel acima
	*/
	for (int i = 0; i < TrieNode::alphabetSize; i++)
	if (x->arrSubTries[i] != nullptr)
	return x;
	
	delete x;
	return nullptr;
}
