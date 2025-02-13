#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

void enqueue(int num);
void dequeue();
void display();

int arr[MAX], front = -1, rear = -1, num;

int main() {
    int choice;

    printf("Performing the Queue operation...\n");
    printf("Enter the size of the queue (max %d): ", MAX);
    scanf("%d", &num);

    if (num > MAX) {
        printf("Number exceeded the maximum value! Setting queue size to %d.\n", MAX);
        num = MAX;
    }

    while (1) {
        printf("\nChoose one from the below options:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(num);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program!\n");
                exit(0);
            default:
                printf("❌ Please enter a valid option (1-4)!\n");
        }
    }
}

void enqueue(int num) {
    int value;

    if (rear == num - 1) {
        printf("❌ Queue Overflow! Cannot insert more elements.\n");
    } else {
        printf("Enter the value to enqueue: ");
        scanf("%d", &value);

        if (front == -1) {
            front = 0; 
        }

        rear++;
        arr[rear] = value;
        printf("✅ %d added to the queue.\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("❌ Queue Underflow! No elements to dequeue.\n");
        front = rear = -1; 
    } else {
        printf("✅ Dequeued element: %d\n", arr[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("📭 Queue is empty!\n");
    } else {
        printf("📌 Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
