#include <stdio.h>
#include "lvm.h"

#define INSTRUCTION_PTR 0
#define BASE_PTR 6
#define STACK_PTR 7
#define IVT 0xFFF0

typedef struct MemoryAccess{
    uint16_t address;
    uint8_t is_word;
} MemoryAccess;

uint16_t little_endian(uint16_t value)
{
    return ((value & 0xFF) << 8) | ((value >> 8) & 0xFF);
}
void store_endian(uint8_t* location,uint16_t value)
{
    *((uint16_t*)location) = value;
}
uint16_t pop_byte(vm_t *vm)
{
    uint8_t bytes = vm->memory[vm->reg[INSTRUCTION_PTR]];
    vm->reg[INSTRUCTION_PTR] += 1;
    return bytes;
}
uint16_t pop_word(vm_t *vm){
    uint16_t words =  *((uint16_t *)&vm->memory[vm->reg[INSTRUCTION_PTR]]);
    words |= vm->memory[vm->reg[INSTRUCTION_PTR] + 1] << 8; 
    vm->reg[INSTRUCTION_PTR] += 2;
    //printf("Popped Word: %04X\n", words);
    return words;
}
uint16_t pop_stack(vm_t *vm)
{
    uint16_t words = *((uint16_t *)&vm->memory[vm->reg[STACK_PTR]]);
    vm->reg[STACK_PTR] += 2;
    return words;
}   
void push_stack(vm_t *vm,uint16_t value)
{
    vm->reg[STACK_PTR] -= 2;
    store_endian(&vm->memory[vm->reg[STACK_PTR]],value);
}
void setflags(vm_t *vm,uint16_t r)
{
    int16_t signed_r = (int16_t) r;
    uint16_t updated_flags = 0;
    if (signed_r > 0)
    {
        updated_flags |= FLAG_POSITIVE;
    }
    if (signed_r == 0)
    {
        updated_flags |= FLAG_ZERO;
    }
    if (signed_r < 0)
    {
        updated_flags |= FLAG_NEGATIVE;
    }
    vm->flags &= ~(0x7);
    vm->flags |= updated_flags;
}
MemoryAccess memory_access(vm_t *vm)
{
    MemoryAccess access;
    uint8_t reg_mod_byte = pop_byte(vm);
    uint8_t opcode = reg_mod_byte >> 6;
    // uint8_t W = (reg_mod_byte >> 5) & 1;
    // uint8_t I = (reg_mod_byte >> 4) & 1;
    // uint8_t D = (reg_mod_byte >> 3) & 1;
    uint8_t reg = reg_mod_byte & 0x7;
    access.address = 0;  
    access.is_word = 0; 

    if (opcode == 0) {
        access.address = vm->reg[reg]; // Memory address is register NNN
    } else if (opcode == 1) {
        access.address = vm->reg[BASE_PTR] + vm->reg[reg]; // Memory address is sum of BP(R6) and register NNN
    } else if (opcode == 2) {
        access.address = vm->reg[STACK_PTR] + vm->reg[reg]; // Memory address is sum of SP(R7) and register NNN
    } else if (opcode == 3) {
        uint16_t immediate = pop_word(vm);
        access.address = immediate + vm->reg[reg];  // Memory address is sum of the immediate word and register NNN
    }
    return access;
}
int instructions(vm_t* vm) {
	uint8_t instruction = pop_byte(vm);
    uint8_t opcode = instruction >> 6;
    uint8_t reg_numA = (instruction >> 3) & 0x7;
    uint8_t reg_numB = instruction & 0x7;
	if (reg_numA == 0 && reg_numB == 0) {
		if (opcode == 0) {
			vm->reg[INSTRUCTION_PTR] = pop_stack(vm); //return from function call
            if (vm->flags & FLAG_INT_ENABLE)
            {
               vm->flags = pop_stack(vm);
            }
            

		} else if (opcode == 1) {
			uint8_t jump_byte = pop_byte(vm); //conditional jump relative
            uint8_t jump_mask = (jump_byte >> 5) & 0x7;
            int8_t location = jump_byte & 0x1F;
            location <<= 3;
            location >>= 3;
            if (jump_mask & vm->flags)
            {
                vm->reg[INSTRUCTION_PTR] += location;
            }
		} else if (opcode == 2) {
			uint16_t address_location = pop_word(vm);
            vm->reg[INSTRUCTION_PTR] = address_location; //jump to absolute address

		} else if (opcode == 3) {
			uint16_t address_location = pop_word(vm);
            push_stack(vm,vm->reg[INSTRUCTION_PTR]);
            vm->reg[INSTRUCTION_PTR] = address_location; //call to absolute address
			
		}
	} else if (reg_numA == 0) {
		if (opcode == 0) {
			MemoryAccess access = memory_access(vm);
            uint16_t data;
            if (access.is_word)
            {
                data = *((uint16_t *)&vm->memory[access.address]); //load register DDD from memory
            } else {
                data = vm->memory[access.address];
            }
            vm->reg[reg_numB] = data; 
            
		} else if (opcode == 1) {
			MemoryAccess access = memory_access(vm);

            if (access.is_word)
            {
                store_endian(&vm->memory[access.address],vm->reg[reg_numB]); //store register SSS to memory
            }
            else
            {
                vm->memory[access.address] = vm->reg[reg_numB]; 
            }
		} else if (opcode == 2) {
			MemoryAccess access = memory_access(vm); //store address to register DDD
            vm->reg[reg_numB] = access.address;
		} else if (opcode == 3) {
			return RESULT_ILLEGAL; //illegal instruction codes
		}
	} else if (reg_numB == 0) {
		if (opcode == 0) {
		    uint16_t load_immediate = pop_word(vm); //load immediate to register DDD
            //printf("Load Immediate Value: %04X\n", load_immediate);
            //printf("Register Value before: %04X\n", vm->reg[reg_numA]);
            vm->reg[reg_numA] = load_immediate; //storing it in load_immediate so we can update the set_flags with it
            //printf("Register Value after: %04X\n", vm->reg[reg_numA]);
            setflags(vm,load_immediate); //indicates arithmetic flags are updated

		} else if (opcode == 1) {
            uint8_t shift_byte = pop_byte(vm);
            uint8_t D = (shift_byte >> 7) & 1;
            uint8_t A = (shift_byte >> 6) & 1;
            uint8_t R = (shift_byte >> 5) & 1;
            uint8_t count_reg = shift_byte & 0x1F;
            uint8_t shifting = count_reg;
            if (R)
            {
                if (count_reg > 7)
                {
                    return RESULT_ILLEGAL;
                }
                shifting = vm->reg[count_reg];
            }

             if (A)
            {
                if (D)
                {
                    vm->reg[reg_numA] =((int16_t) vm->reg[reg_numA]) >> shifting; //arithmetic shift
                }else
                {
                 vm->reg[reg_numA] =((int16_t) vm->reg[reg_numA]) << shifting; //logical shift
                }
                
            } else{
                if (D)
                {
                    vm->reg[reg_numA] = vm->reg[reg_numA] >> shifting; //shift right
                } else
                {
                    vm->reg[reg_numA] = vm->reg[reg_numA] << shifting; //shift left
                }
            }
            
            
            setflags(vm,vm->reg[reg_numA]);

		} else if (opcode == 2) {
			vm->reg[reg_numA] = ~(vm->reg[reg_numA]); //complement register RRR
            setflags(vm,vm->reg[reg_numA]); //indicates arithmetic flags are updated

		} else if (opcode == 3) {
			vm->reg[reg_numA] = -(vm->reg[reg_numA]); //negate register RRR
            setflags(vm,vm->reg[reg_numA]); //indicates arithmetic flags are updated

		}
	} else {
		if (opcode == 0) {
            vm->reg[reg_numA] = vm->reg[reg_numB]; //move from register SSS to register DDD
            setflags(vm,vm->reg[reg_numA]); //indicates arithmetic flags are updated

		} else if (opcode == 1) {
            vm->reg[reg_numA] += vm->reg[reg_numB]; //add register SSS to register DDD
            setflags(vm,vm->reg[reg_numA]); //indicates arithmetic flags are updated

		} else if (opcode == 2) {
			vm->reg[reg_numA] &= vm->reg[reg_numB]; //bitwise AND register SSS with register DDD
            setflags(vm,vm->reg[reg_numA]); //indicates arithmetic flags are updated

		} else if (opcode == 3) {
		    vm->reg[reg_numA] ^= vm->reg[reg_numB]; //bitwise XOR register SSS with register DDD
            setflags(vm,vm->reg[reg_numA]); //indicates arithmetic flags are updated

		}
	}
	
	return RESULT_CONTINUE;
}

int execute_interrupts(vm_t *vm,int int_num)
{
    push_stack(vm,vm->flags); //flags are pushed on stack
    push_stack(vm,vm->reg[INSTRUCTION_PTR]); //IP is pushed on the stack
    vm->flags &= ~FLAG_INT_ENABLE; //Flag int enable is cleared
    uint16_t isr_address = IVT + int_num; // the (ISR) address is retrieved from the(IVT) based on the interrupt number
    vm->reg[INSTRUCTION_PTR] = isr_address; //the IP is set to the ISR address retrieved. 

    return RESULT_CONTINUE;

}

int step(vm_t* vm,int int_num) {
    if (int_num != INT_NONE && vm->flags & FLAG_INT_ENABLE)
    {
        return execute_interrupts(vm,int_num);
    }
    
    return instructions(vm);
}