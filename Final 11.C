#include <stdio.h>

double valor_absoluto(double valor) {
    if (valor < 0) return -valor;
    return valor;
}

int main() {
    double x;

    printf("Ingrese x (-1 < x < 1): ");
    scanf("%lf", &x);


    if (x <= -1 || x >= 1) {
        printf("Error: x debe estar entre -1 y 1.\n");
        return 1;
    }

    int potencias[] = {2, 4, 8, 16, 32, 64, 128, 256};
    int num_pruebas = 8;

    double aprox_anterior = 0.0;

    printf("\n| Número de términos (n) | Valor de x | Valor Aproximado | Error Relativo Aproximado %% |\n");
    printf("|------------------------|------------|-------------------|------------------------------|\n");

    for (int idx = 0; idx < num_pruebas; idx++) {
        int n = potencias[idx];

        double sum = 0.0;
        for (int i = 0; i < n; i++) {
            int exp = 2*i + 1;
            double term = 1.0 / exp;


            for (int j = 0; j < exp; j++) {
                term *= x;
            }

            sum += term;
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
