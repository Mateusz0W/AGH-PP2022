#include<stdio.h>

int main(void){
    enum fruits {APLLE,MANGO,ORANGE=4,BANANA};

    char *fruit_names[]={
        [APLLE]="Apple",
        [MANGO]="Mango",
        [ORANGE]="Orange",
        [BANANA]="Banana",
    };
    size_t size=sizeof(fruit_names);
    printf("%zd\n",size/sizeof(*fruit_names));
    for(int i=0;i<size/sizeof(*fruit_names);i++){
        printf("%s",fruit_names[i]);
    }
    printf("%zd %zd",size,sizeof(*fruit_names));
}