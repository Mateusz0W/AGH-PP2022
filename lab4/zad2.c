#include <stdio.h>
#include<stdlib.h>
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

int main(void){
    srand(time(0));
    printf("podaj rozmiar");
    int size;
    scanf("%d",&size);
    int *table=malloc(size*sizeof(int));
    int *arg_p=malloc(sizeof(int));
    int *arg_n=malloc(sizeof(int));
    int p=0;
    int n=0;

    for(int i=0;i<size;i++)
        table[i]=i_rand(-5,5);   
    
    wypisz_i(table,table+size);
    for(int i=size-1;i>=0;i--){

        if(table[i]%2==0){
            p++;
           arg_p= realloc(arg_p,p*sizeof(int));
            arg_p[p-1]=table[i];
            table=realloc(table,i*sizeof(int));
            
        }
        else{
             n++;
            arg_n=realloc(arg_n,n*sizeof(int));
            arg_n[n-1]=table[i];
            table=realloc(table,i*sizeof(int));
           

        }
    }
    wypisz_i(arg_p,arg_p+p);
     wypisz_i(arg_n,arg_n+n);
    free(arg_n);
    free(arg_p);

}