// Co wypisz funkcja f5

#include <stdio.h>

void print_v1(float *tab_1D,size_t n){
    for(size_t i=0;i<n;i++)
        printf("%10g",tab_1D[i]);
    printf("\n");
}

int main(void){
    float tab2[][4]={{4.5,12.7},{1.0},{12.3,3.5}};
    for(size_t i=0 ; i<sizeof tab2/sizeof *tab2;++i)
        print_v1(tab2[i],4);
}