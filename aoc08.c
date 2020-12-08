#include <stdio.h>

#define ACC 0
#define JMP 1
#define NOP 2

struct instr {
  int code;
  int val;
  int ran;
};

struct instr bootcode[1024];
char instruction[32];
int flipped = -1;

int flip_instr(int j) {
  /* printf("flipping %d\n", j); */
  if(bootcode[j].code == JMP) {
    bootcode[j].code = NOP;
  } else if(bootcode[j].code == NOP) {
    bootcode[j].code = JMP;
  }
  flipped = j;
}
int reset_flip_instr() {
  if(flipped > -1){ // unflip
    /* printf("un"); */
    flip_instr(flipped);
  }
  int i = 0;
  for(i; i<1024; i++) {
    // reset computer
    bootcode[i].ran = 0;
  }
  flipped++;
  if((bootcode[flipped].code == JMP) || (bootcode[flipped].code == NOP)) {
    flip_instr(flipped);
  } 
}

int main() {
  int i = 0;
  // generate program
  while(fgets(instruction, 32, stdin)) { // \0 and \n i think
    int code = -1;
    if(strncmp("acc", instruction, 3) == 0){
      code = ACC;
    } else if(strncmp("jmp", instruction, 3) == 0){
      code = JMP;
    } else if(strncmp("nop", instruction, 3) == 0){
      code = NOP;
    }
    char* substr = malloc(10);
    strncpy(substr, instruction+4, 8);
    int val = atoi(substr);
    struct instr tmp = {code, val, 0};
    bootcode[i] = tmp;
    i++;
  }

  // execute program
  int p = 0;
  int accumulator = 0;
  int first_run = -1;
  while(1) {
    if(bootcode[p].ran){
      // Part 1
      if(first_run){
        printf("%d\n", accumulator);
      }
      p = 0;
      accumulator = 0;
      reset_flip_instr();
      first_run = 0;
      continue;
    } else  {
      bootcode[p].ran = 1;
    }
    int code= bootcode[p].code;
    int val = bootcode[p].val;
    /* printf("p%d a%d c%d v%d\n",p, accumulator, code, val); */
    if(code == ACC){
      accumulator += val;
    }
    if( code == JMP){
      p += val;
    } else {
      p++;
    }
    if(p == 1024 ){
      printf("%d\n", accumulator);
      return;
    }
  }
}
