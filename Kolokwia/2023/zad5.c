#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *f_napis(char *napis,int n){
    char *b=";";
    int size=strlen(napis);
    size=size*n+(n-1)+1;
    char *a=malloc(size);
    strcpy(a,napis);
    for(int i=0;i<n-1;i++){
        strcat(a,b);
        strcat(a,napis);
    }
    return a;
}

int main(void){
    char *result=f_napis("kot",5);
    printf("%s",result);

}