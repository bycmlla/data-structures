#include <stdio.h>
#include <stdlib.h>

int main(){

    int * p1;
    int x = 100;
    p1 = &x;
    *p1 = 200;
    printf("%p\n", p1);
    printf("%i\n", *p1);
    printf("%d", x);
//0061FF14
}