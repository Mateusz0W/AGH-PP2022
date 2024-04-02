#include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    //generowanie liczb losowych calkowitych z przedziału (min, max)
    int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }

#define M 4
#define N 3

int main(void){
    int TAB[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            TAB[i][j]=i_rand(2,9);
        }
    }
        int (*wsk)[M] = TAB+2;
}