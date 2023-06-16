#include <stdio.h>

#define TAM 100

int main() {
    char frase[TAM];
    int i, j;

    // Leitura da frase
    printf("Digite a frase:\n");
    fgets(frase, TAM, stdin);

    // Remoção dos espaços em branco
    for (i = 0, j = 0; frase[i] != '\0'; i++) {
        if (frase[i] != ' ' && frase[i] != '\t' && frase[i] != '\n') {
            frase[j] = frase[i];
            j++;
        }
    }
    frase[j] = '\0';

    // Exibição do resultado
    printf("Frase sem espaços em branco:\n%s\n", frase);

    return 0;
}
