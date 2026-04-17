#include <stdio.h>
#include <math.h>

// Protótipo da função assembly
double foo3(double *a, int n);

int main(void) {
    double valores[] = {M_PI_2, M_PI, M_PI_4}; // Valores para calcular seno
    int n = 3;

    // Chamada à função e impressão do resultado
    printf("foo3(valores, n) = %.2f\n", foo3(valores, n));

    return 0;
}
