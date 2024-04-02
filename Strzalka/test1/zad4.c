#include<stdio.h>
#include<string.h>

int main(void){
    const char *string1[]={"jeden","dwa","trzy","cztery","piec"};
    char string2[][18]={"Szesc",
                        "siedem",
                        "osiem",
                        "Dziewiec\0Dziesiec"};
    size_t n1=sizeof string1 / sizeof(*string2);
    size_t n2 = sizeof string2/ sizeof(*string2);
    printf("%zd %zd",n1,n2);
    const char *p=*(string2+2);
    printf("%c",*++p);
    char *w=*string2 +strlen(*string2)-1;
    printf("%c",--*w-1);
    w=*(string2+n2-1);
    printf("%s",w+strlen(w)+2);
}