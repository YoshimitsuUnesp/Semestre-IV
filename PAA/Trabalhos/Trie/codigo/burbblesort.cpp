#include <iostream>
#include <vector>

void burbbleSort(int vetor[], const int tamanho){
    int temp;
    for (int j = 0; j < tamanho-1; ++j) {
        for (int i = 0; i < tamanho-j-1; ++i) {
            if(vetor[i] > vetor[i+1]){
                temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
            }
        }
    }
}
int main()
{
    std::vector<int> teste = {20,45,63,10,2,5,9,5,90,101,104,1004};
    burbbleSort(teste);
    for(auto item : teste) std::cout << item<< std::endl;
}
