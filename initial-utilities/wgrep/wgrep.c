#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main(int argc, char *argv[]) {
  FILE* file;
  char line[1200];
  char word[255];
  
  if (argc >= 3){
    int files;
    strcpy(word, argv[1]);

    for (files = 2; files < argc; files++) {
      file = fopen(argv[files], "r");
      if (file != NULL){
        while (fgets(line, 1200, file)) {
          if (strstr(line , word )!= NULL){
            printf("%s",line);
          }
        }
      }
      else {
        printf("wgrep: cannot open file\n");
        return 1;
      } 
    }
  }
  else if (argc == 2){
    //char str[1200];
    //scanf("%[^\n]s", str);
    strcpy(word, argv[1]);
    
    while (fgets(line, 1200, stdin)) {
      if (strstr(line , word )!= NULL){
        printf("%s",line);
      }
    }
    
    return 0;
  }
  else {
    printf("wgrep: searchterm [file ...]\n");
    return 1;
  }
  return 0;
}
