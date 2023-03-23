#include<stdio.h>
#include<stdlib.h>
typedef struct List
{
    int data;
    struct List *next;
} node;

node* cInsert(node*);

node* display(node*);

int main(){

    int n=0, ch=0;
    int i=0;
    node *last = NULL;
    printf("\nEnter number of processes: ");scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        printf("\nBurst Time of P%d Process: ",i);
        last = cInsert(last);
    }

    for(i=0; i<n; i++)
     last = display(last);
    return 0;

}

node* cInsert(node* last){

    node *p = NULL;

    int val;

    p= (node*)malloc(sizeof(node));

    if(p != NULL){

        scanf("%d",&val);
        p->data = val;
        if(last == NULL){
            p->next = p;
        } 
        else{
            p->next = last->next;
            last->next = p;
        }
        last = p;
    }
    return last;
}

node* display(node *last){
    
    node* dummy = (node*)malloc(sizeof(node));

    dummy->next = last;

    node* temp = dummy;
    node* f = NULL;
    while(last->data > 5){

        last->data = last->data - 5;
        printf("%D ->",last->data);
        last = last->next;
        temp = temp->next;
    }
    printf("\n");
    f = last;
    temp -> next = last->next;
    last = last ->next;
    free(f);
    return last;
}