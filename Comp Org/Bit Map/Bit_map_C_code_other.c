#include <stdio.h>
#include <stdlib.h>

void print_out(char* data, int width, int height) {
    for (int row = 0; row < height; row++) {
        char byte = 0;
        
        for (int col = 0; col < width; col++) {
            if (col % 8 == 0) {
                byte = *data;
                data++;
            }
            
            printf((byte & 0x80) ? "██" : "  ");
            
            byte = byte << 1;
        }
        
        printf("\n");
    }
}

int main() // THE PART WHERE I ACTUALLY DO THE ALGORITHM
{
    int cur_index = 0;
    char input[] = {0x20, 0x20, 0x50, 0x50, 0x8A, 0xFF, 0x8A};
    int width = 5;
    int height = 7;
    char output[height * 2 * 2];
    // char* output = calloc(height * 2 * 2, 1);
    int input_index = 0;
    
    int offset = (width * 2 + 7)/8;
    
    for (int i = 0; i < height; i++) { // move into al from arrray initially
        
        int count = 0; //how many bits counted
        int bit_mask = 1 << 7; //checking if 1 or 0
        int bit_adder = 0; //add 2 if 1, 0 if 0
        
        while (count < width) {
            if (!bit_adder) { // switching to a new 'byte'
                output[cur_index] = 0;
                output[cur_index + offset] = 0;
                cur_index++;
                bit_adder = 3 << 6;
            }
            
            if (!bit_mask) {
                input_index++;
                bit_mask = 1 << 7;
            }
        
            if (input[input_index] & bit_mask) { // if there is a 1 in input, add 2 bits from bit_adder
                output[cur_index - 1] |= bit_adder; // add
                output[cur_index + offset - 1] |= bit_adder;
            }
            
            bit_adder >>= 2; // if 0, shift 2 and dont add any
        
            bit_mask >>= 1;
            count++;
        }
        cur_index += offset; // this line accounts for the height doubling
        input_index++;
    }
    
    print_out(output,10,14);
}