#include<stdio.h>

   void swap(int*a, int*b){
         int temp = *a;
         *a = *b;
         *b = temp;
         return;}

    int *find_min_wsk (int * wsk, int size ){
        int *min;
        min = wsk;
        for(int i=0;i<size;i++){
            if(*min>*(wsk+i)){
                min=wsk+i;
            }
        }
        return min;

    } 

    void sort (int *a, int *b){
        int size=b-a+1;
      
        for(int i=0;i<=b-a;i++){
            int *d=find_min_wsk(a+i,size);
            swap(a+i,d);
            size--;
        }
       
        
    }
    void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}

int main (void){
    int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,22,12,6,8,4,44,6,42,2,16,5,33,1,7,9,55,1,11,22,34,78,11,21,9,12,5,3,9};
     int size= sizeof(tab_A)/sizeof(tab_A[0]);
     
     int *min=find_min_wsk(tab_A,size);
     printf("%d\n",*min);

    int a=10;
    int i=0;
    while(a<=60){
        int *w=find_min_wsk(tab_A+i,a);
        printf("zakres: %d  ",a-1);
     for(int j=i;j<a;j++){
        
        printf("tab[%d]=%d ",j,tab_A[j]);
     }
     printf(" %d %p %d ",*w,w,w-tab_A);
     printf("\n");

     sort(tab_A+i,tab_A+a);
     i+=10;
     a+=10;
     }
     i=0;
     a=10;
     
    for(int j=0;j<5;j++){
        wypisz_i(tab_A+i,tab_A+a);
         i+=10;
         a+=10;
         printf("\n");
    }


}