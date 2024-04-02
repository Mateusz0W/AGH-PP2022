#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person{
    char surname[50];
    char name[50];
    int age;
    struct person *next;
    struct person *next2;
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
        while ((strcmp(ptr->surname,current->surname))>0 &&current->next!=NULL)
        {
            prev=current;
            current=current->next;
        }
        if(current->next==NULL && strcmp(current->surname,ptr->surname)<0){
            current->next=ptr;
            ptr->next=NULL;
        }
        else  if(current==head && strcmp(current->surname,ptr->surname)>0){
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
person *age(person *head,person *ptr){
    person *current=head;
    person *prev=head;
    if(head==NULL){
        head=ptr;
        head->next2=NULL;
    }
    else{
        while (ptr->age>current->age &&current->next2!=NULL)
        {
            prev=current;
            current=current->next2;
        }
        if(current->next2==NULL && current->age<ptr->age){
            current->next2=ptr;
            ptr->next2=NULL;
        }
        else  if(current==head && current->age>ptr->age){
            ptr->next2=head;
            head=ptr;
        }
        else{
            ptr->next2=current;
            prev->next2=ptr;
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
void print_age(person *head,int size){
    for(int i=0;i<size;i++){
        printf("[ %d ] ->",head->age);
        head=head->next2;
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
        head2=age(head2,tab+i);
    }
    print_surname(head1,4);
    printf("\n");
    print_age(head2,4);

}