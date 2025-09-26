#include <stdio.h>

long long factorial(int n) {
    long long f = 1;
    int i;
    for (i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main(int argc, char *argv[])
{
	int n, i, k, j;
    float x, sec=0.0, term, pot, fac;
	long long E[] = {1, -1, 5, -61, 1385, -50521};
	do{
    printf("Ingrese el valor de x en radianes:");
    scanf("%f", &x);
	}while(x>(3.14159265359/2));
	do{
		printf("Ingres el numero de terminos (n<1||n>6): ");
		scanf("%d", &n);
	}while(n<1||n>6);

for (i=0; i<n; i++) {
    k=2*i;
    fac=factorial(k);

    pot=1.0;
    for (j=0; j<k; j++) {
        pot*=x;
    }

    term=(i%2==0? 1:-1)*(E[i]*pot)/fac;
    sec+=term;
}
    printf("el sec(%f)=%f \n", x, sec);
	return 0;
}