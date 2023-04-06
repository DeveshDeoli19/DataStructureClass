#include <stdio.h>
#include <stdlib.h>

typedef struct doubleLinkedList
{

    int data;
    struct doubleLinkedList *pre;
    struct doubleLinkedList *next;
} node;

node *insert(node *);

void display1(node *);
void display2(node *);
void display3(node *, node *);

int main()
{

    int ch;
    node *head = NULL, *tail = NULL;

    do
    {
        printf("1. Insert\n2. Display from head to tail\n3. Display from head to tail\n4. Display without overlapping\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        printf("\n\n");

        switch (ch)
        {

        case 1:
            tail = insert(tail);
            if (head == NULL)
                head = tail;
            break;

        case 2:
            display1(head);
            break;

        case 3:
            display2(tail);
            break;

        case 4:
            display3(head, tail);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\nWrong choice\n");
        }

    } while (ch >= 1 && ch <= 5);

    return 0;
}

node *insert(node *tail)
{

    node *p = NULL;
    int x;
    p = (node *)malloc(sizeof(node));

    if (p != NULL)
    {
        printf("Enter data: ");
        scanf("%d", &x);
        p->data = x;

        if (tail == NULL)
        {
            tail = p;
            tail->pre = NULL;
        }

        else
        {
            tail->next = p;
            p->pre = tail;
            tail = p;
        }
        tail->next = NULL;
    }
    printf("\n\n");
    return tail;
}

void display1(node *head)
{

    if (head == NULL)
        printf("\nEmpty\n");

    else
    {
        printf("\n\nHead to tail\n\n");
        while (head != NULL)
        {

            printf("%d -> ", head->data);
            head = head->next;
        }
        printf("NULL");
    }
    printf("\n\n");
}

void display2(node *tail)
{

    if (tail == NULL)
        printf("\nEmpty\n");

    else
    {
        printf("\n\nTail to head\n\n");
        while (tail != NULL)
        {

            printf("%d -> ", tail->data);
            tail = tail->pre;
        }
        printf("NULL");
    }
    printf("\n\n");
}

void display3(node *head, node *tail)
{

    if (tail == NULL)
        printf("\nEmpty\n");

    else
    {
        while (head != tail)
        {

            printf("%d -> ", head->data);
            head = head->next;
            tail = tail->pre;
        }
        while (tail != NULL)
        {

            printf("%d -> ", tail->data);

            tail = tail->next;
        }
        printf("NULL");
    }
    printf("\n\n");
}