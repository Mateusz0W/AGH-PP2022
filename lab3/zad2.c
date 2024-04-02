#include <stdio.h>

#define rows 5
#define columns 5

void swap (int *p_1, int *p_2) { 
  int temp = *p_1;
    *p_1 = *p_2;
    *p_2 = temp;
 return ;}

int main(void){
    int abc[rows][columns];
    for(int i=0;i<rows;i++){
        int a=0;
        for(int j=0;j<columns;j++){
            
            abc[i][j]=a;
            a++;
            printf("tab[%d][%d]= %d ",i,j,abc[i][j]);
        }
        printf("\n");
    }
      printf("\n\n");
     
    //ZROBIĆ TRANSPONOWANIE
    
}

