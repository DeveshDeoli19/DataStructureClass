
#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    struct Node *prev;
    int info;
    struct Node *next;
}node;


void insert(node **head,node **tail)
{

    node *p = (node*)malloc(sizeof(node));
    int val=0;
    printf("Enter value: ");scanf("%d",&val);
    p->info = val;
    p->next = NULL;

    //if it is first node
    if ((*head) == NULL)
    {
        (*head) = p;
        (*tail) = p;
        (*head)->prev = NULL;
        return;
    }

    //if it is smaller than current head
    if ((p->info) < ((*head)->info))
    {
        p->prev = NULL;
        (*head)->prev = p;
        p->next = (*head);
        (*head) = p;
        return;
    }

    //if it is greater than current tail
    if ((p->info) > ((*tail)->info))
    {
        p->prev = (*tail);
        (*tail)->next = p;
        (*tail) = p;
        return;
    }

    //IF NOT THEN IT LIES BETWEEN HEAD AND TAIL.
    node *temp = (*head)->next;
    while ((temp->info) < (p->info))
        temp = temp->next;

    
    (temp->prev)->next = p;
    p->prev = temp->prev;
    temp->prev = p;
    p->next = temp;
}


void display(node *temp)
{   
    if(temp == NULL){
        printf("\nList is empty\n");
    }
    else{
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    }
}

int main()
{
    node *left = NULL, *right = NULL;
    
    int ch;
    do{
        printf("\n1.Insert\n2.Display\n3.Exit\n\nEnter Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: insert(&left, &right);
            break;
           
        case 2:  
            display(left);
            break;
        case 3: exit(0);
            break;
        default:
            break;
        }
    }while(ch>0 && ch<=2);


    return 0;
}
