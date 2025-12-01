aim:
To write a C program to perform all operations on a Doubly Linked List, including insertion 
(beginning, position, end), deletion (beginning, position, end, by value), searching, and
is playing the list in forward and backward directions.


Program:
#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct Node {
    int data;              // data value
    struct Node* next;     // pointer to next node
    struct Node* prev;     // pointer to previous node
};

// Head pointer (start of doubly linked list)
struct Node* head = NULL;

// Function to create and return a new node
struct Node* CreateNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;  // store value
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

/* ---------------------- INSERTION OPERATIONS ---------------------- */

// Insert new node at beginning
void InsertAtBeginning(int value) {
    struct Node* newNode = CreateNode(value);

    // Case 1: if list is empty
    if (head == NULL) {
        head = newNode;
    } 
    else {
        newNode->next = head;  // link new node with head
        head->prev = newNode;  // link head back to new node
        head = newNode;        // update head
    }
    printf("%d inserted at beginning.\n", value);
}

// Insert node at end of list
void InsertAtEnd(int value) {
    struct Node* newNode = CreateNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;

    // Move to last node
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;  // connect last node to new node
    newNode->prev = temp;  // link backward
    printf("%d inserted at end.\n", value);
}

// Insert node at a specific position
void InsertAtPosition(int value, int pos) {
    // Position 1 → beginning
    if (pos == 1) {
        InsertAtBeginning(value);
        return;
    }

    struct Node* temp = head;
    int k = 1;

    // Move to (pos-1)th node
    while (temp != NULL && k < pos - 1) {
        temp = temp->next;
        k++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* newNode = CreateNode(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;  // fix backward link

    temp->next = newNode;           // fix forward link

    printf("%d inserted at position %d.\n", value, pos);
}

/* ---------------------- DELETION OPERATIONS ---------------------- */

// Delete node at beginning
void DeleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;      // move head to next node

    if (head != NULL)
        head->prev = NULL;  // remove backward link

    printf("%d deleted from beginning.\n", temp->data);
    free(temp);
}

// Delete node at end
void DeleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    // Move to last node
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;  // remove link
    else
        head = NULL;              // only one node

    printf("%d deleted from end.\n", temp->data);
    free(temp);
}

// Delete node by value
void DeleteByValue(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    // Search for value
    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("%d not found.\n", value);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;  // deleting first node

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("%d deleted.\n", value);
    free(temp);
}

// Delete node at specific position
void DeleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    int k = 1;

    // Move to the position
    while (temp != NULL && k < pos) {
        temp = temp->next;
        k++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;  // deleting first node

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Node at position %d deleted.\n", pos);
    free(temp);
}

/* ---------------------- SEARCH & DISPLAY ---------------------- */

// Search value in list
void Search(int value) {
    struct Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("%d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("%d not found in list.\n", value);
}

// Print list forward and backward
void Display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    printf("Forward: ");
    while (temp->next != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);

    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

/* --------------------------- MAIN MENU --------------------------- */

int main() {
    int ch, val, pos;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n2. Insert at Position\n3. Insert at End\n");
        printf("4. Delete at Beginning\n5. Delete by Value\n6. Delete at Position\n");
        printf("7. Delete at End\n8. Search\n9. Display\n10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                InsertAtBeginning(val);
                break;

            case 2:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                InsertAtPosition(val, pos);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                InsertAtEnd(val);
                break;

            case 4:
                DeleteAtBeginning();
                break;

            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                DeleteByValue(val);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                DeleteAtPosition(pos);
                break;

            case 7:
                DeleteAtEnd();
                break;

            case 8:
                printf("Enter value to search: ");
                scanf("%d", &val);
                Search(val);
                break;

            case 9:
                Display();
                break;

            case 10:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

output:
Enter your choice: 1
Enter value to insert: 10
10 enqueued

Enter your choice: 1
Enter value to insert: 20
20 enqueued

Enter your choice: 1
Enter value to insert: 30
30 enqueued

Enter your choice: 3
Queue elements: 10 20 30

Enter your choice: 2
Dequeued: 10

Enter your choice: 3
Queue elements: 20 30

Enter your choice: 2
Dequeued: 20

Enter your choice: 2
Dequeued: 30

Enter your choice: 2
Queue Underflow

Enter your choice: 3
Queue is empty



result:
The program successfully implements all doubly linked list operations including insertion, deletion, search, and 
bidirectional traversal using a single unified program exactly as per the given PPT algorithms.
