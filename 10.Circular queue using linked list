AIM:
To implement a Circular Queue using Linked List in C with the operations:
Enqueue (Insert)
dequeue (Delete)
Display

program:
#include <stdio.h>
#include <stdlib.h>

// Node structure for each element in the circular queue
struct Node {
    int data;
    struct Node *next;
};

// FRONT points to first node, REAR points to last node
struct Node *FRONT = NULL, *REAR = NULL;

// Function to create a new node with given data
struct Node* CreateNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode != NULL) {
        newNode->data = x;
        newNode->next = NULL;
    }
    return newNode;
}

// -------------------------
// INSERTION (ENQUEUE)
// -------------------------
void enqueue(int x) {
    struct Node* NewNode = CreateNode(x);

    // Memory allocation failed
    if(NewNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }

    // If queue is empty, FRONT and REAR both point to the new node
    if(FRONT == NULL) {
        FRONT = NewNode;
        REAR = NewNode;
        REAR->next = FRONT;  // Circular Link
    }
    else {
        REAR->next = NewNode;  // Attach after last node
        REAR = NewNode;        // Move REAR to new node
        REAR->next = FRONT;    // Maintain circular link
    }

    printf("%d inserted into circular queue.\n", x);
}

// -------------------------
// DELETION (DEQUEUE)
// -------------------------
int dequeue() {

    // If queue empty
    if(FRONT == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }

    // If only one node present
    if(FRONT == REAR) {
        int value = FRONT->data;
        free(FRONT);
        FRONT = REAR = NULL;
        return value;
    }

    // More than one node
    struct Node* temp = FRONT;
    int value = temp->data;

    FRONT = FRONT->next;     // Move FRONT ahead
    REAR->next = FRONT;      // Maintain circular link
    free(temp);

    return value;
}

// -------------------------
// DISPLAY ALL ELEMENTS
// -------------------------
void display() {
    if(FRONT == NULL) {
        printf("Circular Queue is Empty\n");
        return;
    }

    struct Node* t = FRONT;
    printf("Circular Queue elements: ");

    // Loop until we reach FRONT again
    do {
        printf("%d ", t->data);
        t = t->next;
    } while(t != FRONT);

    printf("\n");
}

// -------------------------
// MAIN FUNCTION
// -------------------------
int main() {
    int ch, val;

    while(1) {
        printf("\n--- Queue Using Linked List Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if(ch == 1) {
            printf("Enter data to insert: ");
            scanf("%d", &val);
            enqueue(val);
        }
        else if(ch == 2) {
            int v = dequeue();
            if(v != -1)
                printf("Deleted element: %d\n", v);
        }
        else if(ch == 3) {
            display();
        }
        else if(ch == 4) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}


OUTPUT:
--- Queue Using Linked List Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter data to insert: 10
10 inserted into circular queue.

--- Queue Using Linked List Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter data to insert: 20
20 inserted into circular queue.

--- Queue Using Linked List Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter data to insert: 30
30 inserted into circular queue.

--- Queue Using Linked List Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Circular Queue elements: 10 20 30

--- Queue Using Linked List Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Deleted element: 10

--- Queue Using Linked List Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Circular Queue elements: 20 30

--- Queue Using Linked List Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4
Exiting...



RESULT:Program sucessfully demonstrates Circular queue using linked list.







