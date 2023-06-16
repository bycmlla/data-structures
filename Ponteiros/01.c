#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, *p1;
    n = 20;

    char caract[11] = "olá querida";
    char *p2;

    double d, *pd;
    pd = (double *) malloc(30 *sizeof(d));
    d = 3.89;
    
    p1 = &n;
    p2 = caract;
    printf("%d \n %s\n %f", p1, p2, *pd);
    free(pd);

    return 0;
}