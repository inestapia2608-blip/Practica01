#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	float ln, div, sig;
	double  i;
	do{
		printf("Ingresa el numero de terminos\n");
		scanf("%d",&n);
	}while(n<1);

	for(i=0, ln=0; i<n; i++)
	{
		sig = (int)i%2? -1.0:1.0;
		div =(1.0/(i+1));
		// printf("%f\n", div); (comprobación términos n)//
		ln +=sig*div;

	}
	printf("el ln(2)= %f\n", ln);

	return 0;
}