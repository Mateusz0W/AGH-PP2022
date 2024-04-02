#include <stdio.h>

char* fun_1(char s[],char c){
    int i;
    for(i=0; s[i]!='\0';i++)
        if(s[i]==c)
            return s[i];

    return NULL;
}
char *fun_2(char *s,char c){
    while (*(s++)!='\0')
        if(*(--s)==c)
            return s;
    return NULL;
    
}

int main (void){

}