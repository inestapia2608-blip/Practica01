#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, n, sig;
	float x, sen, fac;

	printf("Ingrese el valor de x en radianes: ");
	scanf("%f", &x);
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	for(i=0, fac=x, sen=0; i<n; i++)
	{
		sig= i%2? -1.0:1.0;
		sen+= (sig*fac);
		fac*= (x/(2*i+2))*(x/(2*i+3));
	}
	printf("sin(%f) = %f\n", x, sen);
	return 0;
}