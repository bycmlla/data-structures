#include <stdio.h>
#include <string.h>

#define TAM_FRASE 100

void removerEspacosExcesso(char* frase) {
    int tamanho = strlen(frase);
    int i, j;

    // Remove espaços em excesso
    for (i = 0, j = 0; i < tamanho; i++) {
        if (frase[i] == ' ' && frase[i + 1] == ' ') {
            continue;  // Ignora espaços em excesso
        }
        frase[j] = frase[i];
        j++;
    }
    frase[j] = '\0';
}

int main() {
    char frase[TAM_FRASE];

    // Leitura da frase
    printf("Digite a frase:\n");
    fgets(frase, TAM_FRASE, stdin);

    // Remoção dos espaços em excesso
    removerEspacosExcesso(frase);

    // Exibição do resultado
    printf("Frase sem espaços em excesso:\n%s\n", frase);

    return 0;
}
