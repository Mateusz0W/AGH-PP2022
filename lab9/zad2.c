#include<stdio.h>
#include<stdlib.h>

void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}

int cmp(const void *a,const void *b){
    int a1=*(int *)a;
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

int  proc(int rows,int columns,int tab[][columns],int find_me){
    qsort(tab,rows*columns,sizeof(int),cmp);
    int *w=bsearch(&find_me,tab,columns*rows,sizeof(int),cmp);

    if(w!=NULL){
        int index=(w-tab[0])/columns;
        return index;}
    else{
        printf("brak elementu");
    }
}

int main(void){
    int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
    int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};

    int rows = sizeof(tab_A) / sizeof(tab_A[0]);
    int columns = sizeof(tab_A[0])/sizeof(tab_A[0][0]);
    int index=proc(rows,columns,tab_A,2);
   for(int i=0;i<3;i++){
        wypisz_i(*(tab_A+i),*(tab_A+i)+6);
    }
    printf("index=%d",index);
}