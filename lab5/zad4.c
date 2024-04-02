#include<stdio.h>
#include<stdlib.h>

double *my_alloc(int i_min, int i_max){
    int size=0;
    int count=0;
    for(int i=i_min;i<=i_max;i++){
        size++;
    }
    double *tab=malloc(size*sizeof(double));
    for(int i=0;i<size;i++){
        tab[i]=i;
    }
    double *head=tab;
    for(int i=i_min;i<=0;i++){
        head=tab+count;
        count++;
    }
    return head;
}
void my_free(double **my_tab, int i_min){
    
     if(*my_tab!=NULL)
     {
        *my_tab=*my_tab+i_min;
        free(*my_tab);
        *my_tab=NULL;
     }
     
    
}

int main(void){
    double *tab;
     tab=my_alloc(-2,3);
   // printf("%p\n",tab-2);
    my_free(&tab,-2);
    
    
}