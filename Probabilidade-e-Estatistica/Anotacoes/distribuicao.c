#include <stdio.h>
#include <math.h>

int main(){
    int x, lambda, i, fat;
    float res;

    printf("\tModelo de Poisson\n");
    printf("Digite o P(x) (numero de sucesso esperado):\n");
    scanf("%d", &x);
    printf("Digite o valor de lambda (media de sucessos):\n");
    scanf("%d", &lambda);

    fat = x;

    for (i = 1; fat > 1; fat--)
        i = i * fat;

    res = (float) (pow(lambda, x) * pow(M_E, -lambda))/i;

    printf("Resultado: %f", res);
    
    return 0;
}