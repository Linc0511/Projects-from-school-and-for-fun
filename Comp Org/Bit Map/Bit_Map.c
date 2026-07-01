#include <stdio.h>
#include <assert.h>
#include <string.h>

// Declare the assembly function
extern void enlarge(char *original, int width, int height, char *output);

int main() {
    char original[] = { 0x20, 0x20, 0x50, 0x50, 0x88, 0xFF, 0x8A };
    char enlarged[] = { 0x0C, 0x00, 0x0C, 0x00, 
                        0x0C, 0x00, 0x0C, 0x00, 
                        0x33, 0x00, 0x33, 0x00, 
                        0x33, 0x00, 0x33, 0x00, 
                        0xC0, 0xC0, 0xC0, 0xC0, 
                        0xFF, 0xC0, 0xFF, 0xC0, 
                        0xC0, 0xC0, 0xC0, 0xC0 };
    char output[2 * 14];
    
    // Call the assembly function
    enlarge(original, 5, 7, output);
    
    // Check if the output matches the expected result
    for (int i = 0; i < sizeof(output) / sizeof(output[0]); i++) {
        printf("Element at index %d: %d\n", i, output[i]);
    }
    assert(memcmp(enlarged, output, 2 * 14) == 0);

    printf("Test passed!\n");

    return 0;
}
