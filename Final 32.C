#include <stdio.h>

double valor_absoluto(double valor) {
    if (valor < 0) return -valor;
    return valor;
}

int main(int argc, char *argv[]) {
    double x;

    printf("Ingrese x (|x| < 1): ");
    scanf("%lf", &x);


    if (x <= -1 || x >= 1) {
        printf("Error: |x| debe ser menor que 1.\n");
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
        for (int i = 1; i <= n; i++) {

            double coef = 0.0;
            for (int j = 1; j <= i; j++) {
                coef += 1.0 / j;
            }


            double pot = 1.0;
            for (int j = 0; j < i; j++) {
                pot *= x;
            }


            if (i % 2 == 0) {
                sum -= coef * pot;
            } else {
                sum += coef * pot;
            }
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
