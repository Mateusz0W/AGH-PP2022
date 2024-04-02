#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct elem{
    char letter;
    int count;
    struct elem *next;
};
void print_list(struct elem *head){
    printf("head->");
    while(head!=NULL){
        printf("['%c : %d']-> ",head->letter,head->count);
        head=head->next;
    }
    printf("NULL");
}

struct elem *create ( char var ){
    struct elem *current=malloc(sizeof(struct elem));
    current->letter=var;
    current->count=1;
    current->next=NULL;
    
    return current;
}
struct elem *add_lis ( struct elem *head, char var){
    struct elem *new_node=create(var);
    struct elem *head1;
    struct elem *prev;
    int i=0;
     if(new_node->letter==32){
        return head;
    }
    if(head==NULL){
        head=new_node;
    }
   
    else{
        head1=head;
    
        while (new_node->letter>head1->letter && head1->next!=NULL)
        {
            prev=head1;
            head1=head1->next;
            i=1;
        }
        if(new_node->letter==head1->letter){
            head1->count++;
        }
        else{
             if(i==0){
                new_node->next=head;
                head=new_node;
            }
            else{
                prev->next=new_node;
                new_node->next=head1;
                }
        }
       
        
    }
    return head;

    
    
}
int main(int argc,char *argv[]){
    struct elem *head=NULL;
    struct elem *head1=NULL;
    char *str=argv[1];
    for(int i=0;i<strlen(str);i++){
        head=add_lis(head,*(str+i));
    }
    head1=head;
    print_list(head);
    
    FILE *file_txt,*file_bin;
    file_txt=fopen("ZAD1.txt","w");
    file_bin=fopen(argv[2],"wb");
    int count=0;
    size_t result;
    while (head1!=NULL)
    {
        fprintf(file_txt,"%c : %d\n",head1->letter,head1->count);
        head1=head1->next;
        count++;
    }
    head1=head;
    result=fwrite(head,sizeof(struct elem),count,file_bin);
    if(result!=count){
        printf("błąd");
    }
    fclose(file_txt);
    fclose(file_bin);
}