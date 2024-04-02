#include "stack.h"

void print_stack(struct tnode* head){
    struct tnode *tail=head;
    struct tnode *current=head;

    while (tail->next!=NULL)
    {
        tail=tail->next;
    }
    while (head!=tail)
    {
        while (current->next!=tail)
        {
            current=current->next;
        }   
        printf("[ %d ]\n",tail->value);   
        printf("  ^\n");
        printf("  |\n");
        tail=current;
        current=head;     
    }
    printf("[ %d ]\n\n",tail->value);   
     
}
void push_one(struct tnode** head, struct tnode* el){
    el->next=*head;
    *head=el;
}
struct tnode* push_many(struct tnode* head, struct tnode** list_elements_to_add){
    struct tnode *temp=head;
    head=*list_elements_to_add;
    while ((*list_elements_to_add)->next!=NULL)
    {
        (*list_elements_to_add)=(*list_elements_to_add)->next;
    }
    (*list_elements_to_add)->next=temp;
    *list_elements_to_add=NULL;
    return head;
    
}

struct tnode* pop_one(struct tnode** head){
    if(*head==NULL){
        return NULL;
    }
    struct tnode *pop_one=*head;
    *head=(*head)->next;
    pop_one->next=NULL;
    return pop_one;
}

struct tnode* pop_x(struct tnode** head, int x){
    struct tnode *head2=*head;
    struct tnode *prev=*head;
    if(x==0){
        return NULL;
    }
   for(int i=0;i<x;i++){
    if((*head)->next==NULL){
        *head=NULL;
        return head2;
    }
        prev=*head;
        *head=(*head)->next;
   }
    prev->next=NULL;
    return head2;
}

void clear_st(struct tnode** head){
    struct tnode *current=*head;

    while (current!=NULL)
    {
        *head=(*head)->next;
        free(current);
        current=*head;
    }
    *head=NULL;
}