#include<stdio.h>
#include<stdlib.h>

struct tnode {
       int value;
       struct tnode *next;
     };

void print_list(struct tnode *head){
    struct tnode *current=head;
    while(current->next!=head)
    {
        printf("[ %d ] -> ",current->value);
        current=current->next;
    }
    printf("[ %d ] ->head ",current->value);
    
    
}
struct tnode* add_el(struct tnode* head, struct tnode* el){
    struct tnode *new_node=el;
    struct tnode *current=head;
    new_node->value=el->value;
    if(head==NULL){
        head=new_node;
        new_node->next=new_node;
    }
    else{
        while (current->next!=head)
        {
            current=current->next;
        }
        current->next=new_node;
        new_node->next=head;
        
    }
    return head;
}
void del_el(struct tnode** head, int var){
    struct tnode *current =*head;
    struct tnode *prev=*head;
   

    while (current->next!=*head)
    {
         
        if(current->value==var){
           if(current==*head){
            *head=current->next;
            while (prev->next!=current)
            {
                prev=prev->next;
            }
            prev->next=*head;
            prev=*head;
            current->next=NULL;
            current=*head;
        
           }
           else {
            prev->next=current->next;
            current->next=NULL;
            current=prev->next;
           }
        }
        else{
            prev=current;
            current=current->next;
        }
    }
    if(current->value==var){
        prev->next=current->next;
        current->next==NULL;
    }
    
}
struct tnode* add_list(struct tnode* head1, struct tnode* head2){
    struct tnode *current=head1;
    while (current->next!=head1)
    {
        current=current->next;
    }
    current->next=head2;
    current=head2;
    while (current->next!=head2)
    {
        current=current->next;
    }
    current->next=head1;
    return head1;
}
void free_list(struct tnode**head){
    struct tnode *current=*head;
    struct tnode *temp;
    current=current->next;
    temp=current;
    while(current!=*head){
          temp=temp->next;
          free(current);
          current=temp;
    }
    free(*head);
    *head=NULL;
    
}
int main(void){
    struct tnode *head=NULL;
    struct tnode *head2=NULL;
    struct tnode tab[4];
    struct tnode tab1[4];
    for(int i=0;i<4;i++){
        tab[i].value=i;
        tab1[i].value=i*10;
        head=add_el(head,&tab[i]);
        head2=add_el(head2,&tab1[i]);
    }
    print_list(head);
    printf("\n");
    head=add_list(head,head2);
    print_list(head);
    del_el(&head,0);
    printf("\n");
    print_list(head);
    free_list(&head);//sprawdzić czy działa
    printf("\nwszytko dziala!");
   
}