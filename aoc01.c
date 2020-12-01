#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TARGET 2020
#define MAX_LENGTH 200

int main() {
  // input items assumed 0 < input < TARGET  and len(items) < MAX_LENGTH
  int entrycount[TARGET];
  int entries[MAX_LENGTH];
  // initialize to 0
  for (int i = 0; i < TARGET; i ++) {
    entrycount[i] = 0;
  }
  int entry;
  int c;
  while(scanf("%d", &entry) == 1) {
    if(entrycount[TARGET - entry] != 0) {
      printf("%d\n", entry * (TARGET - entry));
    } 
    entries[c] = entry;
    entrycount[entry] = 1;
    c++;
  }

  // brute force part 2
  for (int i = 0; i < c ; i ++) {
    for (int j = i; j < c; j++) {
      for (int k = j; k < c; k ++) {
        if ((entries[i] + entries[j] + entries[k]) == TARGET) {
          printf("%d\n", entries[i] * entries[j] * entries[k]);
          return 0;
        }
      }
    }
  }
  return 1;
}
