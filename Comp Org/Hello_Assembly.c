#include <stdio.h>
#include <stdlib.h>

int x,y,z;
int f();
int g();
int h();

int main(int argc,char *argv[])
{
    if (argc != 4)
        return 0;

    x = atoi(argv[1]);
    y = atoi(argv[2]);
    z = atoi(argv[3]);
    printf("h(%d,%d,%d) = %d\n",x,y,z,h());
    printf("f(%d,%d,%d) = %d\n",x,y,z,f());
    printf("g(%d,%d,%d) = %d\n",x,y,z,g());
    //printf("h(%d,%d,%d) = %d\n",x,y,z,h());
    return 0;
}