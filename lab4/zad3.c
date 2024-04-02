#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define M 3
#define N 4

void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}

int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }

 int find_min_ind (int *T_F, int *T_L){  //poczatek i koniec (T_F - wskaznik na pierwszy element, T_L wskaznik za ostatni element) obszaru tablicy gdzie szukamy minimum
   int min = 0;
   for (int i = 1; i < T_L - T_F; i++)
      if(T_F[min] > T_F[i]) min = i;
  
   return min;}

int *tab_min(int tab[][M],int rows){
   int *new_tab=malloc(N*sizeof(int));
   for(int i=0;i<N;i++){
        int min=find_min_ind(*(tab+i),*(tab+1+i));
        new_tab[i]=min;
   }
   return new_tab;
}

int row_number(int tab[][M],int rows){
    int *new_tab=tab_min(tab,rows);
    int min=*(*(tab)+new_tab[0]);
    int min_index=0;
for(int i=1;i<rows;i++){

    if(min>*(*(tab+i)+new_tab[i])){
        min=*(*(tab+i)+new_tab[i]);
        min_index=i;

    }
    
}
//printf("\n%d",min_index);
return min_index;
}

int main(void){
     srand(time(0));
int TAB[N][M];

for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
        TAB[i][j]=i_rand(-5,5);
        printf("%d ",TAB[i][j]);
    }
    printf("\n");
}
int *new_tab=tab_min(TAB,N);
printf("\nnew=");
for(int i=0;i<N;i++){
    printf("%d ",new_tab[i]);
}

//////
int min=*(*(TAB)+new_tab[0]);
for(int i=1;i<N;i++){

    if(min>*(*(TAB+i)+new_tab[i])){
        min=*(*(TAB+i)+new_tab[i]);

    }
    
}
printf("\n min=%d",min);
////
int min_index=row_number(TAB,N);
printf("\n%d\n",min_index);
wypisz_i(*(TAB+min_index),*(TAB+min_index)+M);
}