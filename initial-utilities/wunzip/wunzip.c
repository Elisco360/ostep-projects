#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char *argv[]) {
  FILE *file;
  int character;
  int count;
  size_t read;

  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      file = fopen(argv[i], "r");
      if (!file) {
        perror("fopen");
        return 1;
      }

      while ((read = fread(&count, 4, 1, file)) == 1) {
        character = fgetc(file);
        for (int j = 0; j < count; j++) {
          printf("%c", character);
        }
      }


      fclose(file);
    }

  }

  else {
    printf("wunzip: file1 [file2 ...]\n");
    return 1;
  } 

  return 0;
}
