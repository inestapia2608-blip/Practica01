#include <stdio.h>

typedef struct {
    long double real;
    long double imaginario;
} complejo;

complejo dividircomplejos(complejo a, complejo b) {
	
	complejo resultado;
    long double denom = b.real*b.real + b.imaginario*b.imaginario;

    resultado.real = (a.real*b.real + a.imaginario*b.imaginario) / denom;
    resultado.imaginario = (a.imaginario*b.real - a.real*b.imaginario) / denom;

    return resultado;
		
	}
	
complejo multiplicarcomplejos(complejo a, complejo b){
	
	complejo resultado;
	
	resultado.real = -1* (a.imaginario*b.imaginario);
	resultado.imaginario = a.real*b.imaginario;
	
	
	return resultado; 
	
	
} 

complejo sumatoriacomplejos(complejo a, complejo b){
	
	complejo sumatoria;
	sumatoria.real= a.real+b.real;
	sumatoria.imaginario= a.imaginario+b.imaginario;
	
	return sumatoria; 
	
}

long double factorial(long double fac){
	int i; 
	long double res; 
	res=1;
	for (i=1; i<=fac; i++){
		res= res*i;
	}
	return res;
	
}

long double potencia(long double base, long double exponente){
	int i;
	long double res; 
	res=1;
	
	for (i=0; i<exponente; i++){
		res = res*base;
	}
	return res;
}
	
complejo dividircomplejos(complejo a, complejo b);
complejo sumatoriacomplejos(complejo a, complejo b);
long double factorial(long double fac);
long double potencia(long double base, long double exponente);
complejo multiplicarcomplejos(complejo a, complejo b);

int main(int argc, char*argv[]){
	
	int j, signo, r, n, l;
	long double m, lim, com, mj, mdosj, resmdosj, division, resfinal, errorf;
	complejo base, potim, divisioncom, sumint, sum, rescomplejo ;
	complejo sumext = {0,0};
	complejo un= {0,1};
	long double error[8];
	long double k[3];
	
	
	r=0;
	
	while(r<3){
		do{
		printf("ingrese el valor de k ( 0<k<100)\n");
		scanf("%Lf", &k[r]);
		}while (k[r]<0||k[r]>100);
		
		r++;
	}
	
	r=0;
	
	while(r<3){
		complejo tabla[4] = {
	    {1, 0},   
	    {0, 1},   
	    {-1, 0}, 
	    {0, -1}   
		};
		lim = 2*k[r]+1;
		
		errorf=0;
		printf("\n# de terminos\t Valor de x\t Valor aproximado\t Error relativo aproximado\n");
		
		for (l=1; l<9; l++){
			n= potencia(2, l);
			complejo sumext = {0, 0};
			
			
		for (m=1; m<=n; m++){
		
		j=0;
		complejo sumint = {0,0};
		potim = tabla[(int)m % 4];
		
		
		
		while (j<=m){
			
			mj= m-j;
			com= factorial(m)/ (factorial(j)*factorial(mj));
			
			
			signo = (j%2) ? -1 : 1;
			
			mdosj = m-(2*j);
			resmdosj= potencia(mdosj, lim);
			
			division= (signo*resmdosj)/(potencia(2,m)*m);
			
			
			base.real = com*division;
			
			
			divisioncom= dividircomplejos(base, potim);
			
			sumint= sumatoriacomplejos(sumint, divisioncom);
		
			
			j++;
		}
		
		sumext = sumatoriacomplejos(sumext, sumint);	
	}
	
		rescomplejo= multiplicarcomplejos(sumext, un);
		resfinal = rescomplejo.real;
		
		error[l-1] = resfinal;
		if (l==1){
			errorf= 100;
		}else{
			errorf= (resfinal-error[l-2])/(resfinal<0? -1*resfinal:resfinal)*100;
		}	
		
		printf("%-12d\t %-12.6Lf\t %-20.10Lf\t %-20.10Lf%%\n", n, k[r], resfinal, errorf);
			}
		r++;
	
	
	
	
}	
}
