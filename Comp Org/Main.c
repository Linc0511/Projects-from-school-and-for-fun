#include "Unique_Strings_Header.h"
#include <stdio.h>
#include <string.h>
int main()
{
    char newString[1000];
    while (fgets(newString, sizeof(newString), stdin) != NULL)
    {
        int result = add(newString);
        if (result != 0)
        {
            printf("%s", newString);
        } 
    }  
    clear(newString);
    return 0;
}


