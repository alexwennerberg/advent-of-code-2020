#include <stdio.h>

#define INPUT_LENGTH 16
#define SEATS 1024
#define ROW_BITS 7
#define COLUMN_BITS 3

int seats[SEATS];

int calc_id(char ticket[INPUT_LENGTH]) {
  int i;
  int id = ticket[0] == 'B'? 1: 0;
  for(i=1; i < ROW_BITS; i++) {
    id = id << 1;
    if(ticket[i] == 'B') id++;
  }
  for(; i < ROW_BITS + COLUMN_BITS; i++) {
    id = id << 1;
    if(ticket[i] == 'R') id++;
  }
  return id;
}

int main() {
  char input[INPUT_LENGTH];
  while(fgets(input, INPUT_LENGTH, stdin)) { 
    seats[calc_id(input)] = 1;
  }
  int i = SEATS-1;
  while(seats[i] == 0)  i--;
  // Part 1
  printf("%d\n", i);
  while(seats[i] == 1)  i--;
  // Part 2
  printf("%d", i);
}
