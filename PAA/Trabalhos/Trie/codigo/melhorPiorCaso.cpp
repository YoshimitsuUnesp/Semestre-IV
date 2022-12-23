int menor(int vetor[], int n){
  int menor = INT_MAX;  // 1
  for(int i = 0; i < n; i++){ // n
    if (vetor[i] < menor){ // 1
      menor = vetor[i]; // 1
    }
  }
  
  if(menor < 0){ // 1
    for(int i = 0; i < n; i++){ // n
      for(int j = 0; j < n; j++){ // n
        vetor[i] = vetor[i]^(i+j); // 1
      }
    }
  }
  return menor; // 1
}
