#include <stdio.h>

double valor_absoluto(double valor) {
    if (valor < 0) return -valor;
    return valor;
}

int main(int argc, char *argv[]) {
    double x;
    double pi_md = 1.57079;

    printf("Ingrese x (|x| < pi/2): ");
    scanf("%lf", &x);


    if (x < -pi_md || x > pi_md) {
        printf("Error: |x| debe ser menor que pi/2.\n");
        return 1;
    }

    int potencias[] = {1, 2, 3, 4};
    int num_pruebas = 4;

    double aprox_anterior = 0.0;

    printf("\n| Número de términos (n) | Valor de x | Valor Aproximado | Error Relativo Aproximado %% |\n");
    printf("|------------------------|------------|-------------------|------------------------------|\n");

    for (int idx = 0; idx < num_pruebas; idx++) {
        int n = potencias[idx];

        double result = 0.0;


        if (n >= 1) result += x;
        if (n >= 2) result += -(1.0/3.0) * x * x * x;
        if (n >= 3) result += (2.0/15.0) * x * x * x * x * x;
        if (n >= 4) result += -(17.0/315.0) * x * x * x * x * x * x * x;

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
