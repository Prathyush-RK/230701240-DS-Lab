#include<stdio.h>
#define MAX 10
int queue[MAX],front=-1,rear = -1;

void enqueue(int v){
	if(front == MAX-1){
		printf("\nQueue is full");
		return;
	}
	queue[++rear] = v;
	if(front == -1){
		front++;
	}
}

int dequeue(){
	if(front ==-1){
		printf("\nQueue is empty");
		return -1;
	}
	int temp = queue[front];
	if(front == rear){
		front = -1;
		rear = -1;
	}
	front++;
	return temp;
}

void peek(){
	if(front ==-1){
		printf("\nQueue is empty");
		return;
	}
	printf("\nThe first element in the queue is %d",queue[front]);

}

void display(){
	if(front ==-1){
		printf("\nQueue is empty");
		return;
	}
	printf("\nGiven queue is ");
	for (int i =front;i<=rear;i++)
		printf("%d\t",queue[i]);
	printf("\n");
	
}
 

int main(){
	int n,choice;
	do{
		printf("\n1. ENQUEUE\n2. DEQUEUE \n3. PEEK \n4. DISPLAY \n5.EXIT");
		printf("\nENTER YOUR CHOICE: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				printf("\nEnter the element to enqueue: ");
				scanf("%d",&n);
				enqueue(n);
				break;
			}
			case 2:{
				n = dequeue();
				if(n!=-1){
					printf("\nThe dequeued element is %d",n);
					break;
				}
				}
			case 3: peek(); break;
			case 4: display(); break;
		}

	}while(choice<=4);
}
