#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;      // For stack
struct Node *front = NULL;    // For queue
struct Node *rear = NULL;     // For queue

// ---------------------------------------------------------
// Function to PUSH into Stack (Insert at beginning)
// ---------------------------------------------------------
void push(int value) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;   // link new node
    top = newNode;         // move top to new node

    printf("%d pushed into stack.\n", value);
}

// ---------------------------------------------------------
// Function to POP from Stack (Delete from beginning)
// ---------------------------------------------------------
void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    temp = top;
    printf("%d popped from stack.\n", top->data);
    top = top->next;       // move top
    free(temp);
}

// ---------------------------------------------------------
// Function to display Stack
// ---------------------------------------------------------
void displayStack() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ---------------------------------------------------------
// Function to ENQUEUE (Insert at end)
// ---------------------------------------------------------
void enqueue(int value) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        front = newNode;     // first node
        rear = newNode;
    } else {
        rear->next = newNode;  // link new node
        rear = newNode;        // move rear
    }

    printf("%d enqueued into queue.\n", value);
}

// ---------------------------------------------------------
// Function to DEQUEUE (Delete from beginning)
// ---------------------------------------------------------
void dequeue() {
    struct Node *temp;

    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    temp = front;
    printf("%d dequeued from queue.\n", front->data);

    front = front->next;
    if (front == NULL)
        rear = NULL;

    free(temp);
}

// ---------------------------------------------------------
// Function to display Queue
// ---------------------------------------------------------
void displayQueue() {
    struct Node *temp;

    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ---------------------------------------------------------
// MAIN PROGRAM – MENU DRIVEN
// ---------------------------------------------------------
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Linked List Stack & Queue ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 5:
                dequeue();
                break;

            case 6:
                displayQueue();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
