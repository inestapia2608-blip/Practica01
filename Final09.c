#include <stdio.h>

//Algoritmo para obtener (x+x^2)*e^x, mediante su serie definida
double potencia(double base, int exponente){
	int i;
	double res; 
	res=1;
	
	for (i=0; i<exponente; i++){
		res = res*base;
	}
	return res;
}
	
double potencia(double base, int exponente);
int main(int argc, char *argv[]){
	int k, i, n, j;
	long double factorial, div, res, coef, pro, num, den, errorf;
	long double error[8];
	long double x[3];
	k=0;
	
	while(k<3){
		printf("Ingrese el valor de x: \n");
		scanf("%Lf", &x[k]);
		k++;
	}
	
	k=0;
	while (k<3){
		errorf=0;
		
		printf("\n# de terminos\t Valor de x\t Valor aproximado\t Error relativo aproximado\n");
		
		for (j=1; j<9; j++){
		n= potencia(2, j);
		
		for(i=0, coef=0, pro=1, num=1, den=1, res=0; i<n; i++){
		coef = coef+(2*i)+1;
		pro = pro*x[k];
		num= coef*pro;
		
		den = den*(i+1);
		
		div = num/den;
		res = res + div;
		
		
	
		}
		
		error[j-1] = res;
		if (j==1){
			errorf= (res/(res<0? -1*res:res))*100;
		}else{
			errorf= (res-error[j-2])/(res<1? -1*res:res)*100;
		}
		
		printf("%d\t\t %Lf\t %Lf\t\t %Lf%%\n", n, x[k], res, errorf);
	}
		
		k++;
	}
}
