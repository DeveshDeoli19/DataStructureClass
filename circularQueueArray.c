#include<stdio.h>
#define max 10

int insert(int[], int, int);
int serve(int[], int, int);
void display(int[], int, int);

int main(){

    int cq[max], f=-1, r=-1, ch;

    do{
		printf("\n1.Insert\n2.Delete\n3.Display\n");
		printf("Enter Choice: ");scanf("%d",&ch);printf("\n");

		switch(ch){

			case 1: r= insert(cq,f,r);
					if(f == -1) f=0;
			break;
			case 2: f= serve(cq,f,r);
					if(f == -1) r=-1;
			break;
			case 3: display(cq,f,r);break;
			
			default: printf("\nInvalid choice\n");break;
		}
	}while(ch>=0 && ch<=3);
	return 0;
}

int insert(int cq[], int f, int r){

	int val;
	if((r == max-1 && f == 0) || (f == r+1))
		printf("\nQueue is full\n");
	else{
		printf("\n Enter a value: ");scanf("%d",&val);
		
        if( f>0 && r== max-1){
            r=0;
            cq[r] = val;
        }
        else{
            r++;
            cq[r] = val;
        }

	}
	return r;
}

int serve(int cq[], int f, int r){

	if(f == -1)
		printf("\nQueue is empty\n");
	else{

		if(f == r){
			printf("Value removed: %d",cq[f]);
			f=-1;
		}

		else if(f == max-1){
			printf("Value removed: %d",cq[f]);
			f=0;
		}
        else{
            printf("Value removed: %d",cq[f]);
			f++;
        }

	}
	return f;
}

void display(int cq[], int f, int r){

    int i;
    if(f==-1)
        printf("\nQueue is empty\n");

     else{
        if(f<=r){
            while(f<=r)
                printf("%d ",cq[f++]);
        }
        else{

            while(f<=max-1)
                printf("%d ",cq[f++]);
            i=0;
            while(i<=r)
                printf("%d ",cq[i++]);
        }   
     }   
}