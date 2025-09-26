#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	double x, ath=0.0, ex, cu,i;

	do{
		printf("Ingrese el valor de x (|x|<1) en radianes: ");
		scanf("%lf", &x);
	}while (x<=-1||x>=1);
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	cu=x*x;
	ex=x;
	for(i=0; i<n; i++){
		ath+=ex/((2*i)+1);
		ex*=cu;
	}
		
	printf("arctanh(%lf)=%lf", x, ath);

	return 0;
}