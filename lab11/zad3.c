#include<stdio.h>
#include<stdlib.h>

struct tnode {
  char value;
  struct tnode * next;
}; 
void add_front (struct tnode **head,char val){
    struct tnode *current=malloc(sizeof(struct tnode));
    current->next=*head;
    current->value=val;
    *head=current;
}
void print_list(struct tnode *head){
    while(head!=NULL){
        printf("['%c'] ",head->value);
        head=head->next;
    }
}
void free_list(struct tnode *head){
    struct tnode *current=head;
    while(head!=NULL){
        current=head->next;
        free(head);
        head=current;
    }
}

int main(void){
    struct tnode *head=NULL;
    add_front(&head,'a');
    add_front(&head,'c');
    add_front(&head,'v');
    add_front(&head,'f');
    add_front(&head,'t');
    print_list(head);
    free_list(head);
}