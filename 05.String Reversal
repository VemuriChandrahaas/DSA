
Aim:
To reverse a given string using stack data structure.

Code:

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top = -1, max;
char *stack;

// Push a character into stack
void push(char item)
{
    if (top == max - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

// Pop a character from stack
char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

// Function to reverse a string using stack
void stringReversal()
{
    char string[100];

    printf("Enter a string (max %d characters): ", max);
    scanf("%s", string);

    int len = strlen(string);  // Actual length of input string

    // Push each character into stack
    for (int i = 0; i < len; i++)
    {
        push(string[i]);
    }

    // Pop characters to print reversed string
    printf("Reversed string: ");
    for (int i = 0; i < len; i++)
    {
        char ch = pop();
        printf("%c", ch);
    }
    printf("\n");
}

int main()
{
    printf("Enter the size of the character stack: ");
    scanf("%d", &max);

    // Allocate memory for stack
    stack = (char *)malloc(max * sizeof(char));

    if (stack == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    stringReversal();

    free(stack); // Free allocated memory
    return 0;
}


output:
Enter the size of char stack: 20
Enter the string to reverse: hello
Reversed string: olleh

result:
The program successfullY demonstrates string reversal using POP & PUSH.
