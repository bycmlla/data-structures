#include <stdio.h>

#define TAM 10

int main() {
    int vetor[TAM];
    int i;

    // Leitura dos valores do vetor
    printf("Digite os valores do vetor:\n");
    for (i = 0; i < TAM; i++) {
        scanf("%d", &vetor[i]);
    }

    // Acumulação dos valores
    for (i = 1; i < TAM; i++) {
        vetor[i] += vetor[i - 1];
    }

    // Exibição do vetor final
    printf("O vetor final obtido:\n");
    for (i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
