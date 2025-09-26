
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
    double pi = 3.141592653589793;

    printf("\n| Número de términos (n) | Valor de x | Valor Aproximado | Error Relativo Aproximado %% |\n");
    printf("|------------------------|------------|-------------------|------------------------------|\n");

    for (int idx = 0; idx < num_pruebas; idx++) {
        int n = potencias[idx];

        double arctan = 0.0;

        if (x > -1.0 && x < 1.0) {

            for (int i = 0; i < n; i++) {
                double pot = 1.0;
                for (int j = 0; j < (2*i+1); j++) pot *= x;

                if (i % 2 == 0)
                    arctan += pot / (2*i+1);
                else
                    arctan -= pot / (2*i+1);
            }
        } else {

            if (x > 0)
                arctan = pi/2;
            else
                arctan = -pi/2;

            for (int i = 0; i < n; i++) {
                double pot = 1.0;
                for (int j = 0; j < (2*i+1); j++) pot *= x;

                if (i % 2 == 0)
                    arctan -= 1.0 / ((2*i+1) * pot);
                else
                    arctan += 1.0 / ((2*i+1) * pot);
            }
        }

        double error_rel;
        if (aprox_anterior == 0.0) {
            error_rel = 100.0;
        } else {
            double diferencia = arctan - aprox_anterior;
            error_rel = valor_absoluto(diferencia) / valor_absoluto(arctan) * 100.0;
        }

        printf("| 2^%d = %-14d | %-10.2f | %-16.10f | %-28.6f |\n",
               idx + 1, n, x, arctan, error_rel);

        aprox_anterior = arctan;
    }

    return 0;
}
