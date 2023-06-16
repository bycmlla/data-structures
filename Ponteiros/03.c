#include <stdio.h>

int main()
{
    int n1, n2;
    int *p1, *p2;

    printf("Digite um numero: ");
    scanf("%d", &n1);
    printf("Digite outro numero: ");
    scanf("%d", &n2);

    p1 = &n1;
    p2 = &n2;

    printf("%p\n", p1);
    printf("%p\n", p2);

    if ((void *)p1 > (void *)p2)
    {
        printf("O numero de maior endereco e: %d", n1);
    }
    else
    {
        printf("O numero de maior endereco e: %d ", n2);
    }
}