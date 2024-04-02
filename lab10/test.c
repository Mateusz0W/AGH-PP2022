#include<stdio.h>
#include<stdlib.h>

// testowałem funkcje qsor bsearch MOŻNA USUNĄĆ PROGRAM

  int suma (int *p, int len) { 
  int sum = 0;
  
  for (int i = 0; i < len; i++)
      sum += p[i];
  
  return sum;}

int cmp(const void *a,const void *b){
    int *a1=(int *)a;
    int *b1=(int *)b;

    printf("%d---%d\n",*a1,suma(a1,4));
}

int main(void){
     int tab[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int a=1;
    qsort(*tab,9,sizeof(int),cmp);
}