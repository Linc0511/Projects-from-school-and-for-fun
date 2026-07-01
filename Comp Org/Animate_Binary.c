#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void printBinary(int num, int width) {
    for (int i = width - 1; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("██");
        } else {
            printf("  ");
        }
    }
}
int main(int argc, char *argv[]) {
    int scrolls = atoi(argv[1]);
    int numRows = argc - 2;
    int maxWidth = 0;
    int *numbers = (int *)malloc(numRows * sizeof(int));
    for (int i = 0; i < numRows; i++) {
        numbers[i] = atoi(argv[i + 2]);
        int width = 0, num = numbers[i];
        while (num > 0) { width++; num >>= 1; }
        maxWidth = width > maxWidth ? width : maxWidth;
    }
    for (int s = -1; s != maxWidth * scrolls; s++ )
    {
        //printf("\ec");
        printf("⎯⎯⎯\n"); 
        for (int i = 0; i < numRows; i++) {
            int num = numbers[i];
            printBinary(num, maxWidth);
            putchar('\n');
        }
        usleep(100000);
        for (int i = 0; i < numRows; i++) {
            int num = numbers[i];
            num = (num >> 1) | ((num & 1) << (maxWidth - 1));
            numbers[i] = num;
        }
    }
    free(numbers);
    return 0;  
}


