#include <stdio.h>
#include <string.h>
#include <windows.h>

int main(int argc,char* argv[]){

    if(argc != 3){
        printf("search.exe <text to serach> <filename>.");
        return 0;
    }

    char * pword = argv[1];
    char * pfile = argv[2];

    int len = strlen(pword);

    FILE * fp = fopen(pfile,"r");
    if(fp == NULL){
        printf("failed to open file\n");
        return 0;
    }

    while(!feof(fp)){
        int c = fgetc(fp);
        if(EOF == c)
            break;

        if(c == pword[0]){

            char word[1000];
            int index = 0;

            do{
                word[index++] = c;
                c = fgetc(fp);
            }

            while(!feof(fp) && index < len && index < 1000);

            word[index] = '\0';
            if(0 == strcmp(word,pword)){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),206);
                printf("%s",word);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }
            else{
                printf("%s",word);
            }
        }

        printf("%c",c);

    }

    fclose(fp);
    fp = NULL;

}
