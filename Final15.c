#include <stdio.h>

//Algoritmo para obtener a^x, mediante su serie definida
double potencia(double base, int exponente){
	int i;
	double res; 
	res=1;
	
	for (i=0; i<exponente; i++){
		res = res*base;
	}
	return res;
}


double logaritmo(double a){
	int n, i, den;
	float z;
	double num, div, resfinal, res;
	n=100;
	
	z = (float)((a-1)/(a+1));
	
	for(i=0, num=(1/z), den = 0, res = 0; i<n; i++){
		num = num*z*z;
		
		den = (2*i)+1;
		
		div= num/den;
		res= res + div;
		
	}
	resfinal = 2*res;
	return resfinal;
	
	
}
	
double potencia(double base, int exponente);
double logaritmo(double a);

int main(int argc, char *argv[]){
	int i, n, j, k;
	double base;
	long double res, num, den , div, errorf;
	long double error[8];
	double x[3];
	double a[3];
	
	k=0;
	
	while(k<3){
		do{
		printf("Ingrese el valor de a (a>0): \n");
		scanf("%lf", &a[k]);
		}while(a[k]<=0);
		
		do{
		printf("Ingrese el valor de x (x*ln(a))<=20\n");
		scanf("%lf", &x[k]);
		}while((x[k]*logaritmo(a[k])) > 20);
		
		k++;
	}
	
	k=0;
	
	while (k<3){
		errorf=0;
		i=1;
		res=1.0;
		base= logaritmo(a[k])*x[k];
		num = 1.0;
		den = 1.0;
		
		printf("\n# de terminos\t Valor de a\t Valor de x\t Valor aproximado\t Error relativo aproximado\n");
		
		for (j=1; j<9; j++){
		n= potencia(2, j);
	
		while (i<=n){
		num= base*num;
		den= den*i;
		div= num/den;
		res+= div;
		i++;
		}
		
		error[j-1] = res;
		if (j==1){
			errorf= 100;
		}else{
			errorf= (res-error[j-2])/(res<0? -1*res:res)*100;
		}
		
		printf("%-12d\t %-12.6lf\t %-12.6lf\t %-20.10Lf\t %-20.10Lf%%\n", n, a[k], x[k], res, errorf);
		}
		k++;
	}
		
		
	} 

