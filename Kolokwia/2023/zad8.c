/* Mamy strukture
struct  node
{
    int val;
    struct node *next;
}*head;

zdefiniowna jest lista trzymana pzrez wskaźnik head proszę napisać funkcję która zwraca usunięty z listy
element o największje wartości pola va;.

proszę napisać wywołanie tej funkcji dla listy trzymanej przez wskaźnik head

*/



#include<stdio.h>

struct  node
{
    int val;
    struct node *next;
}*head;

struct node *fun(struct node **head){
    struct node *current=*head;
    int max=(*head)->val;
    while ((current!=NULL))
    {
        if(max<current->val)
            max=current->val;
        current=current->next;
    }
    current=*head;
    struct node *prev=*head;
    while (current->val!=max)
    {
        prev = current;
        current=current->next;
    }
    if(current==*head){
        *head=(*head)->next;
        current->next=NULL;
        return current;
    }
    else{
        prev->next=current->next;
        current->next=NULL;
        return current;
    }
    

}


int main(void){

struct node *max =fun(&head);


}