#include "stdio.h"

int main(int argc, char *argv[]) {
  FILE *file;
  char buffer[1200];

  if (argc > 1) {
    int files;
    for (files = 1; files < argc; files++) {
      file = fopen(argv[files], "r");
      if (file != NULL){
        while (fgets(buffer, 1000, file)) {
          printf("%s", buffer);
        }
      }else {
        printf("wcat: cannot open file\n");
        return 1;
      }
    }

    fclose(file);
    return 0;
  } else {
    return 0;
  }
}
