#include <stdio.h>
#include <string.h>

#define TAM_FRASE 100
#define TAM_PALAVRA 20

int verificarPalavraNaFrase(const char* frase, const char* palavra) {
    int tamanhoFrase = strlen(frase);
    int tamanhoPalavra = strlen(palavra);
    int i, j;

    // Percorre a frase
    for (i = 0; i <= tamanhoFrase - tamanhoPalavra; i++) {
        int encontrou = 1;

        // Verifica se a palavra existe na posição atual da frase
        for (j = 0; j < tamanhoPalavra; j++) {
            if (frase[i + j] != palavra[j]) {
                encontrou = 0;
                break;
            }
        }

        // Se a palavra foi encontrada, retorna 1
        if (encontrou) {
            return 1;
        }
    }

    // Caso a palavra não tenha sido encontrada, retorna 0
    return 0;
}

int main() {
    char frase[TAM_FRASE];
    char palavra[TAM_PALAVRA];

    // Leitura da frase
    printf("Digite a frase:\n");
    fgets(frase, TAM_FRASE, stdin);

    // Leitura da palavra
    printf("Digite a palavra:\n");
    fgets(palavra, TAM_PALAVRA, stdin);

    // Remoção do caractere de nova linha (\n) das strings
    frase[strcspn(frase, "\n")] = '\0';
    palavra[strcspn(palavra, "\n")] = '\0';

    // Verificação da palavra na frase
    if (verificarPalavraNaFrase(frase, palavra)) {
        printf("A palavra '%s' foi encontrada na frase.\n", palavra);
    } else {
        printf("A palavra '%s' não foi encontrada na frase.\n", palavra);
    }

    return 0;
}
