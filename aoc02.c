#include <stdio.h>
#include <string.h>

#define MIN 0
#define MAX 1
#define CHAR 2
#define PW 3

int main() {
  char input[32];
  int valid_one = 0;
  int valid_two = 0;
  while(fgets(input, 32, stdin)) {
    char c;
    int mode = 0; 
    int min = 0;
    int max = 0;
    char req; 
    int count = 0;

    int pp = 1;
    int valid_pos = 0;
    for(int i = 0; 1; i++ ) {
      c = input[i];
      if(c == ' ' || c == '-'){
        mode++;
      } else if(c == ':'){
        continue;
      } else  if(mode == MIN){
          min = min * 10 + c - '0';
      } else if(mode == MAX){
          max = max * 10 + c - '0';
      } else if(mode == CHAR){
          req = c;
      } else if(mode == PW){
        if(c == req){
          count ++;
          if(pp == min || pp == max){
            valid_pos++;
          }
        }
        if(c == '\0') {
          break;
        }
        pp++;
      }
    }
    if(count <= max && count >= min){
      valid_one++;
    }
    if(valid_pos == 1) {
      valid_two++;
    }
  }
  // Part 1
  printf("%d\n", valid_one);
  // Part 2
  printf("%d\n", valid_two);
  return 0;
}
