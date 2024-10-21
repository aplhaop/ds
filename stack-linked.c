#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *top = NULL;
struct node *push(struct node *, int);
struct node *pop(struct node *);
struct node *display(struct node *);
int peek(struct node *);

int main() {
    int val, option;
    do {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1: Push");
        printf("\n 2: Pop");
        printf("\n 3: Peek");
        printf("\n 4: Display");
        printf("\n 5: EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\n Enter the number to push: ");
                scanf("%d", &val);
                top = push(top, val);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                val = peek(top);
                if (val != -1) {
                    printf("\n The value at the top of the stack is: %d", val);
                } else {
                    printf("\n Stack is empty.");
                }
                break;

            case 4:
                top = display(top);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    while (option != 5);
    return 0;
}

struct node *push(struct node *top, int val) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    if (top == NULL) {
        ptr->next = NULL;
        top = ptr;
    } else {
        ptr->next = top;
        top = ptr;
    }
    return top;
}

struct node *pop(struct node *top) {
    struct node *ptr;
    if (top == NULL) {
        printf("\n Stack Underflow! Unable to pop.");
    } else {
        ptr = top;
        top = top->next;
        printf("\n Value popped: %d", ptr->data);
        free(ptr);
    }
    return top;
}

struct node *display(struct node *top) {
    struct node *ptr;
    if (top == NULL) {
        printf("\n Stack is empty.");
    } else {
        ptr = top;
        printf("\n Stack elements are:\n");
        while (ptr != NULL) {
            printf("\t %d", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    return top;
}

int peek(struct node *top) {
    if (top == NULL) {
        return -1;
    } else {
        return top->data;
    }
}