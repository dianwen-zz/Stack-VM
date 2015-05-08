# Stack-VM

This is a simple stack-based virtual machine. Based on: http://blog.felixangell.com/virtual-machine-in-c/.

Instruction set:
 - PSH imm: pushes immediate value onto the stack
 - ADD: pops 2 elements off the stack and pushes on the sum
 - POP: pops top element off the stack and prints it
 - SET $t imm: $t = imm
 - HLT: halts execution
