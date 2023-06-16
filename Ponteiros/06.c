#include <stdio.h>

int calcularSomaDobro(int *a, int *b) {
    int soma = (*a * 2) + (*b * 2);
    *a = *a * 2;
    *b = *b * 2;
    return soma;
}

int main() {
    int a, b;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    int soma = calcularSomaDobro(&a, &b);

    printf("Soma do dobro dos valores: %d\n", soma);
    printf("Novo valor de A: %d\n", a);
    printf("Novo valor de B: %d\n", b);

    return 0;
}
