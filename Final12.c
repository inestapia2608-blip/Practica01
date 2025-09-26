#include <stdio.h>

//Algoritmo para obtener ln(x), mediante su serie definida
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
	int n, i, den, j, k;
	float z;
	double num, div, resfinal, res, errorf;
	double error[8];
	float x[3];
	
	k=0;
	
	while(k<3){
		do{
		printf("Ingrese el valor de x (x>0): \n");
		scanf("%f", &x[k]);
		}while(x<=0);
		k++;
	}
	
	k=0;
	
	while (k<3){
		errorf=0;
		z = (float)((x[k]-1)/(x[k]+1));
		
		printf("\n# de terminos\t Valor de x\t Valor aproximado\t Error relativo aproximado\n");
		
		for (j=1; j<9; j++){
		n= potencia(2, j);
		
		for(i=0, num=(1/z), den = 0, res = 0; i<n; i++){
		num = num*z*z;
		den = (2*i)+1;
		div= num/den;
		res= res + div;
		}
		resfinal = 2*res;
		
		
		
		error[j-1] = resfinal;
		if (j==1){
			errorf= (resfinal/(resfinal<0? -1*resfinal:resfinal))*100;
		}else{
			errorf= (resfinal-error[j-2])/(resfinal<1? -1*resfinal:resfinal)*100;
		}
		
		printf("%d\t\t %f\t %lf\t\t %lf%%\n", n, x[k], resfinal, errorf);
		}
		k++;
	}
		
		
	} 

