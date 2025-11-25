#include <stdio.h>
#include <stdlib.h>

// Creating Node
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;  // Stack top pointer

// PUSH operation
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed to stack\n", value);
}

// POP operation
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }

    struct Node* temp = top;
    printf("%d popped from stack\n", top->data);

    top = top->next;
    free(temp);
}

// DISPLAY stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();

                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }
}



