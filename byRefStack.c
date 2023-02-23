#include<stdio.h>
#define max 10

void push(int [], int *);
void pop(int [], int *);
void display(int [], int *);
void peek(int [], int *);

int main(){

	int stack[max], top=-1, ch;

	do{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Peek\n");
		printf("Enter Choice: ");scanf("%d",&ch);printf("\n");

		switch(ch){

			case 1: push(stack, &top);break;
			case 2: pop(stack, &top);break;
			case 3: display(stack, &top);break;
			case 4: peek(stack, &top);break;
			default: printf("\nInvalid choice\n");break;
		}
	}while(ch>=0 && ch<=4);
	return 0;
}

void push(int stack[], int *top){

	int value;
	if((*top) == max-1){
		printf("\nStack is Full\n");
	}
	else{
		(*top)++;
		printf("\nEnter value: ");scanf("%d",&value);
		stack[*top]= value;
	}
}

void pop(int stack[], int *top){

	
	if((*top) == -1){
		printf("\nStack is Empty\n");
	}
	else{
		
		printf("\nValue: %d",stack[*top]);
		(*top)--;
		
	}
}

void display(int stack[], int *top){

	int i=(*top);
	if((*top) == -1){
		printf("\nStack is Empty\n");
	}
	else{
		for(i=(*top);i>=0;i--)
		 printf("%d ",stack[i]);

	  printf("\n");	
	}
}

void peek(int stack[], int *top){

	if((*top) == -1){
		printf("\nStack is Empty\n");
	}
	else{
		 printf("\nValue at top: %d ",stack[*top]);
		printf("\n\n");
	}
}