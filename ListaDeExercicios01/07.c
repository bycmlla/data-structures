#include <stdio.h>
#include <string.h>

#define TAM 100

int contarPalavras(const char* frase) {
    int i, count = 0;
    int tamanho = strlen(frase);

    // Verifica cada caractere da frase
    for (i = 0; i < tamanho; i++) {
        // Se o caractere atual não é um espaço em branco e o próximo caractere é um espaço em branco, incrementa o contador de palavras
        if (frase[i] != ' ' && frase[i] != '\t' && frase[i] != '\n' && (frase[i + 1] == ' ' || frase[i + 1] == '\t' || frase[i + 1] == '\n' || frase[i + 1] == '\0')) {
            count++;
        }
    }

    return count;
}

int main() {
    char frase[TAM];

    // Leitura da frase
    printf("Digite a frase:\n");
    fgets(frase, TAM, stdin);

    // Contagem de palavras
    int numPalavras = contarPalavras(frase);

    // Exibição do resultado
    printf("A frase contém %d palavras.\n", numPalavras);

    return 0;
}
