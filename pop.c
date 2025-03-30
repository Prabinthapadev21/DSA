#include <stdio.h>
#include <stdlib.h>

#define SIZE 4  // Maximum allowed stack size

void push(int stack[], int *top, int max);
void pop(int stack[], int *top); 
void display(int stack[], int top);

int main() {
    int stack[SIZE], top = -1, choice, n;

    printf("Enter the number of elements allowed in the stack (max %d): ", SIZE);
    scanf("%d", &n);

    // If user enters a number greater than SIZE, restrict it to SIZE
    if (n > SIZE) {
        printf("⚠ Warning: You entered %d, which exceeds the limit! Setting max size to %d.\n", n, SIZE);
        n = SIZE;
    }

    printf("\n*************** Stack Operations ***************\n");

    while (1) {
        printf("\nChoose one from the below options:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(stack, &top, n);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("❌ Invalid choice! Please enter a correct option (1-4).\n");
        }
    }

    return 0;
}

// Function to push an element onto the stack
void push(int stack[], int *top, int max) {
    int value;
    if (*top == max - 1) {
        printf("❌ Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter the value: ");
        scanf("%d", &value);
        (*top)++;
        stack[*top] = value;
        printf("✅ %d pushed to the stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("❌ Stack Underflow! No elements to pop.\n");
    } else {
        printf("✅ Popped element: %d\n", stack[*top]);
        (*top)--;
    }
}

// Function to display the stack elements
void display(int stack[], int top) {
    if (top == -1) {
        printf("🛑 Stack is empty.\n");
    } else {
        printf("📌 Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
