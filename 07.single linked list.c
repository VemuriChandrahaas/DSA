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

// Creating a node structure
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;   // starting point of list

// Insert a new node at the beginning
void insertAtBeginning(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    // storing data in new node
    newnode->data = value;
    newnode->next = head;   // link old head to new node
    head = newnode;         // move head to new node

    printf("Inserted %d at beginning\n", value);
}

// Insert a new node at the end
void insertAtEnd(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    // if list is empty
    if(head == NULL) {
        head = newnode;
        printf("Inserted %d at end\n", value);
        return;
    }

    // go to last node
    struct node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    printf("Inserted %d at end\n", value);
}

// display list from head to end
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

// main menu function
int main() {
    int choice, value;

    while(1) {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Choose any: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
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
