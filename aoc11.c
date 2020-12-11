#include <stdio.h>

#define EMPTY 'L'
#define OCCUPIED '#'
#define FLOOR '.'

/* #define WIDTH 90 */
/* #define HEIGHT 91 */
#define WIDTH 10
#define HEIGHT 10

char seats[HEIGHT][WIDTH];

int swap_seats(int mode) { // returns n occupied
  char newseats[HEIGHT][WIDTH];
  int x, y;
  int occupied = 0; 
  for(y=0;y<HEIGHT;y++) {
    for(x=0;x<WIDTH;x++) {
      char state = seats[y][x];
      int neighbors[8][2] = {
        {-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, /* 0 0 */ {0, 1}, {1, -1}, {1, 0}, {1, 1}
      };
      int n;
      int occupied_adjacent = 0;
      for(n=0; n < 8; n++) {
        int xdiff =  neighbors[n][0];
        int ydiff =  neighbors[n][1];
        if(
            x+xdiff >= 0 
            && x+xdiff < WIDTH 
            && y+ydiff >= 0 
            && y+ydiff < HEIGHT 
            && seats[y+ydiff][x+xdiff] == OCCUPIED
            ) {
          occupied_adjacent++;
        }
      }
      char new_state;
      if(state == EMPTY && occupied_adjacent == 0) {
        new_state = OCCUPIED;
      } else  if(state == OCCUPIED && occupied_adjacent >= 4) {
        new_state = EMPTY;
      } else {
        new_state = state;
      }
      if(new_state == OCCUPIED){
        occupied++;
      }
      newseats[y][x] = new_state;
    }
  }
  // copy over
  for(y=0;y<HEIGHT;y++) {
    for(x=0;x<WIDTH;x++) {
      seats[y][x] = newseats[y][x];
    }
  }
  return occupied;
}

int print_seats() {
  int x, y;
  for(y=0;y<HEIGHT;y++) {
    for(x=0;x<WIDTH;x++) {
      printf("%c", seats[y][x]);
    }
    printf("\n");
  }
  printf("\n");
}

int main () {
  int x = 0;
  int y = 0;
  char c;
  while(( c = getc(stdin))) {
    if(x > WIDTH) {
      x = 0;
      y++;
    }
    seats[y][x] = c;
    x++;
    if(c == EOF){
      break;
    }
  }
  int last = -1;
  int occ;
  int i;
  while(occ != last ) {
    last = occ;
    // specify part number
    occ = swap_seats(1);
    print_seats();
    printf("%d\n", occ);
  }
  /* while(swap_seats(2) != last) { */
  /*   printf("%d\n", occ); */
    /* print_seats(); */
  /* } */
}
