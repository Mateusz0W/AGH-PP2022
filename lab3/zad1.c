#include<stdio.h>
#include <stdlib.h>
#include <time.h>

//generowanie liczb losowych calkowitych z przedziału (min, max)
int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}

void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}

#define rows 5
#define columns 4

int suma (int *tab, int len) { 
  int ss = 0.0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}


int main(void){
srand(time(NULL));
int abc[rows][columns];
for(int i=0;i<rows;i++){
    for(int j=0;j<columns;j++){
        abc[i][j]=i_rand(-10,10);
    }
}

wypisz_i(*abc,*(abc+4)+4);
int size=rows*columns;
int suma_all = suma ((int *)abc,size); 
printf("%d",suma_all);
}