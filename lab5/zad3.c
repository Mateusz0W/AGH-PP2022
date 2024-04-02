#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *text(char *T1,char *T2,int s){
    char *F;
    char *T3=malloc(sizeof(char));
    int size=0;
    int c=0;
    int i=0;
    while( (F=strstr(T1,T2))!=NULL){
        size=F-T1;
        c+=size;
        T3=realloc(T3,(c+1)*sizeof(char));
        T1[size]='\0';
        if(i==0)
            strcpy(T3,T1);
        else
            strcat(T3,T1);
        T1+=size+s;
        i++;
       
    }
    strcat(T3,T1);
    return T3;
    

}

int main(void){
    char TEXT1[]="Jak sie nie ma, co sie lubi, to sie lubi, co sie ma.";
    char TEXT2[]="sie";
    char *TEXT3;
    int s=sizeof(TEXT2)-1;
    TEXT3=text(TEXT1,TEXT2,s);
    printf("%s",TEXT3);
}