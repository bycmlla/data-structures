#include <stdio.h>

void calcularSoma(int *a, int b) {
    *a = *a + b;
}

int main() {
    int a, b;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    calcularSoma(&a, b);

    printf("Valor de A: %d\n", a);
    printf("Valor de B: %d\n", b);

    return 0;
}
