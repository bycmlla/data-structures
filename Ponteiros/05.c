#include <stdio.h>

void encontrarMaiorMenor(int a, int b, int *maior, int *menor) {
    if (a > b) {
        *maior = a;
        *menor = b;
    } else {
        *maior = b;
        *menor = a;
    }
}

int main() {
    int a, b;
    int maior, menor;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    encontrarMaiorMenor(a, b, &maior, &menor);

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    return 0;
}
