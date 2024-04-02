#include<stdio.h>
#include<stdlib.h>

int suma (int *p, int len) { 
  int sum = 0;
  
  for (int i = 0; i < len; i++)
      sum += p[i];
  
  return sum;}

void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}

int cmp(const void *a,const void *b){
    int a1= *(int *)a;
    int b1=*(int *)b;
    if(a1<b1){
        return -1;
    }
    if(b1<a1){
        return 1;
    }
    else{
        return 0;
    }
    
}

void proc1(int rows,int columns,int tab[][columns]){
    for(int i=0;i<rows;i++){
        qsort(*(tab+i),columns,sizeof(int),cmp);
    }
}

void proc2(int rows,int columns,int tab[][columns]){////    ZROBIĆ!!!!!!!!!!!!!!!!!!
        int *T=malloc(rows*sizeof(int));
        for(int i=0;i<rows;i++){
            T[i]=suma(*(tab+i),columns);
            printf("%d ",T[i]);
        }
        for(int i=1;i<rows;i++){
            if(tab[i-1]<tab[i]){

            }
        }
}

int main(void){
    int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
    int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};

    int rows = sizeof(tab_A) / sizeof(tab_A[0]);
    int columns = sizeof(tab_A[0])/sizeof(tab_A[0][0]);
    proc1(rows,columns,tab_A);
    
    for(int i=0;i<3;i++){
        wypisz_i(*(tab_A+i),*(tab_A+i)+6);
    }
     proc2(rows,columns,tab_A);
}
