#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *prox;
} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;

void inicializarLista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}

void isVazia(Lista *lista)
{

    if (lista->inicio == NULL)
    {
        printf("Lista esta vazia\n");
    }
    else
    {
        printf("Lista nao esta vazia\n");
    }
}

// INSERINDO NO INICIO
// cria a lista passando a lista como um ponteiro e o dado
void inserirInicio(Lista *lista, int dado)
{
    // cria um novo nó alocando memoria pra ele
    // o novo dado vai receber o dado que for passado por parametro
    // e o prox do novo elemento vai apontar para null
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;

    // faz a verificação pra saber se a lista está vazia
    // se ela tiver vazia, o inicio da lista vai apontar para o novo elemento
    // o proximo do novo continua apontando para null;
    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        novo->prox = NULL;
        lista->tam++;
    }
    // se não estiver vazia, o prox do novo elemento vai apontar para o elemento
    // que estiver no inicio da lista
    // e o inicio da lista passa a apontar para o novo elemento;
    else
    {
        novo->prox = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
}

// INSERIR NO FINAL DA LISTA
// cria a função trazendo a nossa lista e o dado

void inserirFinal(Lista *lista, int d)
{
    // cria um novo nó alocando memoria
    // o dado do novo vai receber o dado que for passando por parametro na função
    // o prox do novo vai apontar pra null
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = d;
    novo->prox = NULL;

    // faz a verificação se a lista é vazia novamente
    // se a lista for vazia o inicio vai receber o novo elemento

    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        novo->prox = NULL;
        lista->tam++;
    }
    else
    {

        // se não for vazia faz a inserção no final
        // cria um novo elemento aux
        // esse aux vai receber a lista
        No *aux = lista->inicio;

        // percorre a lista até encontrar o null
        // enquanto o prox do aux for != de null ele vai continuar recebendo ele dnv
        while (aux->prox != NULL)
        {
            // isso faz com que o ponteiro avance para o proximo nó da lista
            // ele recebe o endereço do proximo nó
            aux = aux->prox;
        }
        // quando encontrar o null, no caso o final da lista, ele vai receber o novo elemento
        // o prox do novo vai receber null
        // e dou um free para liberar a memoria do aux que alocamos;
        aux->prox = novo;
        lista->tam++;
        novo->prox = NULL;
    }
}

void quantidade(Lista *lista)
{
    printf("Tamanho da lista: %d ", lista->tam);
}

// IMPRIMINDO LISTA
void imprimirLista(Lista *lista)
{
    // cria um nó auxiliar que recebe o inicio da lista
    // dou um print fora do loop
    No *aux = lista->inicio;
    printf("Exibindo lista: ");
    // equanto nao for nulo, ele vai printando os dados
    // e o aux continua recebendo o proximo nó

    while (aux != NULL)
    {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n\n");
}

// BUSCANDO ELEMENTO NA LISTA
// cria a função passando a lista
void buscarElemento(Lista *lista)
{
    // crio meu aux para receber o inicio da lista
    /*crio minha variavel valor para que o usuario possa
    escolher o numero desejado*/
    // crio uma flag para que ele diga se foi encontrado ou nao
    No *aux = lista->inicio;
    int valor, encontrado = 0;

    // print e scan do elemento desejado pelo usuário

    printf("Digite o elemento que você deseja procurar: ");
    scanf("%d", &valor);

    // faço meu loop, enquanto aux for != de nulo
    // entro com um if para verificar se o elemento desejado existe na lista
    // se ele existir ele retorna o valor e quebra o loop, caso não exista ele vai retornar

    while (aux != NULL)
    {
        if (aux->dado == valor)
        {
            encontrado = 1;
            valor = aux->dado;
            printf("Dado encontrado: %d", valor);
            break;
        }
        aux = aux->prox;

        if (!encontrado)
        {
            printf("Dado nao existe nesta lista");
        }
    }
}

// REMOVENDO ITEM DA LISTA
// Cria a função passando a lista
void removerElemento(Lista *lista)
{
    No *aux = lista->inicio;
    No *ant = NULL;
    int valor, flag = 0;

    printf("Digite o valor que você deseja remover da lista: ");
    scanf("%d", &valor);

    while (aux != NULL)
    {
        if (aux->dado == valor)
        {
            if (ant == NULL)
            {
                lista->inicio = aux->prox;
            }
            else {
                ant->prox = aux->prox;
            }
            
            printf("Dado encontrado: %d. Removendo...", valor);
            free(aux);
            lista->tam--;
            printf("Exibindo lista: ");
            imprimirLista(lista);
            flag = 1;
            break;
        }
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
        No *prox = aux->prox;
        free(aux->dado);
        free(aux);
        aux = prox;
    }
    lista->inicio = NULL;
    printf("removi tudo");
}

void bubbleSort(Lista *lista)
{
    // crio uma flag
    // crio meu ponteiro pro dado atual e uma pro dado anterior
    int trocou;
    No *atual;
    No *anterior = NULL;
    // confiro se a lista está vazia
    if (lista->inicio == NULL)
    {
        return;
    }
    do
    {
        trocou = 0;
        atual = lista->inicio;

        while (atual->prox != anterior)
        {
            if (atual->dado == atual->prox->dado)
            {
                // crio uma variavel para guardar o valor de A
                // A vai receber o valor de B
                // B vai receber o valor de A da variavel
                int temp = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = temp;

                trocou = 1;
            }
            atual = atual->prox;
        };
        anterior = atual;
    } while (trocou);
}

int main()
{
    Lista lista;

    inicializarLista(&lista);

    int opcao;
    do
    {
        printf("\n\n-----------------------------------------------\n\n");
        printf("Programa para implementar as funcoes principais \n");
        printf("de uma lista simplesmente encadeada.\n\n");
        printf(" 1 - Verificar se a lista e vazia \n");
        printf(" 2 - Inserir um elemento no fim da lista \n");
        printf(" 3 - Informar a quantidade de elementos da lista \n");
        printf(" 4 - Imprimir toda a lista \n");
        printf(" 5 - Buscar elemento na lista \n");
        printf(" 6 - Remover elemento da lista \n");
        printf(" 7 - Remover todos os elementos da lista \n");
        printf(" 8 - Ordenar a lista\n");
        printf(" 9 - Inserir um elemento no inicio da lista \n");
        printf("10 - Sair \n\n");
        printf("Escolha a opcao desejada: ");

        scanf("%d", &opcao);

        if (opcao == 1)
            isVazia(&lista);
        if(opcao == 2){
            int num;
            printf("\n\nDigite o numero que deseja adicionar: ");
            scanf("%d", &num);
            inserirFinal(&lista, num);
        }
        if(opcao == 3)
            quantidade(&lista);
        else if(opcao == 4)
            imprimirLista(&lista);
        else if(opcao == 5)
            buscarElemento(&lista);
        else if(opcao == 6)
            removerElemento(&lista);
        else if(opcao == 7)
            removerTodosElementos(&lista);
        else if(opcao == 8)
            bubbleSort(&lista);
        else if (opcao == 9){
            int num;
            printf("\nDigite o numero que deseja adicionar: ");
            scanf("%d", &num);
            inserirInicio(&lista, num);
        }

    } while (opcao != 10);
}