#include <stdio.h>
#include <stdlib.h>

int n;
int bits();

int main(int argc,char *argv[])
{
    if (argc != 2)
        return 0;

    n = atoi(argv[1]);
    
    printf("bits(%d) = %d\n",n,bits());
    return 0;
}