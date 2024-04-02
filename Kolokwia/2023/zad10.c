#include<stdio.h>
#define RAZ(a,b) (a)<(b)?(a):(b)

#define DWA(x) 2*x

#define TRZY(x) printf("%s=%d\n",#x,x)

int main(void){
int x=3,y=4,m=RAZ(x++,y++);
printf("x=%d,y=%d,m=%d\n",x,y,m);
double M=47/DWA(2);
printf("m=%f\n",M);
TRZY(2*2+6);

}