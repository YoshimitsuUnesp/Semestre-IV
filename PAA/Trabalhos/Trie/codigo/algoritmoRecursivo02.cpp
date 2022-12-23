int fibonacci(int n){
	int res = 0;
	if(n == 1 || n == 2){ // <-- caso base
		res = 1; // <-- caso base
	}else{
		res = fibonacci(n-1) + fibonacci(n-2); // <-- casos indutivos
	}
	return res;
}