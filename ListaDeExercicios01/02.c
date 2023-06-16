#include <stdio.h>

#define TAM 20

int main() {
    int vetor[TAM];
    int maiorValor;
    int posicaoMaior;
    int i;

    // Leitura dos valores do vetor
    printf("Digite os valores do vetor:\n");
    for (i = 0; i < TAM; i++) {
        scanf("%d", &vetor[i]);
    }

    // Encontrar o maior valor e a posição correspondente
    maiorValor = vetor[0];
    posicaoMaior = 0;
    for (i = 1; i < TAM; i++) {
        if (vetor[i] > maiorValor) {
            maiorValor = vetor[i];
            posicaoMaior = i;
        }
    }

    // Exibição do maior valor e posição correspondente
    printf("O maior valor encontrado é: %d\n", maiorValor);
    printf("A posição do maior valor é: %d\n", posicaoMaior);

    return 0;
}
