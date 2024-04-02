#include<stdio.h>
#include<stdlib.h>
#include <time.h>

//generowanie liczb losowych calkowitych z przedziału (min, max)
    int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }

struct tnode {
       int value;
       struct tnode *next;
     };


struct tnode* create ( int value){
    struct tnode *current=malloc(sizeof (struct tnode));
    current->value=value;
    return current;
}

struct tnode *make_list(struct tnode *head,int value){
    struct tnode *current;
    current=create(value);
    current->next=head;
    head=current;
    return head;
}
void print_list(struct tnode *head){
    printf("    addres        value       next\n");
    while (head!=NULL)
    {
        printf("%p    %d    %p\n",head,head->value,head->next);
        head=head->next;
    }
    
   
}

void sort(struct tnode **head){
    struct tnode *current=*head;
    struct tnode *even;
    struct tnode *p_even;
    struct tnode *prev=current;
    struct tnode *temp;
    while (current!=NULL)
    {
        if(current->value%2==1){
            even=current;
            while (even->value%2!=0)
            {   
                p_even=even;
                even=even->next;
                if(even==NULL){
                    break;
                }
            }
            if(current==*head){
                temp=even->next;
                even->next=current;
                current->next=temp;
                *head=even;
            }
            else{
                temp=even->next;
                even->next=current->next;
                prev->next=even;
                p_even->next=current;
                current->next=temp;
                current=even;
            }


            
        }
        prev=current;
        current=current->next;
    }
    
    
}

int main(void){
    srand(time(NULL));
    struct tnode *head=NULL;
    for(int i=0;i<10;i++){
        head=make_list(head,i_rand(1,15));
    }
    print_list(head);
    sort(&head);
    printf("\n\n");
    print_list(head);

}