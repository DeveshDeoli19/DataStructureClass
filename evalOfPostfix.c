#include <stdio.h>
#include <stdlib.h>
#define max 50

void push(int, int *, int[]);
int pop(int *, int[]);
int eval(char, int, int);

int main()
{
    char a[50];
    int i, op1, op2, res, x, ch;
    int top = -1;
    int stack[max];
    printf("enter a postfix expression:");
    gets(a);
    for (i = 0; a[i] != '\0'; i++)
    {

        if (a[i] >= 97 && a[i] <= 122)
        {
            printf("Enter value of %c: ", a[i]);
            scanf("%d", &ch);
            push(ch, &top, stack);
        }
        else if (top >= 1)
        {
            op2 = pop(&top, stack);
            op1 = pop(&top, stack);
            res = eval(a[i], op1, op2);
            push(res, &top, stack);
        }
        else
        {
            printf("\n\nInvalid postfix expression\n\n");
            return -1;
        }
    }
    x = pop(&top, stack);
    if (top == -1)
        printf("evaluated value = %d", x);
    else
    {
        printf("\n\nInvalid postfix expression\n\n");
        return -1;
    }
    return 0;
}
void push(int ch, int *top, int stack[])
{

    (*top)++;
    stack[(*top)] = ch;
}
int pop(int *top, int stack[])
{
    int res;
    res = stack[(*top)];
    (*top)--;
    return res;
}
int eval(char ch, int op1, int op2)
{
    switch (ch)
    {
    case '+':
        return (op1 + op2);
    case '-':
        return (op1 - op2);
    case '*':
        return (op1 * op2);
    case '/':
        return (op1 / op2);
    }
}