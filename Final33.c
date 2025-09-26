#include <stdio.h>

#define NUM_X 3
#define MAX_TERMS 9

long double potencia(long double base, int exponente) {
    long double res = 1.0;
    for (int i = 0; i < exponente; i++) {
        res *= base;
    }
    return res;
}

long double absoluto(long double x) {
    return (x < 0.0) ? -x : x;
}

long double coeficiente(int n) {
    switch (n) {
        case 0: return 1.0;
        case 1: return 1.0;
        case 2: return 0.5;
        case 3: return 0.0;
        case 4: return -1.0 / 8.0;
        case 5: return -1.0 / 15.0;
        case 6: return 0.0;
        case 7: return 1.0 / 105.0;
        case 8: return 1.0 / 560.0;
        default: return 0.0;
    }
}

int main() {
    long double x[NUM_X];
    long double anterior, sum, term;
    int i, j, n;

    for (i = 0; i < NUM_X; i++) {
        printf("Valor de x #%d (recomendado |x| < 1.5): ", i + 1);
        scanf("%Lf", &x[i]);
    }

    for (i = 0; i < NUM_X; i++) {
        printf("\n# de términos\tValor de x\tValor aproximado\tError relativo (%%)\n");

        anterior = 0.0;

        for (j = 1; j <= MAX_TERMS; j++) {
            sum = 0.0;

            for (n = 0; n < j; n++) {
                term = coeficiente(n) * potencia(x[i], n);
                sum += term;
            }

            long double errorf = (j == 1 || absoluto(anterior) < 1e-15)
                                 ? 0.0
                                 : absoluto((sum - anterior) / anterior) * 100.0;

            anterior = sum;

            printf("%-14d%-12.6Lf%-20.10Lf%-20.10Lf%%\n", j, x[i], sum, errorf);
        }
    }

    return 0;
}


