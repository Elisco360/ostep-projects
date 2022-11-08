#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc, char* argv[]){

    char * sp = argv[1];
    int num = 1;
    int result = 0;
    char temp [1000];
    
    FILE*fp;
    for (int i = 1; i < argc; i++){
        fp = fopen(argv[2],"r");

            if(!fp || argc!=3)
            {
                printf("wgrep: searchterm[file ...]");
                
            }
            if(!fp)
            {
                printf("wgrep: cannot open file");
                
            }

            while(fgets(temp,1000, fp)!= NULL){
                if((strstr(temp,sp))!=NULL){
                    printf("\n%s\n",temp);
                    result++;
                }
                num++;
            }
            if(result == 0){
                printf("Match not found");

            }

            fclose(fp);

         }

    return 0;
    


    
}