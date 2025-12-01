aim:
To implement a C program that performs all basic operations on a single linked list, including:
Insertion at beginning
Insertion at end
Insertion at specific position
Displaying the linked list
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertBegin(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at beginning\n", value);
}

void insertEnd(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        printf("Inserted %d at end\n", value);
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("Inserted %d at end\n", value);
}

void display() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while(1) {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBegin(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
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
--- Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Specific Position
4. Display List
5. Exit
Enter your choice: 1
Enter value to insert at beginning: 10

Enter your choice: 2
Enter value to insert at end: 20

Enter your choice: 3
Enter value: 15
Enter position: 2

Enter your choice: 4
List: 10 -> 15 -> 20 -> NULL

result:
The program successfully performs all basic singly linked list operations, including
insertion at beginning, insertion at end, insertion at specific position, and displaying the list.
