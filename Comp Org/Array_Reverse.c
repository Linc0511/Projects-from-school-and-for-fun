#include <stdio.h>
#include <stdlib.h>

void reverse(char *str);

int main(int argc,char *argv[])
{
    char s[] = "zyxwvutsrqponmlkjihgfedcba";
    reverse(s);
    printf("%s\n",s);
}