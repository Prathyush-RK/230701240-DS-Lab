#include <stdio.h>
#define size 100

int stack[size];
int top = -1, i;

void push() {
    int a;
    printf("Enter the data to insert in stack : ");
    scanf("%d", &a);
    if (top == size - 1) {
        printf("Stack is full\n");
    } else {
        top = top + 1;
        stack[top] = a;
    }
}

void pop() {
    int a;
    if (top == -1) {
        printf("The stack is empty\n");
    } else {
        a = stack[top];
        printf("Item popped is : %d\n", a);
        top--;
    }
}
 

void peek() {
    if (top == -1) {
        printf("The stack is empty\n");
    } else {
        printf("The top most element in the stack is : %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Items in the stack are : ");
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    printf("STACK IMPLEMENTATION USING ARRAY\n");
    printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
    do {
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
           case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting!!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
} 
