#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define PASSPORT_LENGTH 256

int valid_passport(char passport[PASSPORT_LENGTH], int part) {
  int fields = 0;
  char field[4];
  char value[32];
  for(int c=0; passport[c] != '\0'; c++ ){
    if(passport[c] == ':'){
      fields++;
      field[0] = passport[c-3];
      field[1] = passport[c-2];
      field[2] = passport[c-1];
      field[3] = '\0';
      int i = 0;
      char p = passport[c];
      while(p != '\n' && p != '\0' && p != ' ') {
        if(p != ' ' && p != '\n' && p != ':'){
          value[i] = passport[c];
          i++;
        }
        c++;
        p = passport[c];
      }
      value[i] = '\0';
      if(part == 1){
        continue; // part 1, skip this validation
      }
      if(strcmp(field, "byr") == 0){
        int birth_year = atoi(value);
        if(birth_year > 2002 || birth_year <1920) {
          return 0;
        }
      } else if (strcmp(field, "iyr") == 0) {
        int issue_year = atoi(value);
        if(issue_year > 2020 || issue_year <2010) {
          return 0;
        }
      } else if (strcmp(field, "eyr") == 0) {
        int exp_year = atoi(value);
        if(exp_year < 2020 || exp_year >2030) {
          return 0;
        }
      } else if (strcmp(field, "hgt") == 0) {
        if(value[2] == 'i' && value[3] == 'n'){
          value[2] == '\0';
          int height = atoi(value);
          if(height > 76 || height < 59) {
            return 0;
          }
        } else if(value[3] == 'c' && value[4] == 'm') {
          value[3] == '\0';
          int height = atoi(value);
          if(height > 193 || height < 150) {
            return 0;
          }
        } else {
          return 0;
        }
      } else if (strcmp(field, "hcl") == 0) {
        int j;
        if(value[0] != '#' || strlen(value) != 7) {
          return 0;
        }
        for(j=1; value[j] != '\0'; j++) {
          char ch = value[j];
          if (!((ch >= '0' && ch <= '9') ||
               (ch >= 'a' && ch <= 'f'))) {
            return 0;
          }
        }
      } else if (strcmp(field, "ecl") == 0) {
        if(strcmp(value, "amb") == 0){
        } else if(strcmp(value, "blu") == 0){
        } else if(strcmp(value, "brn") == 0){
        } else if(strcmp(value, "gry") == 0){
        } else if(strcmp(value, "grn") == 0){
        } else if(strcmp(value, "hzl") == 0){
        } else if(strcmp(value, "oth") == 0){
        } else {
          // invalid
          return 0;
        }
      } else if (strcmp(field, "pid") == 0){
        int j;
        for(j=0; value[j] != '\0'; j++) {
          if(!isdigit(value[j])) {
            return 0;
          }
        }
        if(strlen(value) != 9){
          return 0;
        }
      } 
    }
  }
  if(fields == 8){
    return 1;
  } else if(fields == 7 && strstr(passport, "cid:") == NULL) {
    return 1;
  }
  return 0;
}

int main() {
  int valid_passports_one = 0;
  int valid_passports_two = 0;
  char last_char = ' ';
  int i = 0;
  char c;
  char passport[PASSPORT_LENGTH];
  while ((c = getc(stdin))){
      if((last_char == '\n' && c == '\n') || c == EOF) {
        passport[i] = '\0';
        if(valid_passport(passport, 2)){
          valid_passports_one++;
          valid_passports_two++;
        } else if(valid_passport(passport, 1)){
          valid_passports_one++;
        }
        if(c == EOF){
          break;
        }
        i = 0;
      }
      passport[i] = c;
      i++;
      last_char = c;
  }
  // Part 1
  printf("%d\n", valid_passports_one);
  // Part 2
  printf("%d", valid_passports_two);
}
