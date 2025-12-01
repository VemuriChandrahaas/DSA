 Aim:To implement a program that performs basic stack operations such as push, pop and peek
demonstrating the use of the stack data structure using an array 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5        // stack size
#define MAX 50        // max string length

char stack[SIZE][MAX];
int top = -1;

void push(char item[]) {
    if (top == SIZE - 1) {
        printf("Stack is full\n");
    } else {
        top++;
        strcpy(stack[top], item);
        printf("Pushed: %s\n", item);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Popped: %s\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%s\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    char value[MAX];

    while (1) {
        printf("\n1. Push (String)\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Choose any: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter string: ");
                scanf("%s", value);    // reads a string (no spaces)
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


output:
Enter the size of stack: 3

1. Push
2. Pop
3. Peek
4. Exit
Choose operation: 1
Enter value to push: 10
Pushed 10
Current stack elements:
10 (TOP)

Choose operation: 1
Enter value to push: 20
Pushed 20
Current stack elements:
20 10 (TOP)

Choose operation: 3
Top element is: 20

Choose operation: 2
Popped element: 20
Current stack elements:
10 (TOP)

Choose operation: 4

result:
The program successfully implements the stack data structure 
using an array and performs the operations push, pop, peek, and display.
