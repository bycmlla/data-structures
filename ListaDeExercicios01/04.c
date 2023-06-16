#include <stdio.h>

#define TAM 16

int main() {
    int vetor[TAM];
    int i, temp;

    // Leitura dos valores do vetor
    printf("Digite os valores do vetor:\n");
    for (i = 0; i < TAM; i++) {
        scanf("%d", &vetor[i]);
    }

    // Troca dos valores
    for (i = 0; i < TAM / 2; i++) {
        temp = vetor[i];
        vetor[i] = vetor[TAM - 8 + i];
        vetor[TAM - 8 + i] = temp;
    }

    // Exibição do vetor resultante
    printf("O vetor resultante:\n");
    for (i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
