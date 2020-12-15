#include <stdio.h>

#define INPUT_LENGTH 98

int joltages[INPUT_LENGTH];

int cmpfunc (const void * a, const void * b) {
     return ( *(int*)a - *(int*)b );
}


unsigned long long int paths[256];

unsigned long long int get_value(int v) {
  if (v < 0) {
    return 0;
  } else if (v == 0) {
    return 1;
  }else {
    return paths[v];
  }
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
  // Part 1
  printf("%d\n", freq[1] * freq[3]);
  // Part 2
  int device_voltage = joltages[INPUT_LENGTH] + 3;
  int possible_arrangements = 1;

  int value;
  for(i=0; i<=INPUT_LENGTH; i++) {
    if(i == INPUT_LENGTH) {
      value = value + 3;
    } else {
      value = joltages[i];
    }
    paths[value] = get_value(value-2) + get_value(value-1) + get_value(value-3);
  }
  printf("%lld\n", paths[value]);
}
