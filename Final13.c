#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	float x, frac, ln, ex, a;
	double i;
	do{
		printf("Ingrese x (x>=0.5): ");
		scanf("%f", &x);
	}while(x<=0.5);

	do{
		printf("Ingrese el numero de terminos (n): ");
		scanf("%d", &n);
	}while(n<1);

	ex=(x-1.0)/x;
	i=0;
	ln=0;
	a=1;
	while(i<n)
	{
		a*=ex;
		ln+=a/(i+1.0);
		i++;
	}
	printf("El ln(%f)=%f ", x, ln);
	return 0;
}