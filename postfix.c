#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int evaluatePostfix(char* exp) {
    int i = 0;
    char ch;
    while ((ch = exp[i++]) != '\0') {
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (ch) {
                case '+': push(val1 + val2); 
                    break;
                case '-': push(val1 - val2); 
                    break;
                case '*': push(val1 * val2); 
                    break;
                case '/': push(val1 / val2); 
                    break;
                case '%': push(val1 % val2); 
                    break;
                default: printf("Invalid operator!\n"); 
                    exit(1);
            }
        }
    }
    return pop();
}

int main() {
    char postfix[MAX];
    
    printf("Enter a valid postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of the postfix expression: %d\n", result);
    
    return 0;
}