#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n1, n2;
    int *p1, *p2;

    p1 = &n1;
    p2 = &n2;

    printf("%p\n %p", (void*)p1, (void*)p2);

    if (p1 > p2)
    {
        printf("%p p1 é o maior", (void*)p1);
    }
    else
    {
        printf("%p p2 é o maior", (void*)p2);
    }

    return 0;
}