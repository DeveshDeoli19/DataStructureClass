#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int data;
    struct List *next;
} node;

node *insertRight(node *);

node *insertLeft(node *);

node* delete(node *);

void display(node *);

node* reverse(node *);

node* sort(node *);

void swap (node *, node *);
int main()
{
    node *head = NULL, *tail = NULL;

    int ch;

    do
    {
        printf("\n1.Insert At Right\n2.Insert At Left\n3.Display\n4.Reverse\n5.Sort\n");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);
        printf("\n");

        switch (ch)
        {

        case 1:
            head = insertRight(head);
            break;
        case 2:
            head = insertLeft(head);
            break;
        case 3:
            display(head);
            break;
        case 4: head = reverse(head);
            break;
        case 5: head = sort(head);
        break;
        default:
            printf("\nInvalid choice\n");
            break;
        }
    } while (ch >= 0 && ch <= 5);
    return 0;
}

node *insertRight(node *head)
{

    int x;
    node *l = (node *)malloc(sizeof(node)), *temp = NULL;
    printf("\nEnter Data: ");
    scanf("%d", &x);
    if (l != NULL)
    {
        if (head == NULL)
        {

            l->data = x;
            head = l;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = l;
            l->data = x;
        }
        l->next = NULL;
    }
    return head;
}

node *insertLeft(node *head)
{

    int x;
    node *l = (node *)malloc(sizeof(node)), *temp = NULL;
    printf("\nEnter Data: ");
    scanf("%d", &x);
    if (l != NULL)
    {
        if (head == NULL)
        {

            l->data = x;
            head = l;
            l->next = NULL;
        }
        else
        {
            l->data = x;
            l->next = head;
            head = l;
        }
    }
    return head;
}

void display(node *head)
{

    if (head == NULL)
    {
        printf("\nList is empty\n");
    }

    else
    {
        while (head != NULL)
        {
            printf("%d -> ", head->data);
            head = head->next;
        }
        printf("NULL\n\n");
    }
}

node* reverse(node *head){

    node* pre=NULL,*curr=head,*nxt=NULL;

    if (head == NULL)
    {
        printf("\nList is empty\n");
    }

    else{
    while(curr != NULL){

        nxt = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nxt;
    }
    printf("\nLinked List reversed Successfully\n");
    }
    return pre;
}

node* sort( node *head) 
{ 
    int s, i; 
    node *ptr1; 
    node *lptr = NULL; 
  
    /* Checking for empty list */
    if (head == NULL) 
        printf("\nList is Empty\n"); 
  
  else{
    do
    { 
        s = 0; 
        ptr1 = head; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data > ptr1->next->data) 
            { 
                swap(ptr1, ptr1->next); //swap data  of nodes
                s = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (s); 
   
    printf("\nLinked List reversed Successfully\n");

     }
    return head;
} 

void swap(node *a, node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 