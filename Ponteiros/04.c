#include <stdio.h>

void trocarValores(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    printf("Valores originais: A = %d, B = %d\n", a, b);

    trocarValores(&a, &b);

    printf("Valores trocados: A = %d, B = %d\n", a, b);

    return 0;
}
