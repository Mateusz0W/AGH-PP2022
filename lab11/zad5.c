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
    printf("head -> ");
    while(head!=NULL){
        printf("['%c'] ",head->value);
        head=head->next;
    }
     printf("->NULL");
}
struct tnode *list(struct tnode **head,char val){
  struct tnode *head1=*head;
  struct tnode *prev=*head;
  struct tnode *new_head=NULL;
  struct tnode *head2=NULL;
  int i=0;
  while (head1!=NULL)
  {
    while (head1->value!=val)
    {
        prev=head1;
        head1=head1->next;
        i=1;
    }
    if(i==0){
        *head=(*head)->next;
    }
    if(new_head==NULL){
        new_head=head1;
        head2=new_head;
        head1=head1->next;
        new_head->next=NULL;
    }
    else{
        head2->next=head1;
        prev->next=head1->next;
        head2=head1;
        head1=head1->next;
        head2->next=NULL;
    }
    
  }
  return new_head;
    
}

int main(void){
    struct tnode *head=NULL;
    
    char word[] = "Ala ma kota";
   for (int i = 0; word[i] != '\0'; i++) 
        add_front(&head, word[i]);

    print_list(head);
    printf("\n\n");
    struct tnode *left=list(&head,'a');
    print_list(left);
}