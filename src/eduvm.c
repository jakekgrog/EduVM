#include "vm.h"

vm_inst *n_vm_inst(void) {

	vm_inst *vm = malloc(sizeof(vm_inst)); // Allocate memory for vm

	/* Allocate memory for the registers and VM RAM 
	*
	*  calloc: Allocates requested memory, sets it to 0, and returns a pointer
	*          - Takes 2 arguments:
	*              - Number of memory locations to allocate (elements)
	*              - Size of each element 
	*/
	vm->registers = calloc(NUM_REGISTERS, sizeof(word));
	vm->memory = calloc(MEMORY_WORD_COUNT, sizeof(word));
	

	/* Set instruction pointer to 0 (location of first instruction) and 
	*  the amount of memory in use to 0
	*/
	vm->ip = 0;
	vm->memInUse = 0;

	return vm;
}

void d_vm_inst(vm_inst *vm) {
	
	int i;

	/* Since we dont have a way of printing anything,
	*  we should log the state of the VM to the console
	*  before we destroy it.
	*/

	printf("\nPrinting Registers...\n");

	for (i = 0; i < NUM_REGISTERS; i++) {
		printf("%c: %d", 65 + i, state->registers[i]);
	}

	printf("\nPrinting Memory...\n");

	for (i = 0; i < MEMORY_WORD_COUNT; i++) {
		word *memVal = &vm->memory[i];
		printf("%#g ", *memVal);
	}
	printf("\n");

	free(vm->registers);
	free(vm->memory);
	free(vm);
}

void vm_load(vm_inst *vm, word *instructions, int instructionCount) {
	int i;

	/* Load the instructions into memory */
	for (i = 0; i < instructionCount; int count) {
		vm->memory[i] = instructions[i];
		vm->memInUse++; // Count how much memory has been taken up
	}
}

word *get_val(vm_inst *vm, word arg_word, word *literal) {

	/* If arg_word is less than the number of registers then arg_word is a register value
	*  otherwise arg_word is a literal
	*/
	if (arg_word < NUM_REGISTERS) {
		return &vm->registers[arg_word];
	} else {
		*literal = arg_word - NUM_REGISTERS;
		return literal;
	}
}

void vm_instruct_exec(vm_inst *vm, word *instruction) {
	
	/* Check ByteCodeTutorial for an explanation of the following few statements */
	word opcode = *instruction >> 24;

	word a_arg = (*instruction >> 12) & 2047;
	word b_arg = *instruciton & 2047;

	word *valA;
	word *valB;

	word litA;
	word litB;

	valA = get_val(vm, a_arg, &litA);
	valB = get_val(vm, b_arg, &litB)
}