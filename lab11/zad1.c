#include<stdio.h>
#include<stdlib.h>
#include<time.h>

    //generowanie liczb losowych calkowitych z przedziału (min, max)
    int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }
        //generowanie liczb losowych rzeczywistych z przedziału (min, max)
    double d_rand(double min, double max){
    double r = (double) rand()/RAND_MAX;
    return r*(max-min) + min;
    }


struct liczba
{
    char sign;
    union value
    {
        int i;
        double d;
    }val;
    
};

void struct_prn(struct liczba *ptr,int len){
    for(int i=0;i<len;i++){
        if(ptr->sign=='i'){
            printf("%d ",ptr->val.i);
        }
        else{
            printf("%f ",ptr->val.d);
        }
        ptr++;
        
    }
}

int cmp(const void *a,const void *b){
    struct liczba a1=*(struct liczba *)a;
    struct liczba b1=*(struct liczba *)b;

    if(a1.sign=='i'){
        if(b1.sign=='d'){
            return 1;
        }
        else{
            return (a1.val.i-b1.val.i);
        }
    }
    else{
        if(b1.sign=='i'){
            return -1;
        }
        else{
            return(a1.val.d-b1.val.d);
        }
    }

}


void sort(struct liczba *ptr,int len){
    qsort(ptr,len,sizeof(struct liczba),cmp);
}



int main(int argc,char *argv[]){
    srand(time(NULL));
    int len=i_rand(10,20);
    struct liczba tab[len];

    for(int i=0;i<len;i++){
        int random =i_rand(0,1);
        if(random==0){
            tab[i].val.i=i_rand(-5,5);
            tab[i].sign='i';
        }
        else{
            tab[i].val.d=d_rand(-5.0,5.0);
            tab[i].sign='d';
        }
        
    }
    
    struct_prn(tab,len);
    FILE *file;
    file=fopen("ZAD3.dat","wb");
    fwrite(tab,sizeof(struct liczba),len,file);

    fclose(file);




    sort(tab,len);
    printf("\n\n");
    struct_prn(tab,len);

    int find_i;
    double find_d;
    int *w;

    if(*argv[1]=='i'){
       find_i =atoi(argv[2]);
       w=bsearch(&find_i,tab,len,sizeof(struct liczba),cmp); 
    }
    else{
        find_d=atof(argv[2]);
    }
     printf("\n\n%d",*w);

    
  
}