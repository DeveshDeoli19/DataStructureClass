#include<stdio.h>
#define max 10

int insert(int[], int);
int serve(int[], int, int);
void display(int[], int, int);

main(){

	int q[max], f=-1, r=-1, ch;

	do{
		printf("\n1.Insert\n2.Delete\n3.Display\n");
		printf("Enter Choice: ");scanf("%d",&ch);printf("\n");

		switch(ch){

			case 1: r= insert(q,r);
					if(f == -1) f=0;
			break;
			case 2: f= serve(q,f,r);
					if(f == -1) r=-1;
			break;
			case 3: display(q,f,r);break;
			
			default: printf("\nInvalid choice\n");break;
		}
	}while(ch>=0 && ch<=3);
	return 0;
}


int insert(int q[], int r){

	int val;
	if(r == max-1)
		printf("\nQueue is full\n");
	else{
		printf("\n Enter a value: ");scanf("%d",&val);
		r++;
		q[r] = val;

	}
	return r;
}


int serve(int q[], int f, int r){

	if(f == -1)
		printf("\nQueue is empty\n");
	else{

		if(f == r){
			printf("Value removed: %d",q[f]);
			f=-1;
		}

		else{
			printf("Value removed: %d",q[f]);
			f++;
		}

	}
	return f;
}


void display(int q[], int f, int r){

      if(f == -1)
		printf("\nQueue is empty\n");

	else{
		while(f<=r)
			printf("%d ",q[f++]);
	}

}
