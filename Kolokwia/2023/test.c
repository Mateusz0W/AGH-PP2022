struct lista_trig
{
    double (*fun)(double);
    char name[4];
    struct lista_trig *next;
};



void struct lista_trig dodaj(struct lisya_trig **head,char *name,double (*fun_wsk)(double)){
    struct lista_trig *current=*head;
    struct lista_trig *prev=*head;

    if(*head==NULL){
        *head=malloc(sizeof(struct lista_trig));
        *head->next=NULL;
        strcpy((*head)->name,name);
        (*head)->fun=fun_wsk
    }
    else{
        struct lista_trig *temp=malloc(sizeof(struct lista_trig));
        strcpy(temp->name,name);
        temp->fun=fun_wsk;
        while(strcmp(current->name,name)<1 && current!=NULL){
            prev=current;
            current=current->next;
        }
        if(*head==current){
            temp->next=*head;
            *head=temp;
        }
        else{
            prev->next=temp;
            temp->next=current;
        }   
    }
}