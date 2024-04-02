#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double fun0(double x) { return log(x); }
double fun1(double x) { return x*x;    }
double fun2(double x) { return sin(x); }
double fun3(double x) { return cos(x); }

void cmp(const void *a,const void *b){

}

void print_fun(double (*F)(double),char *name,double *data,int size){
   
    for(int i=0;i<size;i++){
        
        printf("%s(%f)= %f ",name,*(data+i),F(*(data+i)));
    }
}

 double *find_max(double (**F)(double),double value){ /////////////          ZROBIĆ!!!!!!!!!!!!!!!!!!!!!!!
   double max= (*(F+3))(value); 
  
 }
 void sort_arg(double (*F)(double),double *data,int size){//  ZROBIĆ !!!!!!!!!!!!!!!!!!!!!!!!!!!

    qsort(,size,sizeof(double),cmp);
 }
int main(void){
  

    char* nazwy[]={"log", "pow","sin","cos"};

    double data[8] = { 3.5, 1.0, 2.5, 2.0, 1.5, 3.0, 0.5, 4.0 }; 

    double (*TAB_FUN[5])(double );

    TAB_FUN[0] = fun0; 
    TAB_FUN[1] = fun1; 
    TAB_FUN[2] = fun2; 
    TAB_FUN[3] = fun3;
    TAB_FUN[4] = NULL;

    print_fun (fun0,"log",data,8);

    char **str;
    double (**wsk_fun)(double);
    wsk_fun = TAB_FUN;    
    str = nazwy;
    printf("\n\n------------------------------");
    printf("\n\n");
    int i=0;

    while (*wsk_fun!=NULL)
    {
        print_fun(*wsk_fun,nazwy[i],data,8);
        wsk_fun++;
        i++;
        printf("\n\n");
    }
    double *wsk_max;
    wsk_max = find_max (TAB_FUN, 0.05);
    sort_arg (TAB_FUN[1], data, 8);
    
}