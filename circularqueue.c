#include <stdio.h>
#define n 5

int queue[n];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if ((rear + 1) % n == front) {
        printf("Queue Overflow\n");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    }
    else {
        rear = (rear + 1) % n;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else if (front == rear) {
        printf("Deleted element: %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Deleted element: %d\n", queue[front]);
        front = (front + 1) % n;
    }
}

void display() {
    int i;
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements: ");
        i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", queue[rear]);
    }
}

void main()
{
    int ch;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter a elements to insert:");
            int x;
            scanf("%d",&x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        default:
            printf("\n invalid choice\n");
            break;
        }


    }
    return 0;
}

