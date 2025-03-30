#include <stdio.h>

void insert(int a[], int *n);

int main() {
    int a[10], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    insert(a, &n);

    printf("Updated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

void insert(int a[], int *n) {
    int pos, new_data;

    printf("Enter the position to enter the new data: ");
    scanf("%d", &pos);

    if (pos <= 0 || pos > *n + 1) {
        printf("Invalid position\n");
        return;
    }

    printf("Enter the new data: ");
    scanf("%d", &new_data);

    // Shift elements to the right
    for (int i = *n - 1; i >= pos - 1; i--) {
        a[i + 1] = a[i];
    }

    a[pos - 1] = new_data; // Insert new data
    (*n)++; // Increase the size of the array
}
