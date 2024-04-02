#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

 //generowanie liczb losowych rzeczywistych z przedziału (min, max)
    double d_rand(double min, double max){
    double r = (double) rand()/RAND_MAX;
    return r*(max-min) + min;
    }


struct point
{
    double x;
    double y;
};
struct vect_point
{
    struct point start;
    struct point end;
};
struct vect
{
    double length;
    double angle;
    struct vect_point vector;
};


double vect_len( struct vect_point vector){
  double len_x=vector.end.x-vector.start.x;
  double len_y=vector.end.y-vector.start.y;
  double len;
  return len=sqrt(len_x*len_x-len+len_y*len_y);
}

double vect_slope( struct vect_point vector){
    double dx = vector.end.x - vector.start.x;
    double dy = vector.end.y - vector.start.y;
    double angle = sin(dy / sqrt(dx * dx + dy * dy));
    
    return angle;
}

void fill_tab ( struct vect *wsk, int size ){
    for(int i=0;i<size;i++){
        wsk->angle=vect_slope(wsk->vector);
        wsk->length=vect_len(wsk->vector);
        wsk++;
    }
}

void selection_sort(struct vect *wsk,int size){
    int index;
    struct vect temp;
    for(int i=0;i<size-1;i++){
        index=i;
        for(int j=i+1;j<size;j++){
            if(wsk[j].angle<wsk[index].angle){
                index=j;
            }
            else if(wsk[j].angle==wsk[index].angle){
                if(wsk[j].length<wsk[index].length){
                    index=j;
                }
                
            }
            
        }
        if(index!=i){
                    temp=wsk[index];
                    wsk[index]=wsk[i];
                    wsk[i]=temp;
                }
    }
    
}
int cmp(const void *a,const void *b){
    struct vect a1= *(struct vect *)a;
    struct vect b1 = *(struct vect *)b;

    if(a1.length<b1.length){
        return -1;
    }
    if(a1.length==b1.length){
        if(a1.angle<b1.angle){
            return -1;
        }
        else{
            return 1;
        }
    }
    else{
        return 1;
    }
}
int cmp2(const void *a,const void *b){
    struct vect a1=*(struct vect*)a;
    struct vect b1=*(struct vect *)b;

    if((a1.length==b1.length) &&(a1.angle==b1.angle) ){
        return 0;
    }
}

double search(struct vect *wsk,int size,struct vect *find_me){
    qsort(wsk,size,sizeof(*wsk),cmp);
    struct vect *ptr;
    ptr=bsearch(find_me,wsk,size,sizeof(*wsk),cmp2);
    if(ptr==NULL){
        printf("\n\nbrak");
    }
}

int main(int argc,char *argv[]){
     srand(time(0));
    int size =atoi(argv[1]);
    struct vect tab_vect[size];

    for(int i=0;i<size;i++){
        tab_vect[i].vector.start.x=d_rand(0.0,10.0);
        tab_vect[i].vector.start.y=d_rand(0.0,10.0);
        tab_vect[i].vector.end.x=d_rand(0.0,10.0);
        tab_vect[i].vector.end.y=d_rand(0.0,10.0);
        
    }
        fill_tab(&tab_vect[0],size);
    for(int i=0;i<size;i++){
        
        printf(" x.start=%f y.start=%f x.end=%f y.end=%f dlugosc=%f kat=%f\n", tab_vect[i].vector.start.x, tab_vect[i].vector.start.y,tab_vect[i].vector.end.x,tab_vect[i].vector.end.y,tab_vect[i].length,tab_vect[i].angle);
    }
   // selection_sort(tab_vect,size);
    search(tab_vect,size,&tab_vect[1]);
    printf("\nposortowne:\n");
    for(int i=0;i<size;i++){
        
        printf(" x.start=%f y.start=%f x.end=%f y.end=%f dlugosc=%f kat=%f\n", tab_vect[i].vector.start.x, tab_vect[i].vector.start.y,tab_vect[i].vector.end.x,tab_vect[i].vector.end.y,tab_vect[i].length,tab_vect[i].angle);
    }
}