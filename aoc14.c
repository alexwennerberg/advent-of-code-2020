#include <stdio.h>

#define LINE_SIZE 64
#define MEMORY_SIZE 9999999
#define MASK_SIZE 36

typedef char bitmask[MASK_SIZE];

long long int memory_v1[MEMORY_SIZE];
long long int memory_v2[MEMORY_SIZE];

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

long long int get_memory_sum(int version) {
  int i;
  long long int result = 0;
  for(i=0; i<MEMORY_SIZE; i++) {
    if(version == 1) {
      result += memory_v1[i];
    } else if(version == 2) {
      result += memory_v2[i];
    }
  }
  return result;
}

/* a nightmare */
void apply_memory_v2(int index, long long int target, bitmask mask) {
  int i;
  int newindex = index;
  for(i=0; i<MASK_SIZE; i++) {
      if(mask[i] == '1') {
        newindex |= (1ULL << (MASK_SIZE - i - 1));
      } else if(mask[i] == '0') {
      } else if (mask[i] == 'X') {
        mask[i] = '0';
        int j;
        bitmask newmask1;
        bitmask newmask2;
        for (j=0; j<MASK_SIZE; j++) {
          newmask1[j] = mask[j];
        }
        newmask1[i] = '0';
        index &= ~(1ULL << (MASK_SIZE - i - 1));
        apply_memory_v2(index, target, newmask1);
        for (j=0; j<MASK_SIZE; j++) {
          newmask2[j] = mask[j];
        }
        newmask2[i] = '1';
        apply_memory_v2(index, target, newmask2);
      }
    }
    printf("%d %d %lld %s\n", index, newindex, target, mask);
    memory_v2[newindex] = target;
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
      memory_v1[index] = apply_mask(target, mask);
      bitmask v2_mask;
      int i;
      for (i=0; i<MASK_SIZE; i++) {
        v2_mask[i] = mask[i];
      }
      apply_memory_v2(index, target, v2_mask);
    }
  }
  printf("%lld\n", get_memory_sum(1));
  printf("%lld\n", get_memory_sum(2));
}
