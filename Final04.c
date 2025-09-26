#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	float div, pi;
	double i;
	do{
		printf("Ingresa el numero de terminos: ");
		scanf("%d",&n);
	}while(n<1);

	for(i=0, pi=0; i<=n; i++){
		div =(1.0/((2*i+1)*(2*i+1)));
		pi +=div;
	}
	printf("el pi^2/8= %f\n", pi);
	return 0;
}