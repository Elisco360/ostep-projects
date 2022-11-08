#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[]){
   //assigning the file pointer address to variable fp
    FILE*fp;
      for (int i =1; i < argc; i++)
      {

         fp = fopen(argv[i], "r");
               if(!fp)
               {
                  printf("wcat: cannot open file\n");
                  return 1;
               }
               char ch;
               while((ch=fgetc(fp))!=EOF){
                  printf("%c",ch);

               }
               fclose(fp);

         }
    

   
   
}