#include <stdio.h>

double valor_absoluto(double valor) {
    if (valor < 0) return -valor;
    return valor;
}

int main(int argc, char *argv[]) {
    double x;
    printf("Ingrese x (en radianes, 0 < |x| < pi): ");
    scanf("%lf", &x);


    int terminos[] = {1, 2, 3, 4, 5};
    int num_pruebas = 5;

    double aprox_anterior = 0.0;

    printf("\n| Número de términos (n) | Valor de x | Valor Aproximado | Error Relativo Aproximado %% |\n");
    printf("|------------------------|------------|-------------------|------------------------------|\n");

    for (int idx = 0; idx < num_pruebas; idx++) {
        int n = terminos[idx];

        double result = 0.0;

        if (x == 0) {
            printf("Error: csc(x) no está definida para x=0.\n");
            return 1;
        }


        result = 1.0 / x;


        if (n >= 2) result += x / 6.0;
        if (n >= 3) result += (7.0 * x * x * x) / 360.0;
        if (n >= 4) result += (31.0 * x * x * x * x * x) / 15120.0;
        if (n >= 5) result += (127.0 * x * x * x * x * x * x * x) / 604800.0;

        double error_rel;
        if (idx == 0) {
            error_rel = 100.0;
        } else {
            double diferencia = result - aprox_anterior;
            error_rel = valor_absoluto(diferencia) / valor_absoluto(result) * 100.0;
        }

        printf("| n = %-17d | %-10.2f | %-16.10f | %-28.6f |\n",
               n, x, result, error_rel);

        aprox_anterior = result;
    }

    return 0;
}

