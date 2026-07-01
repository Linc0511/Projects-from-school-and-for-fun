#include <stdio.h>
#include <stdlib.h>

int n;
int fib();

int main(int argc,char *argv[])
{
    if (argc != 2)
        return 0;

    n = atoi(argv[1]);
    
    printf("f(%d) = %d\n",n,fib(n));
    return 0;
}