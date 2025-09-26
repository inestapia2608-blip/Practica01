#include <stdio.h>

double valor_absoluto(double valor) {
    if (valor < 0) return -valor;
    return valor;
}

int main(int argc, char *argv[]) {
    double x;
    printf("Ingrese x: ");
    scanf("%lf", &x);

    int potencias[] = {2, 4, 8, 16, 32, 64, 128, 256};
    int num_pruebas = 8;

    double aprox_anterior = 0.0;

    printf("\n| Número de términos (n) | Valor de x | Valor Aproximado | Error Relativo Aproximado %% |\n");
    printf("|------------------------|------------|-------------------|------------------------------|\n");

    for (int idx = 0; idx < num_pruebas; idx++) {
        int n = potencias[idx];

        double sum = 0.0;
        for (int i = 0; i < n; i++) {
            double term = 1.0;
            for (int j = 0; j < 2*i; j++) term *= x;

            double fact = 1.0;
            for (int j = 1; j <= 2*i; j++) fact *= j;

            if (i % 2 == 0) sum += term / fact;
            else sum -= term / fact;
        }

        double error_rel;
        if (aprox_anterior == 0.0) {
            error_rel = 100.0;
        } else {
            double diferencia = sum - aprox_anterior;
            error_rel = valor_absoluto(diferencia) / valor_absoluto(sum) * 100.0;
        }

        printf("| 2^%d = %-14d | %-10.2f | %-16.10f | %-28.6f |\n",
               idx + 1, n, x, sum, error_rel);

        aprox_anterior = sum;
    }

    return 0;
}

