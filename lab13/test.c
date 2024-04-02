#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person{
    char surname[50];
    char name[50];
    int age;
    struct person *next;
}person;
void add_person(person *ptr,char *name,char *surname,int age){
    strcpy(ptr->name,name);
    strcpy(ptr->surname,surname);
    ptr->age=age;
}
person *surname(person *head,person *ptr){
    person *current=head;
    person *prev=head;
    if(head==NULL){
        head=ptr;
        head->next=NULL;
    }
    else{
        while (ptr->surname>current->surname &&current->next!=NULL)
        {
            prev=current;
            current=current->next;
        }
        if(current->next==NULL && current->surname<ptr->surname){
            current->next=ptr;
            ptr->next=NULL;
        }
        else  if(current==head && current->surname>ptr->surname){
            ptr->next=head;
            head=ptr;
        }
        else{
            ptr->next=current;
            prev->next=ptr;
        }

        
    }

   return head;
}
void print_surname(person *head,int size){
    for(int i=0;i<size;i++){
        printf("[ %s ] ->",head->surname);
        head=head->next;
    }
    printf("NULL");
}



int main(void){
    person tab[4];
    person *head1=NULL;
    person *head2=NULL;
    add_person(&tab[0],"Mateusz","koks",21);
    add_person(&tab[1],"adam","kot",19);
    add_person(&tab[2],"michał","sen",33);
    add_person(&tab[3],"monika","boss",89);
    for(int i=0;i<4;i++){
        head1=surname(head1,tab+i);
    }
   // print_surname(head1,4);
    if(tab[0].name<tab[1].name){
        printf("dd");
    }
    else{
        printf("aa");
    }

}