#include <stdio.h>

#define PI 3.14159265359

int main(int argc, char *argv[])
{
	int n;
	float x, arcsen=0.0, ex, div, cu, arc;
	double mult, ip, i, j;;

	do{
		printf("Ingrese el valor de x (|x|<1) en radianes: ");
		scanf("%f", &x);
	}while (x<=-1||x>=1);
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	cu=x*x;
	ex=x;
	ip=1;
	i=0;
	while(i<n){
		arcsen+=ip*(ex/((2*i)+1));
		mult=((2.0*i)+1.0)/((i+1)*2.0);
		ip*=mult;
		ex*=cu;
		i++;
	}
	
	arc=(PI/2)-arcsen;
	printf("el arccos(%f)=%f", x, arc);

	return 0;
}