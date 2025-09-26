#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, i;
	float x, ln, num, sig;
	do{
		printf("Ingrese x (-1<=x <1): ");
		scanf("%f",&x);
	}while(x<=-1 || x>1);
	do{
		printf("Ingrese el numero de terminos (n): ");
		scanf("%d",&n);
	}while(n<1);
	i=0; 
	ln=0;
	num=1;
	while(i<n)
	{
		sig = i%2? -1.0:1.0;
		num*=x;
		ln+=(sig*(num/(i+1)));
		i++;
	}
	printf("el ln(1+%f)=%f", x, ln);
	return 0;
}