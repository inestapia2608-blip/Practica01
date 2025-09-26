#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, j;
	float div, sum;
	double i;
	do{
		printf("Ingresa el numero de terminos: ");
		scanf("%d",&n);
	}while(n<1);
	for(i=1, j=0, sum=0; i&&j<=n; i++, j++){
		div =(1.0/((2*j+1)*(2*i+1)));
		sum +=div;
	}
	printf("el 1/2= %f\n", sum);

return 0;
}