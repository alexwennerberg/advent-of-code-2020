#include <stdio.h>

#define LINE_SIZE 64
#define MEMORY_SIZE 99999
#define MASK_SIZE 36

typedef char bitmask[MASK_SIZE];

long long int memory[MEMORY_SIZE];

void parse_mask(char* input_line, char* dest) {
    int i;
    for(i=0; i<MASK_SIZE; i++) {
      dest[i] = input_line[i+7];
    }
}

void parse_mem(char* input_line, int* index, long long int* target) {
    int i;
    for(i=4; input_line[i] != ']'; i++) {
      *index = *index * 10 + input_line[i]- '0';
    }
    for(i+=4; input_line[i] != '\n'; i++) {
      *target = *target * 10 + input_line[i] - '0';
    }
}

long long int apply_mask(long long int target, bitmask mask) {
  int i;
  for(i=0; i<MASK_SIZE; i++) {
    if(mask[i] == '1') {
      target |= (1ULL << (MASK_SIZE - i - 1));
    } else if(mask[i] == '0') {
      target &= ~(1ULL << (MASK_SIZE - i - 1));
    } // X -> Do nothing
  }
  return target;
}

long long int get_memory_sum() {
  int i;
  long long int result = 0;
  for(i=0; i<MEMORY_SIZE; i++) {
    result += memory[i];
  }
  return result;
}

int main () {
  char input_line[LINE_SIZE];
  bitmask mask;
  while(fgets(input_line, LINE_SIZE, stdin)) {
    int index = 0;
    long long int  target = 0;
    if ( input_line[1] == 'a' ) { // Mask line
      parse_mask(input_line, mask);
    } else if ( input_line[1] == 'e' ) { // memory line
      parse_mem(input_line, &index, &target);
      memory[index] = apply_mask(target, mask);
    }
  }
  printf("%lld\n", get_memory_sum());
}
