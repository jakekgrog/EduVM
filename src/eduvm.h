#ifndef EDUVM_H
#define EDUVM_H

#include <stdio.h>
#include <stdint.h>

#include "opcodes.h"

#define NUM_REGISTERS 5
#define MEMORY_WORD_COUNT 64

typedef int32_t word; /* Define a word as a 32 bit integer */

/* VM instance struct */
typedef struct
{
	word *registers;   // Registers
	word *memory;      // RAM
	word ip;           // Instruction Pointer
	int memInUse;      // Counter for the amount of memory in use
} vm_inst;

/* Create new VM instance */
vm_inst *n_vm_inst(void);

/* Destroy VM instance */
void d_vm_inst(vm_inst *vm);

/* Load program instructions into memory */
void vm_load(vm_inst *vm, word *instruction, int count);

/* Execute an instruction */
void vm_instruct_exec(vm_inst *vm, word *instruction);

/* Start instruction execution from memory */
void vm_inst_run(vm_inst *vm);

#endif