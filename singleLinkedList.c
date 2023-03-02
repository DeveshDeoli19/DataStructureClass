#include<stdio.h>
#include<stdlib.h>

typedef struct List{
    int data;
    struct List *next;
}node;

node* insertRight(node *);

node* insertLeft(node *);

void display(node *);

int main()
{
    node *head=NULL, *tail=NULL;

    int ch;

    do{
		printf("\n1.Insert At Right\n2.Insert At Left\n3.Display\n");
		printf("Enter Choice: ");scanf("%d",&ch);printf("\n");

		switch(ch){

			case 1: head = insertRight(head);break;
			case 2: head = insertLeft(head);break;
			case 3: display(head);break;
			default: printf("\nInvalid choice\n");break;
		}
	}while(ch>=0 && ch<=3);
    return 0;
}

node* insertRight(node *head){

    int x;
    node *l= (node*) malloc(sizeof(node)),*temp=NULL;
    printf("\nEnter Data: ");scanf("%d",&x);
    if(l != NULL){
     if(head == NULL){
        
        l->data = x;
        head = l;
     }
     else{
        temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = l;
        l->data = x;
     }
     l->next = NULL;
    }
    return head;
}

node* insertLeft(node *head){

    int x;
    node *l= (node*) malloc(sizeof(node)),*temp=NULL;
    printf("\nEnter Data: ");scanf("%d",&x);
    if(l != NULL){
     if(head == NULL){
        
        l->data = x;
        head = l;
        l->next = NULL;
     }
     else{
        l->data = x;
        l->next = head;
        head = l;
     }
    }
    return head;
}

void display(node *head){

    if(head == NULL){
        printf("\nList is empty\n");
    }

    else{
        while(head != NULL){
            printf("%d -> ",head->data);
            head = head->next;
        }
        printf("NULL\n\n");
    }
}
