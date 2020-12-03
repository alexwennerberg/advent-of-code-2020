#include <stdio.h>
#include <string.h>

#define INPUT_LENGTH 323
#define INPUT_WIDTH 31

int get_trees(char slope[INPUT_LENGTH][INPUT_WIDTH], int right, int down) {
    int x = 0;
    int y = 0;
    int trees = 0;
    while(y < INPUT_LENGTH - 1){
      x = x + right;
      if(x >= INPUT_WIDTH){
        x = x - INPUT_WIDTH;
      }
      y = y + down;
      if(slope[y][x] == '#'){
        trees++;
      }
    }
    return trees;
}

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
  

  int slope31 = get_trees(slope, 3, 1);
  // Part 1
  printf("%d\n", slope31);
  int result = slope31 
    * get_trees(slope, 1, 1) 
    * get_trees(slope, 5, 1) 
    * get_trees(slope, 7, 1) 
    * get_trees(slope, 1, 2);
  // Part 2
  printf("%d", result);

}
