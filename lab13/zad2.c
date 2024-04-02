#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char f_name[50];
    char l_name[50];
    char code[6];
    int age;
}person;

person *create_tab ( char * nazwa_pliku, int size){
    person *ptr=malloc(size*sizeof(person));
    FILE *file;
    file=fopen(nazwa_pliku,"r");
    for(int i=0;i<size;i++){
        fscanf(file,"%s %s %s %d",ptr[i].f_name,ptr[i].l_name,ptr[i].code,&ptr[i].age);
    }

    fclose(file);
    return ptr;
    
}
int main(void){
    char *name="ZAD2.txt";
    FILE *file;
    file=fopen(name,"r");
    char z;
    int size=1;
    while ((z=fgetc(file))!=EOF)
    {
        if(z=='\n')
            size++;
    }
    //fseek(file,0,SEEK_SET);
    fclose(file);
    person *ptr;
    ptr=create_tab(name,size);
    for(int i=0;i<size/4;i++){
        printf("%s %s %s %d\n",ptr[i].f_name,ptr[i].l_name,ptr[i].code,ptr[i].age);
    }
    file=fopen("ZAD2.dat","wb");
    fwrite(ptr,sizeof(person),size,file);
    fclose(file);
    
}