#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

    //generowanie liczb losowych calkowitych z przedziału (min, max)
    int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }

int main(void){
    srand(time(NULL));
    int size=i_rand(2,20);
    size++;
    char *str=malloc(size*sizeof(char));
    for(int i=0;i<size;i++){
        str[i]=i_rand('a','z');
    }
    str[size-1]='\0';
    for(int i=0;i<size;i++){
        printf("%c",str[i]);
    }
    char *sm="aeiouy";
    int count=size-1;
    int i=0;
    int a=0;
    while(i<size){
        if(strchr(sm,str[i])!=NULL){
            char temp=str[count];
            str[count]=str[i];
            str[i]=temp;
            count--;
           
        }
        else{
            i++;
            
        }
        if(i==count){
            break;
        }
    }
    printf("\n");
     for(int i=0;i<size;i++){
        printf("%c",str[i]);
    }
    printf("\n");
    str[i+1]='\0';
    str = realloc(str, (i + 1) * sizeof(char));
    
    int j=0;
    while (str[j]!='\0'){
        printf("%c",str[j]);
        j++;
    }
   free(str);

}