#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
    int data;
    struct Stack *next;
} stk;

void push(stk **);

void pop(stk **);

void display(stk *);


int main()
{
    stk *top = NULL;

    int ch;

    do
    {
        printf("\n1.Push \n2.Pop\n3.Display\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);
        printf("\n");

        switch (ch)
        {

        case 1:
            push(&top);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            display(top);
            break;
        default:
            printf("\nInvalid choice\n");
            break;
        }
    } while (ch >= 0 && ch <= 3);
    return 0;
}

void push(stk **top){

    stk *p = NULL;
    int x;

    p= (stk*)malloc(sizeof(stk));

    if(p != NULL){

        printf("\nEnter value:");scanf("%d",&x);
        p->data = x;
        p->next = (*top);
        (*top) = p;
    }

}

void pop(stk **top){

    stk *p = NULL;

    if((*top) != NULL){

        printf("\nValue Popped: %d\n",(*top)->data);
        p=(*top);
        (*top)=(*top)->next;
        free(p);
    }
    else{
        printf("\nStack is empty\n");
    }

}

void display(stk *top){

    if(top != NULL){
        while(top != NULL){
             printf("%d -> ",top->data);
             top = top->next;
        }
        printf("NULL\n");
    }
    else{
        printf("\nStack is Empty\n");
    }
}