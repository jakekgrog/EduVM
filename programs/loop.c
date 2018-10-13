#include "../src/eduvm.h"

int main() {
	word program[] = {
		0x0A000006, // SET register A to 1
		0x0A001006, // SET register B to 1
		0x03000001, // ADD register B to register A
		0x0700000F, // IFN register A regiser B
		0x05007000, // JMP to instruciton 2
	};

	vm_inst *vm = n_vm_inst();
	vm_load(vm, program, 5);
	vm_inst_run(vm);
	d_vm_inst(vm);

	return EXIT_SUCCESS;
}