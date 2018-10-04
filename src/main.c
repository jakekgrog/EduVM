#include <stdio.h>
#include <stdbool.h>

typedef enum {
	PSH,
	INC,
	PNT,
	ADD,
	POP,
	GOTO,
	HLT
} InstructionSet;

typedef enum {
	A, B, C, D, E, F,
	SP,
	IP,
	NUM_REGISTERS
} Registers;

const int program[] = {
	PSH, 1,   // Push value to the stack
	ADD,      // Add top of stack to register[A]
	PNT,      // Print the value in register[A]
	GOTO, 0,  // Jump to location (set instruction pointer)
	POP,      // Pop a value from the top of the stack
	HLT       // Halt the program
};

#define sp (registers[SP])
#define ip (registers[IP])

bool running = true;

int stack[256];
int registers[NUM_REGISTERS];

int fetch() {

	return program[ip];
}

void eval(int instr) {
	switch (instr) {
		case HLT: {
			running = false;
			break;
		}
		case PSH: {
			sp++;
			stack[sp] = program[++ip];
			break;
		}
		case PNT: {
			printf("%d\n", registers[A]);
			break;
		}
		case POP: {
			sp--;

			break;
		}
		case ADD: {
			int a = stack[sp--];
			int result = a;
			registers[A] = registers[A] + result;
			sp++;
			break;
		}
		case GOTO: {
			ip = program[ip + 1];
			break;
		}
	}
}

int main() {
	while (running) {
		eval(fetch());
		ip++;
	}
}

