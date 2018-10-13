#ifndef OPCODES_H
#define OPCODES_H

#define OP_LD	0x01 //Load value from memory
#define OP_STR	0x02 // Set memory content to second args value
#define OP_ADD	0x03 // Add arg a and arg b
#define OP_SUB	0x04 // Subtract arg A and arg B
#define OP_JMP	0x05 // Jump to another location in memory
#define OP_IF	0x06 // If arg A == arg B, execute next instruction else skip
#define OP_IFN	0x07 // If arg A != arg B, execute next instruction else skip
#define OP_INC	0x08 // Increment arg A by 1
#define OP_DEC	0x09 // Decrement arg A by 1
#define OP_SET	0x0A // Set register arg A to value of arg B
#define OP_MUL	0x0B // Multiply arg A by arg B
