#include "vm.h"

vm_inst *n_vm_inst(void) {

	vm_inst *vm = malloc(sizeof(vm_inst)); // Allocate memory for vm

	/* Allocate memory for the registers and VM RAM 
	*
	*  calloc: Allocates requested memory, sets it to 0, and returns the address
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

	/* Since we dont have a way of printing anything from the instruction set
	*  we should print the state of the VM before we destroy it.
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