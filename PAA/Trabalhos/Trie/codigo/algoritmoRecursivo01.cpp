int fatorial(int n)
{
	int resp = 0;
	if(n == 0){ // <-- Caso base
		resp = 1; // <-- Caso base
	}else{
		resp = n * fatorial(n-1); // <-- Caso indutivo
	}
	return resp;
}