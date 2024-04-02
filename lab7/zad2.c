#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char** podziel(char *T, int *size){
    char *W=" .,:;";
    
    int count=0;
    char* w;
    char **word=malloc(sizeof(char *));
    int i=0;
    int j=0;
    while(*T){
    i=0;
    while ((w=strchr(W,*(T+i)))==NULL)
    {
        i++;
    }
    i++;
    j=i;
    //printf("%d",i);
    count++;
    word=realloc(word,count*sizeof(char*));
    T[j-1]='\0';
    for(int i=count-1;i<count;i++){
        word[i]=malloc((i+1)*sizeof(char));
        strcpy(word[i],T);
    }
    
    T+=j;

    
   printf("%s\n",*word);
}
int a=0;
    
}

int main(int argc,char *argv[]){
    int size=1;
    //printf("%s",argv[1]);
    podziel(*(argv+1),&size);
}