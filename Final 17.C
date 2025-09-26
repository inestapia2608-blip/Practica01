#include <stdio.h>

int main(int argc, char *argv[]) {
    int k;
    double resultado = 0.0;
    int num_terminos;

    printf("Ingrese un valor entero para k: ");
    scanf("%d", &k);


    int potencias[] = {2, 4, 8, 16, 32, 64, 128, 256};
    int num_pruebas = 8;

    const double PI = 3.14159265359;

    printf("\n| Número de términos (n) | Valor de k | Valor Aproximado E_k | Error Relativo Aproximado %% |\n");
    printf("|------------------------|------------|----------------------|------------------------------|\n");

    double aprox_anterior = 0.0;

    for (int idx = 0; idx < num_pruebas; idx++) {
        num_terminos = potencias[idx];


        double potencia_2_2k_2 = 1.0;
        for (int i = 0; i < (2 * k + 2); i++) {
            potencia_2_2k_2 *= 2.0;
        }

        long long factorial_2k = 1;
        if (2 * k > 0) {
            for (int i = 1; i <= (2 * k); i++) {
                factorial_2k *= i;
            }
        }

        double potencia_pi_2k_1 = 1.0;
        for (int i = 0; i < (2 * k + 1); i++) {
            potencia_pi_2k_1 *= PI;
        }

        double factor_principal = (potencia_2_2k_2 * factorial_2k) / potencia_pi_2k_1;


        double sumatoria_serie = 0.0;

        for (int i = 0; i < num_terminos; i++) {
            double base = (double)(2 * i + 1);

            double potencia_denominador = 1.0;
            for (int j = 0; j < (2 * k + 1); j++) {
                potencia_denominador *= base;
            }

            double termino_serie = 1.0 / potencia_denominador;

            if (i % 2 == 1) {
                sumatoria_serie -= termino_serie;
            } else {
                sumatoria_serie += termino_serie;
            }
        }

        resultado = factor_principal * sumatoria_serie;


        double error_rel;
        if (aprox_anterior == 0.0) {
            error_rel = 100.0;
        } else {
            double diferencia = resultado - aprox_anterior;
            error_rel = (diferencia > 0 ? diferencia : -diferencia) / (resultado > 0 ? resultado : -resultado) * 100.0;
        }

        printf("| 2^%d = %-14d | %-10d | %-19.10f | %-28.6f |\n",
               idx + 1, num_terminos, k, resultado, error_rel);

        aprox_anterior = resultado;
    }

    return 0;
}
