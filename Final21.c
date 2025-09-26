#include <stdio.h>
#define NMAX 260

long double B[NMAX];  

long double absoluto(long double x) {
    return (x < 0) ? -x : x;
}
long double factorial(long double fac){
    int i; 
    long double res = 1;
    for (i = 1; i <= fac; i++){
        res *= i;
    }
    return res;
}

long double binom(int n, int k) {
    long double rbi = 1;
    for (int i = 1; i <= k; i++) {
        rbi = rbi * (n - i + 1) / i;
    }
    return rbi;
}

void calcular_bernoulli(int n){
    int i, k;
    B[0] = 1;
    for (k = 1; k <= n; k++) {
        long double sum = 0.0;
        for (i = 0; i < k; i++) {
            sum += binom(k, i) * B[i] / (k + 1.0 - i);
        }
        B[k] = -sum;
    }
}

long double potencia(long double base, long double exponente){
    int i;
    long double res = 1;
    for (i = 0; i < exponente; i++){
        res *= base;
    }
    return res;
}

int main(int argc, char*argv[]){
    int i, valorb, ev, n, k, j, r;
    long double lim, com, ki, res, num, den, sum, pot, fc, errorf;
    long double error[8];
	long double x[3];
   
    
    k=0;
	
	while(k<3){
		do {
        printf("Valor de x: (x < pi/2)\n");
        scanf("%Lf", &x[k]);
    	} while (x[k] > (3.141592653589793238 / 2));
		
		k++;
	}
	
	k=0;

    while(k<3){
    	errorf=0;
		i=1;
    	sum = 0;
    	res = 1;
    	
    	
    	printf("\n# de terminos\t  Valor de x\t Valor aproximado\t Error relativo aproximado\n");
    	
    	for(j=0; j<8; j++){
    	n= potencia(2, j);
    	
    	
		calcular_bernoulli(n * 2);  
		while (i <= n){
        ev = i * 2;
        fc = potencia(-4, i);
        num = B[ev] * fc * (1 - potencia(4, i));
        den = factorial(ev);
        pot = ev - 1;
        res = (num / den) * potencia(x[k], pot);
        sum += res;
        i++;
    	}
    	
		if (j == 0) {
		errorf = 100;  
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


