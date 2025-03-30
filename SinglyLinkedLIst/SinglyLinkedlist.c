#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node NodeType;
NodeType *first = NULL, *last = NULL;

void insert_at_beginning(int);
void insert_given_position(int);
void insert_at_end(int);
void delete_at_beginning();
void delete_given_position();
void delete_at_end();
void delete_nth_node();
void info_sum();
void count_nodes();
void display();

int main() {
    int choice, item;
    do {
        printf("\nMenu for singly linked list:\n");
        printf("1. Insert at beginning\n2. Insert at given position\n3. Insert at end\n4. Delete at beginning\n");
        printf("5. Delete at given position\n6. Delete at end\n7. Delete nth node\n8. Info sum\n9. Count nodes\n");
        printf("10. Display\n11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &item);
                insert_at_beginning(item);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &item);
                insert_given_position(item);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &item);
                insert_at_end(item);
                break;
            case 4:
                delete_at_beginning();
                break;
            case 5:
                delete_given_position();
                break;
            case 6:
                delete_at_end();
                break;
            case 7:
                delete_nth_node();
                break;
            case 8:
                info_sum();
                break;
            case 9:
                count_nodes();
                break;
            case 10:
                display();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 11);
    return 0;
}

void insert_at_beginning(int item) {
    NodeType *NewNode = (NodeType*)malloc(sizeof(NodeType));
    if (!NewNode) {
        printf("Memory allocation failed\n");
        return;
    }
    NewNode->info = item;
    NewNode->next = first;
    first = NewNode;
    if (last == NULL) last = NewNode;
}

void insert_given_position(int item) {
    int pos, i;
    NodeType *NewNode, *temp;
    printf("Enter the position of node: ");
    scanf("%d", &pos);
    
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    NewNode = (NodeType*)malloc(sizeof(NodeType));
    if (!NewNode) {
        printf("Memory allocation failed\n");
        return;
    }
    NewNode->info = item;
    if (pos == 1) {
        NewNode->next = first;
        first = NewNode;
        if (last == NULL) last = NewNode;
        return;
    }

    temp = first;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(NewNode);
        return;
    }

    NewNode->next = temp->next;
    temp->next = NewNode;
    if (NewNode->next == NULL) last = NewNode;
}

void insert_at_end(int item) {
    NodeType *NewNode = (NodeType*)malloc(sizeof(NodeType));
    if (!NewNode) {
        printf("Memory allocation failed\n");
        return;
    }
    NewNode->info = item;
    NewNode->next = NULL;

    if (first == NULL) {
        first = last = NewNode;
    } else {
        last->next = NewNode;
        last = NewNode;
    }
}

void delete_at_beginning() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    NodeType *temp = first;
    first = first->next;
    free(temp);
    if (first == NULL) last = NULL;
}

void delete_given_position() {
    int pos, i;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || first == NULL) {
        printf("Invalid position or empty list\n");
        return;
    }

    NodeType *temp = first, *temp1;
    if (pos == 1) {
        first = first->next;
        free(temp);
        if (first == NULL) last = NULL;
        return;
    }

    for (i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }

    temp1 = temp->next;
    temp->next = temp1->next;
    if (temp->next == NULL) last = temp;
    free(temp1);
}

void delete_at_end() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    NodeType *temp = first, *hold;
    if (first->next == NULL) {
        hold = first;
        first = last = NULL;
        free(hold);
        return;
    }

    while (temp->next != last) {
        temp = temp->next;
    }

    hold = last;
    last = temp;
    last->next = NULL;
    free(hold);
}

void delete_nth_node() {
    int pos, i;
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    NodeType *temp = first, *hold;
    if (pos == 1) {
        first = first->next;
        free(temp);
        if (first == NULL) last = NULL;
        return;
    }

    for (i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }

    hold = temp->next;
    temp->next = hold->next;
    if (temp->next == NULL) last = temp;
    free(hold);
}

void info_sum() {
    int sum = 0;
    NodeType *temp = first;
    while (temp != NULL) {
        sum += temp->info;
        temp = temp->next;
    }
    printf("The sum of elements is: %d\n", sum);
}

void count_nodes() {
    int count = 0;
    NodeType *temp = first;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes: %d\n", count);
}

void display() {
    NodeType *temp = first;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}
