#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *createLL(struct node *);
void display(struct node *);
struct node *insertBeg(struct node *);
struct node *insertEnd(struct node *);
struct node *deleteBeg(struct node *);
struct node *deleteEnd(struct node *);

int main() {
    int option;
    do {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Delete a node from the beginning");
        printf("\n 6: Delete a node from the end");
        printf("\n 7: EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: front = createLL(front);
                    printf("\n LINKED LIST CREATED");
                    break;

            case 2: display(front);
                    break;
            
            case 3: front = insertBeg(front);
                    break;

            case 4: front = insertEnd(front);
                    break;

            case 5: front = deleteBeg(front);
                    break;

            case 6: front = deleteEnd(front);
                    break;

            case 7: printf("Exiting...\n");
                    break;

            default: printf("Invalid option. Please try again.\n");
        }
    }
    while (option != 7);
    return 0;
}

struct node *createLL(struct node *start) {
    struct node *newNode, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data: ");
    scanf("%d", &num);
    while (num != -1) {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;
        newNode->next = NULL;
        if (start == NULL) {
            start = newNode;
            newNode->next = start; // Point to itself
        } else {
            ptr = start;
            while (ptr->next != start) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = start; // Complete the circular link
        }
        printf("\n Enter the data: ");
        scanf("%d", &num);
    }
    return start;
}

void display(struct node *start) {
    struct node *ptr = start;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    do {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    printf("\n");
}

struct node *insertBeg(struct node *start) {
    struct node *newNode, *ptr;
    int num;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;

    if (start == NULL) {
        start = newNode;
        newNode->next = start; // Point to itself
    } else {
        ptr = start;
        while (ptr->next != start) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = start;
        start = newNode;
    }
    return start;
}

struct node *insertEnd(struct node *start) {
    struct node *newNode, *ptr;
    int num;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;

    if (start == NULL) {
        start = newNode;
        newNode->next = start; // Point to itself
    } else {
        ptr = start;
        while (ptr->next != start) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = start;
    }
    return start;
}

struct node *deleteBeg(struct node *start) {
    struct node *ptr;
    if (start == NULL) {
        printf("List is empty. Underflow.\n");
        return start;
    }
    ptr = start;
    while (ptr->next != start) {
        ptr = ptr->next;
    }
    if (start == ptr) { // Only one node
        free(start);
        return NULL;
    }
    ptr->next = start->next;
    free(start);
    return ptr->next;
}

struct node *deleteEnd(struct node *start) {
    struct node *ptr, *prev;
    if (start == NULL) {
        printf("List is empty. Underflow.\n");
        return start;
    }
    ptr = start;
    prev = NULL;
    while (ptr->next != start) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == start) { // Only one node
        free(start);
        return NULL;
    }
    prev->next = start;
    free(ptr);
    return start;
}