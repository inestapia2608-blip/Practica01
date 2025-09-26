#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	float div, pi;
	double  i;
	do{
		printf("Ingresa el numero de terminos\n");
		scanf("%d",&n);
	}while(n<1);

	for(i=1, pi=0; i<=n; i++){
		div =(1.0/(i*i));
		pi +=div;
	}
	printf("el pi^2/6= %f\n", pi);
return 0;
}