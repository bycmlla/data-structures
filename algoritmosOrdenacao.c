#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 10000

void preencherVetor(int vetor[], int tamanho)
{
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 50000 + 1;
    }
    printf("---------------VETOR DESORDENADO ABAIXO----------------- \n\n\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int bubbleSort(int vetor[], int tamanho)
{
    int contador = 0;
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            contador++;
            if (vetor[j] > vetor[j + 1])
            {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
    return contador;
}

int selectionSort(int vetor[], int tamanho)
{
    int contador = 0;
    for (int i = 0; i < tamanho - 1; i++)
    {
        int indiceMenor = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            contador++;
            if (vetor[j] < vetor[indiceMenor])
            {
                indiceMenor = j;
            }
        }
        int temp = vetor[i];
        vetor[i] = vetor[indiceMenor];
        vetor[indiceMenor] = temp;
    }
    return contador;
}

int insertionSort(int vetor[], int tamanho)
{
    int contador = 0;
    for (int i = 1; i < tamanho; i++)
    {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave)
        {
            contador++;
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
    return contador;
}

void heapify(int vetor[], int tamanho, int indice)
{
    int maior = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    if (esquerda < tamanho && vetor[esquerda] > vetor[maior])
    {
        maior = esquerda;
    }

    if (direita < tamanho && vetor[direita] > vetor[maior])
    {
        maior = direita;
    }

    if (maior != indice)
    {
        int temp = vetor[indice];
        vetor[indice] = vetor[maior];
        vetor[maior] = temp;
        heapify(vetor, tamanho, maior);
    }
}

int heapSort(int vetor[], int tamanho)
{
    int contador = 0;
    for (int i = tamanho / 2 - 1; i >= 0; i--)
    {
        heapify(vetor, tamanho, i);
    }

    for (int i = tamanho - 1; i >= 0; i--)
    {
        contador++;
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        heapify(vetor, i, 0);
    }
    return contador;
}

int partition(int vetor[], int inicio, int fim)
{
    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j <= fim - 1; j++)
    {
        if (vetor[j] < pivo)
        {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;

    return (i + 1);
}

void quickSort(int vetor[], int inicio, int fim, int *contador)
{
    if (inicio < fim)
    {
        int pivo = partition(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo - 1, contador);
        quickSort(vetor, pivo + 1, fim, contador);
    }
}

void merge(int vetor[], int inicio, int meio, int fim, int *contador)
{
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = vetor[inicio + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = vetor[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < n1 && j < n2)
    {
        (*contador)++;
        if (L[i] <= R[j])
        {
            vetor[k] = L[i];
            i++;
        }
        else
        {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int vetor[], int inicio, int fim, int *contador)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(vetor, inicio, meio, contador);
        mergeSort(vetor, meio + 1, fim, contador);
        merge(vetor, inicio, meio, fim, contador);
    }
}

// Função para busca sequencial e contagem de iterações
int buscaSequencial(int vetor[], int tamanho, int chave)
{
    int contador = 0;
    for (int i = 0; i < tamanho; i++)
    {
        contador++;
        if (vetor[i] == chave)
        {
            return contador;
        }
    }
    return -1;
}

int buscaBinaria(int vetor[], int tamanho, int chave)
{
    int esquerda = 0;
    int direita = tamanho - 1;
    int contador = 0;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;
        contador++;
        if (vetor[meio] == chave)
        {
            return contador;
        }
        if (vetor[meio] < chave)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }

    return -1;
}

int main()
{
    int vetor[tam];
    int chave = rand() % 50000 + 1;

    preencherVetor(vetor, tam);

    // Bubble Sort
    int contadorBubble = bubbleSort(vetor, tam);
    printf("Bubble Sort: %d iteracoes\n", contadorBubble);

    // Selection Sort
    int contadorSelection = selectionSort(vetor, tam);
    printf("Selection Sort: %d iteracoes\n", contadorSelection);

    // Insertion Sort
    int contadorInsertion = insertionSort(vetor, tam);
    printf("Insertion Sort: %d iteracoes\n", contadorInsertion);

    // Heap Sort
    int contadorHeap = heapSort(vetor, tam);
    printf("Heap Sort: %d iteracoes\n", contadorHeap);

    // Quick Sort
    int contadorQuick = 0;
    quickSort(vetor, 0, tam - 1, &contadorQuick);
    printf("Quick Sort: %d iteracoes\n", contadorQuick);

    // Merge Sort
    int contadorMerge = 0;
    mergeSort(vetor, 0, tam - 1, &contadorMerge);
    printf("Merge Sort: %d iteracoes\n", contadorMerge);

    // Busca Sequencial
    int contadorSequencial = buscaSequencial(vetor, tam, chave);
    printf("Busca Sequencial: %d iteracoes\n", contadorSequencial);

    // Busca Binária
    int contadorBinaria = buscaBinaria(vetor, tam, chave);
    printf("Busca Binaria: %d iteracoes\n", contadorBinaria);

    return 0;
}
