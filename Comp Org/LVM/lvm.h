#include <stdint.h>
#define FLAG_POSITIVE       1
#define FLAG_ZERO           2
#define FLAG_NEGATIVE       4
#define FLAG_INT_ENABLE     8

#define INT_NONE            -1

#define RESULT_CONTINUE     0
#define RESULT_ILLEGAL      1
#define RESULT_UNALIGNED    2

typedef struct vm_t {
    uint16_t    reg[8];
    uint16_t    flags;
    uint8_t     memory[64*1024];
} vm_t;

// int_num == INT_NONE or 0..7
int step(vm_t *vm,int int_num);
