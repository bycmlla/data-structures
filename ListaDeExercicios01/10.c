#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int calcularSomaMatriz(int matriz[LINHAS][COLUNAS]) {
    int soma = 0;
    int i, j;

    // Percorre a matriz e acumula a soma dos elementos
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            soma += matriz[i][j];
        }
    }

    return soma;
}

int main() {
    int matriz[LINHAS][COLUNAS];
    int i, j;

    // Leitura da matriz
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Cálculo da soma
    int soma = calcularSomaMatriz(matriz);

    // Exibição do resultado
    printf("A soma dos elementos da matriz é: %d\n", soma);

    return 0;
}
