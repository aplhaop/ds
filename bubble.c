#include <stdio.h>

int main() {
    int i, j, n, arr[100], search, first, last, middle, temp;
    
    printf("How many elements you want to store in the array?: ");
    scanf("%d", &n);

    printf("Enter %d elements in the array:\n", n);
    for (i = 0; i < n; i++) { 
        scanf("%d", &arr[i]);
    }

    printf("Enter the element you want to search: ");
    scanf("%d", &search);

    for (i = 0; i < (n - 1); i++) {
        for (j = 0; j < (n - i - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    first = 0;
    last = n - 1;
    middle = (first + last) / 2;

    while (first <= last) {
        middle = (first + last) / 2; 

        if (arr[middle] < search) {
            first = middle + 1;
        } else if (arr[middle] == search) {
            printf("%d found at location %d.\n", search, middle + 1);
            break;
        } else {
            last = middle - 1;
        }
    }

    if (first > last) {
        printf("Not found! %d is not present in the list.\n", search);
    }

    return 0;
}