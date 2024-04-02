#include<stdio.h>
#include<stdlib.h>

struct tnode {
  char value;
  struct tnode * next;
}; 


struct tnode **add_end (struct tnode **head, struct  tnode * elem){
    struct tnode *current=malloc(sizeof(struct tnode));
    struct tnode *new_head;
    current->value=elem->value;
    current->next=NULL;
    if(*head==NULL){
        *head=current;
        new_head=current;
    }
    else{
        while (new_head->next!=NULL)
        {
            new_head=new_head->next;
        }
        new_head->next=current;
        
    }
    return head;
}
void print_list(struct tnode *head){
    while(head!=NULL){
        printf("['%c'] ",head->value);
        head=head->next;
    }
}

int main(void){
    struct tnode *head_1=NULL;
    struct tnode tab[5];
    tab[0].value='a';
    tab[1].value='c';
    tab[2].value='v';
    tab[3].value='f';
    tab[4].value='t';
    
    for(int i=0;i<5;i++){
        add_end(&head_1,tab+i);
    }
    printf("head_1->");
    print_list(head_1);
    printf("->NULL");
}