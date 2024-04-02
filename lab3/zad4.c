
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    //generowanie liczb losowych calkowitych z przedziału (min, max)
    int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }

    void swap (int *p_1, int *p_2) { 
  int temp = *p_1;
    *p_1 = *p_2;
    *p_2 = temp;
 return ;}

int main(void){
    srand(time(NULL));
    int len=i_rand(2,10);
    printf("a%d\n",len);
    int *tab=malloc(len*sizeof(int));
    for(int i=0;i<len;i++){
        tab[i]=i_rand(0,10);
        printf("%d ",tab[i]);
    }
    printf("\n");
    
    for(int i=0;i<len;i++){
        
        if(tab[i]%2 !=0){
            for(int j=i;j<len;j++){
                if(tab[j]%2==0){
                    swap(tab+i,tab+j);
                }
            }
        }
    }
    for(int i=0;i<len;i++){
        //tab[i]=i_rand(0,10);
       printf("%d ",tab[i]);
    }

}