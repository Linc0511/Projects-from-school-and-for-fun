#include <stdio.h>
#include <stdlib.h>

int find(short needle,short *haystack,int size);

int main(int argc,char *argv[])
{
    short a[] = {1,2,3,4,3,5,4,3,2,1};
    int i = find(6,a,10); // -1
    int j = find(3,a,10); // 2    
    printf("%d %d\n",i,j);
}