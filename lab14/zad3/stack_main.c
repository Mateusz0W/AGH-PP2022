#include "stack.h"

int main(void){
    struct tnode *head=NULL;
    struct tnode *current=malloc(sizeof(struct tnode));
    struct tnode *pop=NULL;

    current->value=4;
    push_one(&head,current);
    current=malloc(sizeof(struct tnode));
    current->value=6;
    push_one(&head,current);
    current=malloc(sizeof(struct tnode));
    current->value=2;
    push_one(&head,current);
    current=malloc(sizeof(struct tnode));
    current->value=8;
    push_one(&head,current);
    current=malloc(sizeof(struct tnode));
    current->value=1;
    push_one(&head,current);
    print_stack(head);
    printf("-------------\n");
    pop=pop_one(&head);  
    print_stack(head);
    printf("wysuniety element :%2d\n",pop->value);
    printf("-------------\n");
     
    struct tnode *head2=NULL;

    current=malloc(sizeof(struct tnode));
    current->value=22;
    push_one(&head2,current);
    current=malloc(sizeof(struct tnode));
    current->value=33;
    push_one(&head2,current);
    current=malloc(sizeof(struct tnode));
    current->value=44;
    push_one(&head2,current);
    head=push_many(head,&head2);
    print_stack(head);
    printf("-------------\n");

    head2=pop_x(&head,4);
    if(head!=NULL){
        print_stack(head);
        printf("  ^\n");
        printf("  |\n");
        printf(" head\n\n");
    }
    else{
        printf("head->NULL\n\n");
    }
    if(head2!=NULL){
        print_stack(head2);
        printf("  ^\n");
        printf("  |\n");
        printf(" head2\n");
    }
    else{
        printf("head2->NULL\n\n");
    }
    

    clear_st(&head);
    

}
