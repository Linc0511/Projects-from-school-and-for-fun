#include <stdio.h>

int main() {
    char functionName[100];
    char operatorSymbol[10];
    FILE *headerFile = fopen("functions.h", "w");

    if (headerFile == NULL) {
        printf("Error opening functions.h for writing.\n");
        return 1;
    }

    while (scanf("%s %s", functionName, operatorSymbol) != EOF) {
        fprintf(headerFile, "int %s(int a, int b) { return a %s b; }\n", functionName, operatorSymbol);
    }

    fclose(headerFile);
    return 0;
}


