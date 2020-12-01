#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // input items assumed 0 < input < 2020 
  int entries[2020];
  // initialize to 0
  for (int i = 0; i < 2020; i ++) {
    entries[i] = 0;
  }
  int entry;
  while(scanf("%d", &entry) == 1) {
    if(entries[2020 - entry] == 1) {
      printf("%d", entry * (2020 - entry));
      return 0;
    } 
    entries[entry] = 1;
  }
  return 1;
}
