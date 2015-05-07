#include <stdio.h>
#include "instructions.h"
#include "program.h"

static const int stackSize = 256;

bool running = 1;
int pc = 0;
int sp = -1;
int stack[stackSize];

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
      stack[++sp] = program[++ip];
      break;
    }
    case POP: {
      int value = stack[sp--];
      printf("Popped %d\n", value);
    }
    case ADD: {
      int value1 = stack[sp--];
      int value2 = stack[sp--];
      int sum = value1 + value2;
      stack[++sp] = sum;
      break;
    }
  }
}

int main() {
  while(running) {
    eval(fetch());
    ip++;
  }
  return 0;
}
