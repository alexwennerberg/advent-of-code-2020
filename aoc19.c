#include <stdio.h>

#define image_size 10

struct Frame {
  char imgseg[image_size][image_size];
  int id;
};

void setsides(struct Frame *f) {
  int y=0;
  for(x=0;x<image_size; x++) {

  }
  
}
void frameprint(struct Frame *f) {
  int x=0;
  int y=0;
  for(y=0;y<image_size; y++) {
    for(x=0;x<image_size; x++) {
      printf("%c", f -> imgseg[y][x]);
    }
    printf("\n");
  }
}
int parse_tile_line(char* input) {
  int i;
  int result = 0;
  for(i=5; i<9; i++) {
    result = result * 10 + input[i] - '0';
  }
  return result;
}

int main() {
  char line[image_size + 3];
  struct Frame frames[11];
  int y = 0;
  int n = 0;
  while(fgets(line, image_size + 3, stdin)) {
    struct Frame f;
    if(line[0] == 'T'){ 
      f.id = parse_tile_line(line);
      y = 0;
      n++;
    } else if (line[0] == '#' || line[0] == '.') {
      int x;
      for(x=0;x<image_size; x++) {
        f.imgseg[y][x] = line[x];
      }
      frameprint(&f);
    }
    y++;
  }
}
