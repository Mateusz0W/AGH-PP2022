#include<stdio.h>

void wypisz_d (double *poczatek, double *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;}

void wypelnij(double tab[][6],int rows){
    double a=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<6;j++){
            tab[i][j]=a;
            a+=0.4;
        }
    }
}

int main(void){
    double A_1[8][6];
    double A_2[10][6];

    wypelnij (A_1, 8);
    wypelnij (A_2, 10);

    printf("cala tablica:");
    printf("A1");
    wypisz_d(*A_1,*(A_1+7)+5);
    printf("\n\n");
    printf("A2");
     wypisz_d(*A_2,*(A_2+9)+5);

     printf("\n\n");
     //printf("%f",*(A_1+1));

    for(int i=0;i<8;i++){
        wypisz_d(*(*A_1)+i,*(*A_1+8)+i); //DOKOŃCZYĆ WYPISYWANIE WIERSZAMI
    }
    
}