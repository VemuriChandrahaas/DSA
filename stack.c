Aim:To implement a program that performs basic stack operations such as push, pop and peek
demonstrating the use of the stack data structure using an array 

#include<stdio.h>

int TOP = -1, MAX;

void display(int stack[])
{
    printf("current stack elements are - \n");
    
    for(int i=0; i <= TOP; i++)}
    printf("(TOP)");
}

void push (int stack[]){
    if(TOP == -1)
    {
        printf("top element in the stack : %d \n", stack[TOP]);
        TOP = TOP - 1;
    }
    
}

int main()
{
  int operation=0, TOP = -1;
  
  printf("enter the size of stack:");
  


    
while(operation !=3){
        printf("\n 1.push \n 2.pop \n 3.exit \n");
        printf("please choose stack operations to perform: ");
        scanf("%d", &operation);
        
        switch(operation){
            case 1:
            push(STACK);
            display(STACK);
            break;
            
            case 2:
            pop(STACK);
            display(STACK);
            break;
            
            case 3:
             return 0;
        }
        return 0;
    }

}
