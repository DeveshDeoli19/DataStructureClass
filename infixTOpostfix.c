#include <stdio.h>
#include<stdlib.h>
#define max 100

void push(char[], int *, char, char[],int *);
char pop(char[], int *);
int precedence(char);

int main()
{

    char stack[max];int top = -1;

    char infix[50];
    char postfix[50];

    int i, j = -1, val;

    printf("\n\nInput infix expression: ");
    gets(infix);
        push(stack,&top, '(', postfix, &j);
    // scan every element in postfix expression.
    for (i = 0; infix[i] != '\0'; i++)
    {   
        // if letter is encountered add it to postfix
        if (infix[i] >= 97 && infix[i] <= 122) 
        {
            j++;
            postfix[j] = infix[i];
        }

        // if any operator is found push in stack
        else{

            push(stack, &top,infix[i],postfix,&j);
        }
    }


    //after scanning all elements pop all elements from stack.
     while(stack[top] != '(' && top != 0){
            val = pop(stack,&top);
             j++;
            postfix[j] = val;//add popped elemennt to postfix expression
           
            }

    printf("\n\nPostfix Expression: ");
    for(i=0; i <= j; i++)
        printf("%c",postfix[i]);
    printf("\n\n");
    return 0;
}


void push(char stack[], int *top, char ch, char postfix[], int *j){

    char x;
	if(ch == '('){ //if left ( encountered simply push
		(*top)++;
		stack[*top]= ch;
	}
	else{

        if(precedence(ch) > precedence(stack[(*top)])){
        //if precedence of coming operator is greater than stack[top] then push
            (*top)++;
		stack[*top]= ch;
        }

        else if(precedence(ch) <= precedence(stack[(*top)]) && ch != ')')
		//if precedence of coming operator is smaller or equal to stack[top] then pop until higher precedence operator is not found.
        
        { 
            
        while( precedence(stack[*top]) >= precedence(ch)){

            x = pop(stack,top);
            (*j)++;
            postfix[(*j)] = x;
        }
        //when found push it to stack
        (*top)++;
		stack[*top]= ch;
        }
        else if(ch == ')'){ //if ) encounter pop till left ( encountered
            while(stack[*top] != '('){
            x = pop(stack,top);
            (*j)++;
            postfix[(*j)] = x;
            }
            (*top)--;
        }
	}
}

char pop(char stack[], int *top){

    char x;

		x = stack[(*top)];
		(*top)--;
		
    return x;
}

int precedence(char ch){

    if(ch == '^') return 5;

    else if( ch== '*' || ch== '/' || ch== '%') return 4;

    else if( ch== '+' || ch== '-') return 3;

    else return 2;
}