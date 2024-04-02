#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rows=15;
int columns=10;

void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}

  int suma (int *p, int len) { 
  int sum = 0;
  
  for (int i = 0; i < len; i++)
      sum += p[i];
  
  return sum;}

int cmp(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}

int cmp2(const void *a ,const void *b){
  const int **aa = a;
    const int **bb = b;
    return suma(*aa, columns) - suma(*bb, columns);
}

int main(void){
    srand(time(NULL));
   // tab_3
 
int **tab_3 = malloc( 15*sizeof(int*));

for(int i = 0; i < 15; i++)  
tab_3[i] = malloc(10 * sizeof(int));

for(int i = 0; i < 15; i++)
  for(int j = 0; j < 10; j++)
   tab_3[i][j]  =  rand() % 21;
 
//tab_33
 
int **tab_33 = malloc( 15 * sizeof(int*));

tab_33[0] = malloc(10 * 15 * sizeof(int));
for(int i = 1; i < 15; i++)  
  tab_33[i] = tab_33[i-1] + 10 ;

for(int i = 0; i < 15; i++)
  for(int j = 0; j < 10; j++)
   tab_33[i][j]  =  rand() % 21;
 
//tab_333
 

int (*tab_333)[10] = malloc(10 * 15 * sizeof(int));

for(int i = 0; i < 15  ; i++)
  for(int j = 0; j < 10; j++)
   tab_333[i][j]  =  rand() % 21;

/////////////////////////////////////////////////////////////////////

// każdy wiersz rosnąco
for(int i=0;i<rows;i++){
    qsort(*(tab_3+i),columns,sizeof(tab_33[0][0]),cmp);
    qsort(*(tab_33+i),columns,sizeof(int),cmp);
    qsort(&tab_333[i],columns,sizeof(int),cmp);
    

}

// ze względu na sume elemntów w wierszu

    qsort(tab_3,columns,sizeof(int *),cmp2);


// wypisywanie
for(int i=0;i<rows;i++){
    wypisz_i(tab_3[i], tab_3[i]+columns);
}
printf("\n\n");
for(int i=0;i<rows;i++){
    wypisz_i(tab_33[i],tab_33[i]+columns);
}
printf("\n\n");
for(int i=0;i<rows;i++){
    wypisz_i(tab_333[i],tab_333[i]+columns);
}


/*int var=50;

for(int i=0;i<rows;i++){
    bsearch(&var,*(tab_3+i),columns,sizeof(int),cmp2);
}*/
}