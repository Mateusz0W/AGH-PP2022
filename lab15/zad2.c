#include<stdio.h>
#include<stdlib.h>

 struct tnode {
       int value;
       struct tnode *next;
       struct tnode *prev;
     };
 void print_list_next(struct tnode* head){
    
    
    while(head != NULL){
        printf("[ %d ] -> ",head->value);
        head=head->next;
    }
    printf("NULL");
    printf("\n\n");
 }
void print_list_prev(struct tnode* head){
    while (head->next!=NULL)
    {
        head=head->next;
    }
    while (head!=NULL)
    {
        printf("[ %d ] <- ",head->value);
        head=head->prev;
    }
    printf("NULL");
    printf("\n\n");
    
    
}
struct tnode* add_first(struct tnode* head, struct tnode* el){
    struct tnode *new_node=el;

    if(head==NULL){
        head=new_node;
        head->next=NULL;
        head->prev=NULL;
    }
    else{
        head->prev=new_node;
        new_node->next=head;
        head =new_node;
        new_node->prev=NULL;
    }

    return head;
}
 struct tnode* add_last(struct tnode* head, struct tnode* el){
     struct tnode *new_node=el;
     struct tnode *current=head;

     
     if(head==NULL){
        head=new_node;
        head->next=NULL;
        head->prev=NULL;
    }
    else{
        while (current->next!=NULL)
        {
            current=current->next;
        }
        current->next=new_node;
        new_node->prev=current;
        new_node->next=NULL;
        
    }
    return head;
 }
    struct tnode* del_el_all(struct tnode** head, int var){
        struct tnode *current=*head;
        struct tnode *new_head=NULL;
        struct tnode *temp;
        struct tnode *prev;
       

        while (current !=NULL)
        {
            int i=0;
            if(current->value==var){
                if(current==*head){
                    new_head=*head;
                    *head=(*head)->next;
                    new_head->next=NULL;
                    (*head)->prev=NULL;
                    current=*head;
                    temp=new_head;
                    i=1;
                }
               else if(new_head==NULL){
                    new_head=current;
                    prev=new_head->prev;
                    prev->next=new_head->next;
                    new_head->next=NULL;
                    new_head->prev=NULL;
                    current=prev->next;
                    temp=new_head;
                    i=1;

               }
                else if(current->next==NULL){
                    while (temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=current;
                    prev=current->prev;
                    prev->next=NULL;
                    current->prev=NULL;
                    i=1;
                }
                else{
                    while (temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=current;
                    temp=current->next;
                    prev=current->prev;
                    prev->next=current->next;
                    temp->prev=prev;
                    current->next=NULL;
                    current=temp;
                    i=1;
                }
                if(i==0){
                    current=current->next;
                }
            }
        }
        return new_head;
    }
struct tnode* del_el_one(struct tnode** head, int var){
    struct tnode *current=*head;
    struct tnode *find_me;

    while (current!=NULL)
    {
        if(current->value==var){
            if(current==*head){
                *head=current->next;
                (*head)->prev=NULL;
                find_me=current;
                find_me->next=NULL;
                return find_me;
            }
            else if(current->next==NULL){
                find_me=current;
                current=find_me->prev;
                current->next=NULL;
                find_me->prev=NULL;
                return find_me;
            }
            else{
                find_me=current;
                current=find_me->prev;
                current->next=find_me->next;
                current=find_me->next;
                current->prev=find_me->prev;
                find_me->next=NULL;
                find_me->prev=NULL;
                return find_me;
            }

        }
        current=current->next;
    }
    

}

void add_sort(struct tnode** head1, struct tnode* el){
    struct tnode *current =*head1;
    struct tnode *prev;

    while (current!=NULL && current->value>el->value )
    {
       current=current->next;
    }
    if(current==*head1){
        el->next=*head1;
        (*head1)->prev=el;
        *head1=el;
    }
    else if(current->next==NULL){
        current->next=el;
        el->prev=current;
    }
    else{
        struct tnode *prev=current->prev;
        prev->next=el;
        el->prev=prev;
        el->next=current;
        current->prev=el;
    }
    
}

struct tnode* div_list(struct tnode** head);

void free_list(struct tnode **head){
    struct tnode *current=*head;
    while (*head!=NULL)
    {
       *head=(*head)->next;
       free(current);
       current=*head; 
    }
    
}
int main(void){
    struct tnode *head=NULL;
    struct tnode *head2=NULL;
    struct tnode *one_el=NULL;

    struct tnode tab[7];
    tab[0].value=2;
    tab[1].value=6;
    tab[2].value=0;
    tab[3].value=2;
    tab[4].value=5;
    tab[5].value=2;
    tab[6].value=4;
    
    for(int i=0;i<6;i++){
        //head=add_first(head,&tab[i]);
        head=add_last(head,&tab[i]);  // jedno z tych dwóch musi być zakomentowane
        }

    print_list_prev(head);
    print_list_next(head);  
    one_el=del_el_one(&head,5);
    add_sort(&head,&tab[6]);
    print_list_next(head);
    print_list_next(one_el);
    head2=del_el_all(&head,2);
    print_list_next(head2);
  

    
     
}