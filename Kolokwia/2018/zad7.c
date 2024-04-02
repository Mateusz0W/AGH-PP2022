#include <stdio.h>

 int f1(int (*f)(int)){
        int n=6;
        while((*f)(--n))n;
        return n;
    }

    int f2(int n){
        
        return n*n-6*n+5; 
    }

int main(void){
   printf("f1(f2) = %d\n",f1(f2));
}