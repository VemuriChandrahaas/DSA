Aim:
To convert an infix expression to postfix expression using stack operation.

Code:

#include <stdio.h>
#include <ctype.h>  // For isalnum() to check alphabets & digits

char stack[20];     // Stack to store operators
int top = -1;       // Stack top index

// Push an element to stack
void push(char c) {
    stack[++top] = c;
}

// Pop an element from stack
char pop() {
    return stack[top--];
}

// Function to return precedence of operators
int prec(char c) {
    if (c == '^') return 3;       // Highest precedence
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Convert infix → postfix
void infixtopostfix(char infix[]) {
    char postfix[20], ch;
    int i = 0, k = 0;  // i for input scanning, k for postfix index

    while ((ch = infix[i++]) != '\0') {

        // If character is letter/number → directly add to postfix
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }

        // If '(' → push to stack
        else if (ch == '(') {
            push(ch);
        }

        // If ')' → pop everything until '('
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            if (top != -1)
                pop(); // remove '('
        }

        // Operator encountered (+, -, *, /, ^)
        else {
            // Pop all operators with higher or equal precedence
            while (top != -1 && prec(stack[top]) >= prec(ch))
                postfix[k++] = pop();

            // Push current operator
            push(ch);
        }
    }

    // Pop remaining operators from stack
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';  // Null-terminate the result

    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[20];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixtopostfix(infix);

    return 0;
}


output:
Input:
Enter infix expression: A+B*C

Output:
Postfix expression: ABC*+

result:
The program successfully converts a given infix expression into its equivalent 
postfix expression using stack operations and precedence rules.

