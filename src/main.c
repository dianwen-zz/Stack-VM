#include <stdio.h>
#include "instructions.h"
#include "program.h"


int pc = 0;

int fetch() {
  return program[pc];
}

int main() {
  printf("%d", program[0]);
  return 0;
}
