#include <stdio.h>

int main(int argc, char *argv[]) {
    int n, k, i;
    int a, b;

    printf("Ingresa el valor de a: ");
    scanf("%d", &a);

    printf("Ingresa el valor de b: ");
    scanf("%d", &b);

    printf("Ingresa el exponente n: ");
    scanf("%d", &n);

    printf("\n| Término (k) | Coeficiente Binomial | Potencia de a | Potencia de b | Valor del Término |\n");
    printf("|-------------|----------------------|---------------|---------------|-------------------|\n");

    for (k = 0; k <= n; k++) {

        double fact_n = 1;
        for (i = 1; i <= n; i++) {
            fact_n *= i;
        }


        double fact_k = 1;
        for (i = 1; i <= k; i++) {
            fact_k *= i;
        }


        double fact_nk = 1;
        for (i = 1; i <= (n-k); i++) {
            fact_nk *= i;
        }


        double coef = fact_n / (fact_k * fact_nk);


        double pot_a = 1;
        for (i = 1; i <= (n-k); i++) {
            pot_a *= a;
        }


        double pot_b = 1;
        for (i = 1; i <= k; i++) {
            pot_b *= b;
        }


        double termino = coef * pot_a * pot_b;


        printf("| k = %-8d | C(%d,%d) = %-10.0f | a^%d = %-8.0f | b^%d = %-8.0f | %-16.0f |\n",
               k, n, k, coef, n-k, pot_a, k, pot_b, termino);
    }


    double resultado = 1;
    for (k = 0; k <= n; k++) {

    }

    printf("\nResultado final: (%d + %d)^%d = %.0f\n", a, b, n, resultado);

    return 0;
}
