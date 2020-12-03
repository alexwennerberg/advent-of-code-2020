#include <stdio.h>
#include <string.h>

#define INPUT_LENGTH 323
#define INPUT_WIDTH 31

int main() {
  char slope[INPUT_LENGTH][INPUT_WIDTH]; 
  int row = 0;
  char input[INPUT_WIDTH];
  while(fgets(input, INPUT_WIDTH + 2, stdin)) { // \0 and \n i think
    for(int c=0; c<INPUT_WIDTH; c++ ){
      slope[row][c] = input[c];
    }
    row++;
  }
  int x = 0;
  int y = 0;
  int trees = 0;
  while(y < INPUT_LENGTH - 1){
    x = x + 3;
    if(x >= INPUT_WIDTH){
      x = x - INPUT_WIDTH;
    }
    y = y + 1;
    if(slope[y][x] == '#'){
      trees++;
    }
  }
  // Part 1
  printf("%d", trees);
}
