#include <stdio.h>
#include <stdbool.h>
#include "instructions.h"
#include "program.h"

static const int stackSize = 256;
static const int registerSize = 32;

bool running = true;
int pc = 0;
int sp = -1;
int stack[stackSize];
int registers[registerSize];

int fetch() {
  return program[pc];
}

void eval(int instruction) {
  switch (instruction) {
    case HLT: {
      running = false;
      break;
    }
    case PSH:  {
      stack[++sp] = program[++pc];
      break;
    }
    case POP: {
      int value = stack[sp--];
      printf("Popped %d\n", value);
    }
    case ADD: {
      int valueA = stack[sp--];
      int valueB = stack[sp--];
      int sum = valueA + valueB;
      stack[++sp] = sum;
      break;
    }
    case SET: {
      int regNumber = program[++pc];
      int regValue = program[++pc];
      registers[regNumber] = regValue;
      break;
    }
    case MOVE: {
      int regA = program[++pc];
      int regB = program[++pc];
      registers[regB] = registers[regB];
      break;
    }
  }
}

int main() {
  while(running) {
    eval(fetch());
    pc++;
  }
  return 0;
}
