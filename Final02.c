#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, i;
	float pi, div, sig;
	do{
		printf("Ingresa el numero de terminos:");
		scanf("%d",&n);
	}while(n<1);

	for(i=0, pi=0; i<n; i++){
		sig = i%2? -1.0:1.0;
		div =(1.0/(2*i+1));
		pi +=sig*div;
	}
	printf("pi/4= %f con %d terminos", pi, n);
	return 0;
}