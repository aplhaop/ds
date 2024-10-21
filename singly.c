#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);

int main() {
    int option;
    do {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: Sort the list");
        printf("\n 13: EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: front = create_ll(front);
                    printf("\n LINKED LIST CREATED");
                    break;

            case 2: front = display(front);
                    break;
            
            case 3: front = insert_beg(front);
                    break;

            case 4: front = insert_end(front);
                    break;

            case 5: front = insert_before(front);
                    break;

            case 6: front = insert_after(front); 
                    break;

            case 7: front = delete_beg(front);
                    break;

            case 8: front = delete_end(front);
                    break;
            
            case 9: front = delete_node(front);
                    break;

            case 10: front = delete_after(front); 
                    break;
            
            case 11: front = delete_list(front);
                    printf("\n LINKED LIST DELETED");
                    break;

            case 12: front = sort_list(front);
                    break;
        }
    } while (option != 13);
    return 0;
}

struct node *create_ll(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data: ");
    scanf("%d", &num);
    while (num != -1) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        if (start == NULL) {
            start = new_node;
        } else {
            ptr = start;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }
        printf("\n Enter the data: ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start) {
    struct node *ptr = start;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return start;
    }
    while (ptr != NULL) {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

struct node *insert_beg(struct node *start) {
    struct node *new_node;
    int num;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    return new_node;
}

struct node *insert_end(struct node *start) {
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    if (start == NULL) {
        return new_node;
    }
    ptr = start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return start;
}

struct node *insert_before(struct node *start) {
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    if (ptr == NULL) {
        printf("List is empty.\n");
        free(new_node);
        return start;
    }
    if (ptr->data == val) {
        new_node->next = start;
        return new_node;
    }
    while (ptr != NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Value %d not found in the list.\n", val);
        free(new_node);
        return start;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

struct node *insert_after(struct node *start) {
    struct node *new_node, *ptr;
    int num, val;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    if (ptr == NULL) {
        printf("List is empty.\n");
        free(new_node);
        return start;
    }
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Value %d not found in the list.\n", val);
        free(new_node);
        return start;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    return start;
}

struct node *delete_beg(struct node *start) {
    struct node *ptr;
    if (start == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return start;
    }
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start) {
    struct node *ptr, *preptr;
    if (start == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return start;
    }
    ptr = start;
    if (ptr->next == NULL) {
        free(ptr);
        return NULL;
    }
    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}

struct node *delete_node(struct node *start) {
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value of the node which has to be deleted: ");
    scanf("%d", &val);
    ptr = start;
    if (ptr == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return start;
    }
    if (ptr->data == val) {
        return delete_beg(start);
    }
    while (ptr != NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Value %d not found in the list.\n", val);
        return start;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}

struct node *delete_after(struct node *start) {
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value after which the node has to be deleted: ");
    scanf("%d", &val);
    ptr = start;
    if (ptr == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return start;
    }
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }
    if (ptr == NULL || ptr->next == NULL) {
        printf("No node to delete after value %d.\n", val);
        return start;
    }
    struct node *node_to_delete = ptr->next;
    ptr->next = node_to_delete->next;
    free(node_to_delete);
    return start;
}

struct node *delete_list(struct node *start) {
    struct node *ptr;
    while (start != NULL) {
        ptr = start;
        start = start->next;
        free(ptr);
    }
    return start;
}

struct node *sort_list(struct node *start) {
    struct node *ptr1, *ptr2;
    int temp;
    if (start == NULL) {
        return start;
    }
    for (ptr1 = start; ptr1->next != NULL; ptr1 = ptr1->next) {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
            if (ptr1->data > ptr2->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }
    return start;
}