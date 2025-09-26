#include <stdio.h>

double valor_absoluto(double valor) {
    if (valor < 0) return -valor;
    return valor;
}

int main() {
    float x;
    printf("Ingrese x: ");
    scanf("%f", &x);

    int potencias[] = {2, 4, 8, 16, 32, 64, 128, 256};
    int num_pruebas = 8;

    double aprox_anterior = 0.0;

    printf("\nCálculo de xe^x usando serie de Taylor\n");
    printf("| Número de términos (n) | Valor de x | Valor Aproximado | Error Relativo Aproximado %% |\n");
    printf("|------------------------|------------|-------------------|------------------------------|\n");

    for (int idx = 0; idx < num_pruebas; idx++) {
        int n = potencias[idx];

        double sum = 0.0;

        for (int i = 1; i <= n; i++) {
            // Calcular x^i
            double k = 1.0;
            for (int j = 1; j <= i; j++) {
                k *= x;
            }

            // Calcular i! (factorial)
            double fact = 1.0;
            for (int j = 1; j <= i; j++) {
                fact *= j;
            }

            // Sumar término: x^i / i!
            sum += k / fact;
        }

        // Multiplicar por x para obtener xe^x
        double xe_x_aprox = x * sum;

        double error_rel;
        if (idx == 0) {
            error_rel = 100.0;
        } else {
            double diferencia = xe_x_aprox - aprox_anterior;
            error_rel = valor_absoluto(diferencia) / valor_absoluto(xe_x_aprox) * 100.0;
        }

        printf("| 2^%d = %-14d | %-10.2f | %-16.10f | %-28.6f |\n",
               idx + 1, n, x, xe_x_aprox, error_rel);

        aprox_anterior = xe_x_aprox;
    }

    return 0;
}
