#include <stdio.h>

#include "trace.h"

void* backtrace(int i);

char* get_func_name(const symbol* symbols, int n, void* code_addr) {
    for (int i = n - 1; i >= 0; i--) {
        if (symbols[i].function <= code_addr) {
            return symbols[i].name;
        }
    }
    
    return "???";
}

void trace(const symbol* symbols, int n, const char* msg) {
    printf("%s:", msg);
    
    int i = 1;
    
    while (1) 
    {
        void* code_ptr = backtrace(i);
        if (code_ptr == 0) break;
        
        printf(" %s()", get_func_name(symbols, n, code_ptr));
        
        i++;
    }
    
    printf("\n");
}
