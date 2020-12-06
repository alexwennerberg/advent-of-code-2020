#include <stdio.h>

#define INPUT_LENGTH 16
#define SEATS 1024
#define ROW_BITS 7
#define COLUMN_BITS 3

int main() {
  int question_count[26] = {0}; // a-z
  char last_char = ' ';
  /* char answers[256]; */
  /* answers[i] = '\0'; */
  int total = 0;
  char c;
  int people = 0;
  while ((c = getc(stdin))){
    question_count[c - 97] ++; // TODO bit stuff
    if((last_char == '\n' && c == '\n') || c == EOF) {
      int i;
      for(i=0; i < 26; i++) {
        if(question_count[i] == people){
          total++;
        }
        question_count[i] = 0;
      }
      people = 0;
      if(c == EOF){
        break;
      }
    } else if(c == '\n') {
      people ++;
    }
    last_char = c;
  }
  printf("%d\n", total);
}
