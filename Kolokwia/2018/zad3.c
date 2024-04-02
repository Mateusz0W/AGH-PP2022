#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[]){
    int n=atoi(argv[2]);
    int size=strlen(argv[1]);
    char *napis =malloc(size+1);
    strcpy(napis,argv[1]);
    for(int i=0;i<n;i++){
        printf("%s\n",napis);
    }
    free(napis);
}