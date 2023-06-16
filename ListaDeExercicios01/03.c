#include <stdio.h>

#define TAM 15

int main() {
    int vetor[TAM];
    int i;

    // Leitura dos valores do vetor
    printf("Digite os valores do vetor:\n");
    for (i = 0; i < TAM; i++) {
        scanf("%d", &vetor[i]);
    }

    // Impressão do vetor na ordem inversa
    printf("O vetor na ordem inversa:\n");
    for (i = TAM - 1; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
