
////////////////////ZROBIONE

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

  //generowanie liczb losowych calkowitych z przedziału (min, max)
    int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }

int main(void){
    srand(time(NULL));
    int rows=i_rand(3,7);
    int columns=i_rand(3,7);

    int **array_3=malloc(rows*sizeof(int *));
    for(int i=0;i<rows;i++){
        array_3[i]=malloc(columns*sizeof(int));
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            array_3[i][j]=i_rand(1,15);
            printf("%d ",array_3[i][j]);
        }
        printf("\n");
    }
    
    int rows_new=i_rand(3,7);
    printf("\n");
   // printf("\n%d %d\n ",rows,rows_new);
   
    if(rows_new<rows){
        for(int i=rows_new;i<rows;i++){
            free(array_3[i]);
        }
       
    }
     array_3=realloc(array_3,rows_new*sizeof(int *));
    if(rows_new>rows){
        for(int i=rows;i<rows_new;i++)
            array_3[i]=malloc(columns*sizeof(int));
        for(int i=rows;i<rows_new;i++){
            for(int j=0;j<columns;j++){
                array_3[i][j]=i_rand(-15,-1);
            }
        
        } 
             
      
    }
      for(int i=0;i<rows_new;i++){
        for(int j=0;j<columns;j++){
           
            printf("%d ",array_3[i][j]);
        }
        printf("\n");}

     for(int i = 0;i<rows_new;i++){
            free(array_3[i]);
        }
     free(array_3) ;  

/////////////////////array_2    
printf("\n");
int **array_2=malloc(rows*sizeof(int *));
array_2[0]=malloc(rows*columns*sizeof(int));

for(int i=1;i<rows;i++){
    array_2[i]=array_2[i-1]+columns;
}
for(int i=0;i<rows;i++){
    for(int j=0;j<columns;j++){
        array_2[i][j]=i_rand(1,15);
        printf("%d ",array_2[i][j]);
    }
    printf("\n");
}
printf("\n\n");

if(rows_new<rows){
       array_2 = realloc(array_2,rows_new*sizeof(double*));
        array_2[0]=realloc(array_2[0],columns*rows_new*sizeof(double));
        for(int i =1;i <rows_new;i++){
        array_2[i]  =  array_2[i-1]+columns;
        } 
        }

if(rows_new>rows){
   array_2=realloc(array_2,rows_new*sizeof(int *));
   array_2[0]=realloc(array_2[0],rows_new*columns*sizeof(int));
   for(int i=1;i<rows_new;i++){
         array_2[i]=array_2[i-1]+columns;
   } 
   for(int i=rows;i<rows_new;i++){
    for(int j=0;j<columns;j++){
        array_2[i][j]=i_rand(-15,1);
        
    }
    
}

}
for(int i=0;i<rows_new;i++){
    for(int j=0;j<columns;j++){
      
        printf("%d ",array_2[i][j]);
    }
    printf("\n");
}
  free (array_2[0]) ;//zwonienie  pamieci tablicy "dwuwymiarowej" 
  free (array_2);

  /////////////////array 1
  printf("\n\narray_1\n");
    int (*array_1)[columns]=malloc(rows*columns*sizeof(int ));
     for(int i=0;i<rows;i++){
        for(int j = 0;j<columns;j++){
            array_1[i][j]=i_rand(1,15);
            printf("%d ",array_1[i][j]);
        }
        printf("\n");
    }

    array_1=realloc(array_1,rows_new*columns*sizeof(int));
    if(rows_new>rows){
        for(int i=rows*columns;i<rows_new*columns;i++){
            (*array_1)[i]=i_rand(-15,-1);
        }
    }
       printf("\n");
     for(int i=0;i<rows_new;i++){
        for(int j = 0;j<columns;j++){
           
            printf("%d ",array_1[i][j]);
        }
        printf("\n");
    }


free(array_1);
}




