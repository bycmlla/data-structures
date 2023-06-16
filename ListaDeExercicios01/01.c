#include <stdio.h>

#define TAM 10

int main() {
    int vetor[TAM];
    int soma = 0;
    int i;

    // Leitura dos valores do vetor
    printf("Digite os valores do vetor:\n");
    for (i = 0; i < TAM; i++) {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    // Cálculo da média
    float media = (float)soma / TAM;

    // Exibição da média
    printf("A média dos valores é: %.2f\n", media);

    return 0;
}
