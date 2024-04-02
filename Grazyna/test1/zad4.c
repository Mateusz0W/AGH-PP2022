#include <stdio.h>
int main(){
    char *b[]={"ALA","OAL","TOLA"};
    for(int i=0;i<3;i++)
        printf("%s ",b[i]);
    b[2][0]='K';
    for(int i=0; i<3;i++)
        printf("%s ",b[i]);
return 0;
}