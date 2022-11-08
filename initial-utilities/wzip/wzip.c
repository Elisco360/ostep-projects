#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main(int argc, char *argv[]){
  FILE* file;
  int character;
  int i, count;
  int l_indx;
  
    
  if (argc > 1) {
    character = 0;
    count = 0;
    l_indx = -1;
    
    for (i = 1; i < argc; i++) {
      file = fopen(argv[i], "r");
  
      while ((character = fgetc(file)) != EOF) {
        if (l_indx == -1) {
          l_indx = character;
          count++;
        } else if (character != l_indx) {
          fwrite(&count, 4, 1, stdout);
          fputc(l_indx, stdout);
          count = 1;
        } else {
          count++;
        }
        l_indx = character;
      }
      fclose(file);
    }
  } 
    
  else {
    printf("wzip: file1 [file2 ...]\n");
    return 1;
  }

  if (count > 0) {
    fwrite(&count, 4, 1, stdout);
    fputc(l_indx, stdout);
  }
  
  return 0;
    
}
  