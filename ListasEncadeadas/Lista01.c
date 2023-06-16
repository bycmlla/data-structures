#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *prox;
} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;

void inicio(Lista *lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (lista == NULL)
    {
        lista->inicio = novo;
        novo->prox = NULL;
        lista->tam++;
    }
    else
    {
        novo->prox = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
}

void isVazia(Lista *lista)
{
    int is = 0;
    if (lista->inicio == NULL)
    {
        is = 1;
    }

    printf("%d", is);
}

void final(Lista *lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->tam++;
    }
    else
    {
        No *aux = (No *)malloc(sizeof(No));
        aux = lista->inicio;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        lista->tam++;
    }
}

void exibirLista(Lista *lista)
{
    No *atual = lista->inicio;

    printf("Lista: ");

    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }

    printf("\n");
}

void quantidade(Lista *lista)
{
    printf("Tamanho da lista: %d ", lista->tam);
}

void imprimirLista(Lista *lista)
{
    No *aux = lista->inicio;
    int flag = 0;
    if (aux != NULL)
    {
        flag = 1;
        printf("Exibindo lista: ");

        while (aux != NULL)
        {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("\n\n");
    } 
    if (!flag)
    {
        printf("tem nada aqui");
    }
    
};

void buscarElemento(Lista *lista)
{
    No *aux = lista->inicio;
    int valor;
    int encontrado = 0;

    printf("Digite o elemento que você deseja procurar: ");
    scanf("%d", &valor);

    while (aux != NULL)
    {
        if (aux->valor == valor)
        {
            encontrado = 1;
            int valueFound;
            valueFound = aux->valor;
            printf("Dado encontrado: %d", valueFound);
            break;
        }
        aux = aux->prox;
        if (!encontrado)
        {
            printf("Dado nao existe nesta lista\n");
        }
    }
}

void removerElemento(Lista *lista)
{
    No *aux = lista->inicio;
    No *ant = NULL;
    int valor, flag = 0;

    printf("Digite o valor que você deseja remover da lista: ");
    scanf("%d", &valor);

    while (aux != NULL)
    {
        if (aux->valor == valor)
        {
            flag = 1;

            if (ant == NULL)
            {
                lista->inicio = aux->prox;
            }
            else
            {
                ant->prox = aux->prox;
            }

            printf("Dado encontrado: %d. Removendo...", valor);
            free(aux);
            printf("Exibindo lista: ");
            imprimirLista(lista);
            break;
        }
        ant = aux;
        aux = aux->prox;

        if (!flag)
        {
            printf("este dado nao existe.");
        }
    }
}

void removerTodosElementos(Lista *lista)
{
    No *aux = lista->inicio;

    while (aux != NULL)
    {
        No * prox = aux->prox;
        free(aux->valor);
        free(aux);
        aux = prox;
    }
    lista->inicio = NULL;
    printf("removi tudo");
}

int main()
{
    Lista lista;

    lista.inicio = NULL;
    lista.tam = 0;
    isVazia(&lista);

    inicio(&lista, 18);
    inicio(&lista, 15);
    final(&lista, 38);
    imprimirLista(&lista);

    removerTodosElementos(&lista);

    imprimirLista(&lista);
};