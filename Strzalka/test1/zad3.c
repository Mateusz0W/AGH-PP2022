//co się wypisze

#include<stdio.h>

int main(void){
    float tab1[][4]={4.5,12.7,1.0,12.3,3.5};
    float tab2[][4]={{4.5,12.7},{1.0},{12.3,3.5}};
    size_t n1=sizeof tab1/ sizeof(*tab1);
    size_t n2=sizeof tab2/ sizeof(*tab2);

    printf("%zd %zd",n1 ,n2);
    n1=sizeof *tab1/sizeof(**tab1);
    n2=sizeof *tab2/sizeof(**tab2);
    printf("%zd %zd",n1 ,n2);
    }



