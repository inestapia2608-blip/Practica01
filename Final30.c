#include <stdio.h>
#include <math.h>

#define MAX_TERMS 256
#define NUM_X 3


long double potencia(long double base, int exponente);
long double factorial(int n);
long double absoluto(long double x);
long double coeficiente_arcsin(int n);


long double potencia(long double base, int exponente) {
    long double res = 1.0;
    for (int i = 0; i < exponente; i++) {
        res *= base;
    }
    return res;
}


long double factorial(int n) {
    long double res = 1.0;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}


long double absoluto(long double x) {
    return (x < 0.0) ? -x : x;
}


long double coeficiente_arcsin(int n) {
    long double num = factorial(2 * n);
    long double den = potencia(4.0, n) * potencia(factorial(n), 2) * (2 * n + 1);
    return num / den;
}

int main() {
    long double x[NUM_X];
    long double anterior, sum, term, coef;
    int i, j, n;

    
    for (i = 0; i < NUM_X; i++) {
        do {
            printf("Valor de x #%d (|x| < 1): ", i + 1);
            scanf("%Lf", &x[i]);
        } while (x[i] >= 1.0 || x[i] <= -1.0);
    }

   
    for (i = 0; i < NUM_X; i++) {
        printf("\n# de términos\tValor de x\tValor aproximado\tError relativo (%%)\n");

        anterior = 0.0;

        for (j = 0; j < 9; j++) {
            n = potencia(2.0, j);  
            sum = 0.0;

            for (int k = 0; k <= n; k++) {
                coef = coeficiente_arcsin(k);
                term = coef * potencia(x[i], 2 * k + 1);
                sum += term;
            }

            long double errorf = (j == 0 || absoluto(anterior) < 1e-15)
                                 ? 0.0
                                 : absoluto((sum - anterior) / anterior) * 100.0;

            anterior = sum;

            printf("%-12d\t%-12.6Lf\t%-20.10Lf\t%-20.10Lf%%\n", (int)n, x[i], sum, errorf);
        }
    }

    return 0;
}

