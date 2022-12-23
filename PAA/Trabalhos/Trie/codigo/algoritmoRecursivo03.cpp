int uga(int n){
	int res = 0;
	if(n == ){ // <-- caso base
		res = 1; // <-- caso base
	}else{
		res = uga(n/2) + uga(n/2); // <-- casos indutivos
	}
	for(int i = 0; i < n; i++){
		int z = res + 1;
	}
	return res;
}