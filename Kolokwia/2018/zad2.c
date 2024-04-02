#include <stdio.h>

void suma(int *TAB1,int *TAB2,int size,int *sum){
    *sum=0;
    for(int i=0;i<size;i++){
        *sum+=*(TAB1+i)+ *(TAB2+i);
    }
     
}

int main(void){
    int A[4]={1,2,3,4};
    int B[4]={1,2,3,4};

    int T1[2][3]={{1,1,1},{2,2,2}};
    int T2[2][3]={{1,1,1},{2,2,2}};
    int sum;
    suma(A,B,4,&sum);
    printf("%d\n",sum);
    suma(*T1,*T2,6,&sum);
    printf("%d",sum);
}