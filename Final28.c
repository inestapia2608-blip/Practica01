#include <stdio.h>

int main(int argc, char *argv[])
 {
    int n;
    double x, coh, ter;
    int i;

    printf("Ingrese el valor de x: ");
    scanf("%lf", &x);
    
    do {
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    } while(n < 1);
    
    coh = 1.0; 
    ter = 1.0;
    
    for(i = 1; i < n; i++) {
        ter = ter * x * x / ((2 * i - 1) * (2 * i));
        coh += term;
    }
    
    printf("El cosh(%lf) = %lf\n", x, coh);
    return 0;
}