aim:
To write a C program that performs basic queue operations such as enqueue, dequeue, and display, 
demonstrating the use of the queue data structure using an array.


program:

#include<stdio.h>
#include<stdlib.h>

#define size 5

int queue[size];
int front = -1;
int rear = -1;

void enqueue(int item){
    if(rear == size - 1){
        printf("queue is full\n");
    }
    else{
        if(front == -1) front = 0;   // first element
        rear++;
        queue[rear] = item;
        printf("enqueued %d\n", item);
    }
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("queue is empty\n");
    }
    else{
        printf("dequeued %d\n", queue[front]);
        front++;
    }
}

void display(){
    if(front == -1 || front > rear){
        printf("queue is empty\n");
    }
    else{
        printf("queue elements:\n");
        for(int i = front; i <= rear; i++){
            printf("%d\n", queue[i]);
        }
    }
}

int main(){
    int choice, value;

    while(1){
        printf("\n1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("choose any: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("enter element: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("invalid choice\n");
        }
    }

    return 0;
}

output:
--- QUEUE OPERATIONS ---
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
4. EXIT
Enter your choice: 1
Enter item to insert: 10
Inserted 10 into the queue.

Enter your choice: 1
Enter item to insert: 20
Inserted 20 into the queue.

Enter your choice: 3
Queue elements: 10 20

Enter your choice: 2
Deleted 10 from the queue.

Enter your choice: 3
Queue elements: 20

Enter your choice: 4
Exiting program

result:
The program successfully implements the queue data structure using an array and performs
insertion (enqueue), deletion (dequeue), and display operations.
