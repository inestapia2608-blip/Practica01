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
long double factorial(long double fac){
	int i, k, j; 
	long double res; 
	res=1;
	for (i=1; i<=fac; i++){
		res= res*i;
	}
	return res;
	
}
long double absoluto(long double x) {
    return (x < 0) ? -x : x;
}

long double absoluto(long double x);
long double potencia(long double base, long double exponente);
long double factorial(long double fac);

int main(int argc, char*argv[]){
	
	int n, i, k, j;
	long double num, den, res, sum, errorf;
	long double error[8];
	long double x[3];
	k=0;

	
	while(k<3){
		
        printf("Valor de x: (x < pi/2)\n");
        scanf("%Lf", &x[k]);
		k++;
	}
	
	k=0;
	
	while (k<3){
		
		errorf=0;
		printf("\n# de terminos\t  Valor de x\t Valor aproximado\t Error relativo aproximado\n");
		
		for (j=0; j<9; j++){
			n= potencia(2, j);
			sum = 0;
			
			for (i=0; i<=n; i++){
	 	
			 	num= potencia(x[k], 2*i+1);
			 	den = factorial((2*i+1));
			 	res= num/den;
			 
			 	sum = sum+res;
	 	
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
	
	

