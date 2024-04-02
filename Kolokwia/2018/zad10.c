#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *int_to_str(int value){
    int size=0;
    int val=value;
    while (value!=0)
    {
        value/=10;
        size++;
    }
    char *a=malloc(size+1);
    sprintf(a,"%d",val);
    return a;
    
}

int main(void){
    char *a=int_to_str(100123);
    printf("aaa %s",a);
}