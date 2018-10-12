#include "vm.h"

vm_inst *n_vm_inst(void) {

	vm_inst *inst = malloc(sizeof(vm_inst)); // Allocate memory for vm

	/* Allocate memory for the registers and VM RAM 
	*
	*  calloc: Allocates requested memory, sets it to 0, and returns a pointer
	*          - Takes 2 arguments:
	*              - Number of memory locations to allocate (elements)
	*              - Size of each element 
	*/
	inst->registers = calloc(NUM_REGISTERS, sizeof(word));
	inst->memory = calloc(MEMORY_WORD_COUNT, sizeof(word));
	

	/* Set instruction pointer to 0 (location of first instruction) and 
	*  the amount of memory in use to 0
	*/
	inst->ip = 0;
	inst->memInUse = 0;

	return inst;
}