#include <stdio.h>

long double potencia(long double base, long double exponente){
	int i;
	long double res; 
	res=1;
	
	for (i=0; i<exponente; i++){
		res = res*base;
	}
	return res;
}
long double factorial(int n) {
    long double res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

long double coeficiente_arcsin(int n) {
    long double num = factorial(2 * n);
    long double den = potencia(4, n) * potencia(factorial(n), 2) * (2 * n + 1);
    return num / den;
}



long double absoluto(long double x) {
    return (x < 0) ? -x : x;
}

long double absoluto(long double x);
long double potencia(long double base, long double exponente);
int main(int argc, char*argv[]){
	int n, i, pt, k, j;
	long double num, den, div, res, fac, sum, resfinal, errorf;
	
	long double error[8];
	long double x[3];
	
	k=0;
	
	while(k<3){
	 
	 do{
	 	printf ("Introduce el valor de x |x|<1\n");
	 	scanf ("%Lf", &x[k]);
	 }while ( x[k]>=1 || x[k]<=-1);
		
		k++;
	}
	
	k=0;
	
	while (k<3){
		errorf=0;
		fac=1;
		pt=1;
		printf("\n# de terminos\t  Valor de x\t Valor aproximado\t Error relativo aproximado\n");
		
		for (j=0; j<9; j++){
			n= potencia(2, j);
			sum = 0;
			
			for (i=0; i<=n; i++){
				
				num= potencia(x[k], 2*i+1);
			 	den = 2*i+1;
			 	res= num/den;
			 	
			 	if (pt){
			 		fac=1;
			 		pt=0;
				 }else{
				 	fac= fac*((2*i-1)/((double)2*i));
				 }
			 	
			 	resfinal = coeficiente_arcsin(i) * potencia(x[k], 2*i + 1);
			 	sum = sum+resfinal;
	 			}
	
		if (j == 0) {
		errorf = 0;  
		} else {
		    long double anterior = error[j - 1];
		    if (absoluto(anterior) < 1e-12) {
		        errorf = 0;  
		    } else {
		        errorf = absoluto(sum - anterior) / absoluto(anterior) * 100;
		    }
		}
		
    	printf("%-12d\t %-12.6Lf\t %-20.10Lf\t %-20.10Lf%%\n", n, x[k], sum, errorf);
			
		}
		
		
		k++;
	}
	
	 
	 
	 
}
