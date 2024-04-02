#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char** podziel(char *T, int *size){
    char *W=" .,:;";
    char *w;
    char **word=malloc(sizeof(char*));
    int i=0;
    int count=0;

    while(*T){
    int len=0;
     while ((w=strchr(W,*(T+i)))==NULL)
     {
        i++;
        len++;
     }
     count++;
    T[len]='\0';
    word=realloc(word,count*sizeof(char *));
     word[count-1]=malloc((len+1)*sizeof(char));
     strcmp(word[count-1],T);
    
    T+=len+1;
     
    printf("%s\n",T);
}
    
}

int main(int argc,char *argv[]){
    int size=1;
    //printf("%s",argv[1]);
    podziel(*(argv+1),&size);
}