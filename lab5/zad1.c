#include<stdio.h>

void swap (int *p, int *q) { 
  int temp = *p;
  *p = *q;
  *q = temp;
  return;}

  void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}

void swap_tab(int *A, int *B, int n){
    for(int i=0;i<n;i++){
        swap(A+i,B+i);
    }
}
void swap_rows(int n, int (*TAB)[n], int x, int y){
     swap_tab(TAB[x],TAB[y],n);
}

int main(void){
    int tab_22 [5][2] = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    wypisz_i(*tab_22,*tab_22+10);
    swap_tab(*(tab_22),*(tab_22+1),2);
     wypisz_i(*tab_22,*tab_22+10);
     printf("\n\n");
     int tab_1[4][5] = {{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4}};
    wypisz_i(*tab_1,*tab_1+20);
    swap_rows(5,tab_1,0,2);
    wypisz_i(*tab_1,*tab_1+20);
}