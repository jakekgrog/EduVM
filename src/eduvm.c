#include "eduvm.h"

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
		printf("%c: %d ", 65 + i, vm->registers[i]);
	}

	printf("\nPrinting Memory...\n");

	for (i = 0; i < MEMORY_WORD_COUNT; i++) {
		word *memVal = &vm->memory[i];
		printf("%#x ", *memVal);
	}
	printf("\n");

	free(vm->registers);
	free(vm->memory);
	free(vm);
}

void vm_load(vm_inst *vm, word *instructions, int instructionCount) {
	int i;

	/* Load the instructions into memory */
	for (i = 0; i < instructionCount; i++) {
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
	
	/* Check ByteCodeExplanation for an explanation of the following 3 statements */
	word opcode = *instruction >> 24;
	word a_arg = (*instruction >> 12) & 2047;
	word b_arg = *instruction & 2047;

	word *valA;
	word *valB;

	word litA;
	word litB;

	valA = get_val(vm, a_arg, &litA);
	valB = get_val(vm, b_arg, &litB);

	switch(opcode) {
		case OP_SET:
		{
			*valA = *valB;
			printf("SET %#x %#x\n", a_arg, b_arg);
			break;
		}
		case OP_ADD:
		{
			*valA = *valA + *valB;
			printf("ADD %#x %#x\n", *valA, *valB);
			break;
		}
		case OP_SUB:
		{
			*valA = *valA - *valB;
			printf("SUB %#x %#x", *valA, *valB);
			break;
		}
		case OP_MUL:
		{
			*valA = *valA * *valB;
			printf("MUL %#x %#x\n", *valA, *valB);
			break;
		}
		case OP_JMP:
		{
			vm->ip = *valA - 1; // Subtract 1 to avoid IP increment in vm_inst_run
			printf("JMP %#x\n", *valA);
			break;
		}
		case OP_STR:
		{
			vm->memory[*valA + vm->memInUse] = *valB;
			printf("STR %#x %#x\n", *valA, *valB);
			break;
		}
		case OP_INC:
		{
			*valA = *valA + 1;
			printf("INC %#x\n", *valA);
			break;
		}
		case OP_DEC:
		{
			*valA = *valA - 1;
			printf("DEC %#x\n", *valA);
			break;
		}
		case OP_IFN:
		{
			if (*valA == *valB){
				vm->ip++;
			}
			printf("IFN %#x %#x\n", *valA, *valB);
			break;
		}
	}
}

void vm_inst_run(vm_inst *vm) {

	while((vm->ip) < (vm->memInUse)) {
		vm_instruct_exec(vm, &vm->memory[vm->ip]);
		vm->ip++;
	}
}