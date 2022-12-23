void pesquisa(std::vector<int> vetor, int valor)
{
  if (vetor.size() <= 1)
  {
    std::cout << "Fim da lista" << std::endl;
  }else{
    for(int i = 0; i < vector.size(); i++)
    {
      if(vector[i] == valor){
        std::cout << "Valor encontrado em " << i << std::endl;
        return;
      }
    }
    pesquisa(vector.slice(0, vector.size()/2));
  }
}
