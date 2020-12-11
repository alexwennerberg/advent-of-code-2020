#include <stdio.h>

#define INPUT_LENGTH 98

int joltages[INPUT_LENGTH];

int cmpfunc (const void * a, const void * b) {
     return ( *(int*)a - *(int*)b );
}

int main() {
  char input[8];
  int i = 0;
  while (fgets(input, 8, stdin)) {
    joltages[i] = atoi(input);
    i++;
  }
  qsort(joltages, INPUT_LENGTH, sizeof(int), cmpfunc);
  int last = 0;
  int freq[4] = {0};
  for(i=0; i<INPUT_LENGTH; i++) {
    freq[joltages[i]-last]++;
    last = joltages[i];
  }
  freq[3]++; // device voltage
  printf("%d", freq[1] * freq[3]);

}
