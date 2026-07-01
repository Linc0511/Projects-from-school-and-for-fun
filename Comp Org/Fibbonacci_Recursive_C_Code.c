#include <stdio.h>
#include <stdbool.h>
int fib(int n, bool trace);
int main()
{
    int result = fib(4, true);
    printf("%d\n", result);
    
    return 0;
}