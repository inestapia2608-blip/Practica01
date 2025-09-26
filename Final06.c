#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	double div, sum, i;
	do{
		printf("Ingresa el numero de terminos: ");
		scanf("%d",&n);
	}while(n<1);

	for(i=1, sum=0; i<=n; i++){
		div =(1.0/(i*(i+2)));
		sum +=div;
	}
	printf("el 3/4= %lf\n", sum);

return 0;
}