#include <stdio.h>
#include <string.h>

#define INPUT_LENGTH 16
#define SEATS 1000
#define ROW_BITS 7
#define COLUMN_BITS 3

int seats[SEATS];

int calc_id(char ticket[INPUT_LENGTH]) {
  int i;
  int row = ticket[0] == 'B'? 1: 0;
  int column = ticket[ROW_BITS] == 'R'? 1: 0;

  for(i=1; i < ROW_BITS; i++) {
    row = row << 1;
    if(ticket[i] == 'B') row++;
  }
  for(++i; i < 10; i++) {
    column = column << 1;
    if(ticket[i] == 'R') column++;
  }
  return row * (ROW_BITS + 1) + column;
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
