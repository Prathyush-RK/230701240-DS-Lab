#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}Node;

void enqueue(Node** queue,int val){
	Node* newnode=malloc(sizeof(Node));
	Node* cur;
	if(newnode){

		newnode->data =val;
		newnode->next = NULL;
		if(*queue==NULL){
			*queue = newnode;
			cur =*queue;
		}
		else{
			cur->next= newnode;
			cur = newnode;
		}
	}
	else{
		printf("\nMemory allocation failed\n");
		exit(1);
	}
}

void peek(Node* queue){
	if(queue){
		printf("\nThe first element in the queue is %d",queue->data);
	}
	else{
		printf("\nThe queue is empty");
		return;
	}
}

int dequeue(Node** queue){
	if(*queue){
		Node* temp = *queue;
		(*queue) = (*queue)->next;
		int x = temp->data;
		free(temp);
		return x;
	}
 
	else{
		printf("\nQueue is empty");
		return -1;
	}
}


void display(Node* queue){
	if(queue){
		while(queue){
			printf("%d\t",queue->data);
			queue = queue->next;
		}
	}
	else{
		printf("\nThe queue is empty");
		return;
	}
}

int main(){
	Node* queue= NULL;
	int n,choice;
	do{
		printf("\n1. ENQUEUE\n2. DEQUEUE \n3. PEEK \n4. DISPLAY \n5.EXIT");
		printf("\nENTER YOUR CHOICE: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				printf("\nEnter the element to enqueue: ");
				scanf("%d",&n);
				enqueue(&queue,n);
				break;
			}
			case 2:{
				n = dequeue(&queue);
				if(n!=-1){
					printf("\nThe dequeued element is %d",n);
					break;
				}
				}
			case 3: peek(queue); break;
			case 4: display(queue); break;
		}

	}while(choice<=4);
	
	return 0;
}
