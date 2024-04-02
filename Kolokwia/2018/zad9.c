#include <stdio.h>

int main(void){
    int TAB[7][6];
    int (*FF(int k))[2];
    char * NAP[]={"nap1","nap2","nap3"};
    double T[][2]={{1.0,1.0},{0.},{2.0,3.0}};

    double (*a)[3][2];
     int *(*b(int k)[2]);
    char *(*c)[2];
    int (*d)[6];
    int *e;
    char f[4];
    char g;
    char h[2][2];
    char *((*k)[]);




    a=&T;
    b=FF+1;
    c=FF(9);
    d=TAB[2];
    e=FF(9)[1];
    f=*NAP+1;
    g=*NAP[1]++;
    h=(double[][2]){1.0,3.0,4.0};
    k=NAP;
}