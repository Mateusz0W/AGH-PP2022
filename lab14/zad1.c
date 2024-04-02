#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define MIN 100
#define MAX 150

  //generowanie liczb losowych calkowitych z przedziału (min, max)
    int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }

struct elastyna{
    int len;
    int data[];
};
void write(struct elastyna *ptr,int index){
    
    printf("tab[%d] = ",index);
    for(int i=0;i<ptr->len;i++){
        printf("%d",ptr->data[i]);
    }
    printf("\n\n");
   
}
int cmp(const void *a,const void *b){
    struct elastyna *a1=*(struct elastyna**)a;
    struct elastyna *b1=*(struct elastyna**)b;
    
    if(a1->len<b1->len){
        return -1;
    }
    else if(a1->len>b1->len){
        return 1;
    }
    
        for(int i=0; i< a1->len;++i){
        if(a1->data[i]<b1->data[i]) return -1;
        if(a1->data[i]>b1->data[i]) return 1;
        }
    
}

int main(void){
    srand(time(NULL));

    int len;
    struct elastyna *tab[5];
    for(int i=0; i<5;i++){
        len=i_rand(MIN,MAX);
        tab[i]=malloc(sizeof(struct elastyna)+sizeof(int)*len);
        tab[i]->len=len;
        tab[i]->data[0]=i_rand(1,9);
        for(int j=1;j<len;j++){
            tab[i]->data[j]=i_rand(0,9);
        }
        write(tab[i],i);
    }
    qsort(tab,5,sizeof(struct elastyna *),cmp);
    printf("po sortowaniu\n\n");
    for(int i=0;i<5;i++){
        write(tab[i],i);
    }

}