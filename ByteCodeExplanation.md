The format of byte codes in EduVM are as follows:

The instructions are 32-bit and are represendted as hexadecimal instructions:

__0x0A002006__

0A is the opcode. The opcodes are 1 byte codes (in this case 0000 1010)
002 is the first argument. These are 12-bits.
006 is the second argument. These are also 12-bits.

The values of argument 1 and 2 work as follows:

000 -> 004 These represent the 5 registers the VM uses. 
Register A -> Register E

005 -> FFF represent integer literals. 
0 -> 4095 

So the instruction 0x0A002006 means: SET register C to 1 (6 - 5)


Explanation of the logic in vm_instruct_exec

`word opcode = *instruction >> 24;`

Here I extract the opcode from the instruction, this is easier seen if we convert the instruction to binary

```
0000 1010 0000 0000 0010 0000 0000 0110
          |___________________________|
                     24-bits
```

If we right shift these bits out we'll be left with the opcode


`word arg_b = *instruction & 2047`

If we get the binary representation of 2047 we get

```
0000 0000 0000 0000 0000 1111 1111 1111 <-- This is 2047 in binary
0000 1010 0000 0000 0010 0000 0000 0110 <-- This is the instruction
```
If we perform a logical AND on the instruction with 2047 we're left with argument B

For `arg_a` we shift it right 12 bits to get argument A into the first 12 bits, then we logical AND it with 2047 to get its value

Any questions? Email me at jake.kgrogan@gmail.com
