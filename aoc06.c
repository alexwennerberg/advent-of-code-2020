#include <stdio.h>

int countb(int n) { 
    unsigned int count = 0; 
    while (n) { 
      count += n & 1; 
      n >>= 1; 
    } 
  return count; 
} 

int main() {
  int total_one = 0;
  int total_two = 0;
  int group_one = 0;
  int group_two = -1;
  int person = 0;
  char last_char = ' ';
  char c;
  while ((c = getc(stdin))){
    if((last_char == '\n' && c == '\n') || c == EOF) {
      total_one += countb(group_one);
      total_two += countb(group_two);
      group_one = 0;
      group_two = -1;
      if(c == EOF){
        break;
      }
    } else if(c == '\n') {
      group_one |= person;
      group_two &= person;
      person = 0;
    } else {
      person |= (1 << (c - 97));
    }
    last_char = c;
  }
  // Part 1
  printf("%d\n", total_one);
  // Part 2
  printf("%d\n", total_two);
}
