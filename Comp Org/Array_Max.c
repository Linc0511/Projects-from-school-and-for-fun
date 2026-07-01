#include <stdio.h>
#include <stdlib.h>

int max(int a[],int n);


int main(int argc,char *argv[])
{
    int a[] = {-3, 0, -1};
    int m = max(a,3); // 0
    printf("%d\n",m);
}