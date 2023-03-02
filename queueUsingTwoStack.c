#include<stdio.h>
#define max 10

void insert(int [], int *);
void serve(int [], int [], int *, int *);
void display(int [],int [], int *, int *);
// void peek(int [],int [], int *, int *);

int main(){

	int stack[max], top=-1, stack2[max], top2=-1, ch;

	do{
		printf("\n1.Push\n2.Pop\n3.Display\n");
		printf("Enter Choice: ");scanf("%d",&ch);printf("\n");

		switch(ch){

			case 1: insert(stack, &top);break;
			case 2: serve(stack,stack2, &top, &top2);break;
			case 3: display(stack,stack2, &top,&top2);break;
			default: printf("\nInvalid choice\n");break;
		}
	}while(ch>=0 && ch<=3);
	return 0;
}

void insert(int stack[], int *top){

	int value;
	if((*top) == max-1){
		printf("\nQueue is Full\n");
	}
	else{
		(*top)++;
		printf("\nEnter value: ");scanf("%d",&value);
		stack[*top]= value;
	}
}

void serve(int stack[], int stack2[], int *top, int *top2){

	
	if((*top) == -1 && (*top2) == -1){
		printf("\nQueue is Empty\n");
	}
	else{   


        if((*top2) == -1){

            while((*top != -1)){
                stack2[++(*top2)] = stack[(*top)--];
            }
        }
		
		printf("\nValue Popped: %d\n",stack2[*top2]);
		(*top2)--;
		
	}
}

void display(int stack[], int stack2[], int *top, int *top2){

	int i=(*top);int j=(*top2);
	if((*top) == -1 && (*top2) == -1){
		printf("\nQueue is Empty\n");
	}
	else{
		
         for(j=(*top);j>=0;j--)
		 printf("%d ",stack[j]);

            for(i=(*top2);i>=0;i--)
		 printf("%d ",stack2[i]);
         
	  printf("\n");	
	}
}

