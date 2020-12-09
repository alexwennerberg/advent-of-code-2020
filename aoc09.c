#include <stdio.h>
#include <string.h>

#define PREAMBLE 25

int xmas[1024];

int main() {
  int i = 0;
  // generate program
  char* input[32];
  while(fgets(input, 32, stdin)) { // \0 and \n i think
    int value = atoi(input);
    xmas[i] = value;
    i++;
    if(i > PREAMBLE){
      int sums = 0;
      int j, k;
      for(j=i-PREAMBLE-1; j < i; j++) {
        for(k=i-PREAMBLE-1; k < i; k++) {
          if(xmas[j]+xmas[k] == value && xmas[j] != xmas[k]) {
            sums = 1;
          }
        }
      }
      if(!sums){
        printf("%d\n", value);
        return;
      }
    }
  }
}
