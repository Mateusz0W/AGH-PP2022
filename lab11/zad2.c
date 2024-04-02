#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>

char* va_cat(int n,...){
    va_list args;
    va_start(args,n);
    char *result=malloc(sizeof(char));
    int size=0;

    for(int i=0;i<n;i++){
        char *str=va_arg(args, char *);
        size+=strlen(str);
        result=realloc(result,size*sizeof(*str)+1);
        if(i<1){
            strcpy(result,str);
        }
        else{
            strcat(result,str);
        }
       
    }
    va_end(args);
     //printf("%s",result);
    return result;
        
}

int main(void){
    char a1[]="If you never did You should.";
    char a2[]=" These things are fun";
    char a3[]=" and Fun is good.";
    char *r1=va_cat(3,a1,a2,a3);

    FILE *file;
    file=fopen("ZAD2.txt","w");

    printf("%s\n",r1);
    char* cat2 = va_cat(4, "Sometimes ", "you will never know ", "the value of a moment ", "until it becomes a memory.");
    printf("%s\n", cat2);
    
    fprintf(file,"%s \n%s",r1,cat2);
    fclose(file);
    free(r1);
    free(cat2);
}