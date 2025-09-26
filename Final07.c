#include <stdio.h>

int main() {
    int n;
    double x, term, exp = 0;

    printf("Ingrese x: ");
    scanf("%lf", &x);

    do {
        printf("Ingrese el numero de terminos (n): ");
        scanf("%d", &n);
    } while (n < 1);

    term = 1;
    for(int i = 0; i < n; i++) {
        exp += term;
        term *= x / (i + 1);
    }

    printf("e^(%lf) = %lf\n", x, exp);
    return 0;
}