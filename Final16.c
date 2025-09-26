#include <stdio.h>

#define KMAX 50

long long binom(int n, int k) {
    long long rbi=1;
    for (int i=1; i<=k; i++) {
        rbi=rbi*(n-i+1)/i;
    }
    return rbi;
}

int main(int argc, char *argv[]) {
    int i, k, kc;
    double B[NMAX], sum;

    do {
        printf("Ingrese el numero de K: ");
        scanf("%d", &k);
    } while(k<1);

    B[0]=1;
    for (kc=1; kc<=k; kc++) {
        sum=0.0;
        for (i=0; i<kc; i++) {
            sum+=binom(kc, i)*B[i]/(kc+1.0-i);
        }
        B[kc]=-sum;
    }
    printf("B[%d] = %.10f\n", k, B[k]);
    return 0;
}