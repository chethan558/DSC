#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define n 5
int queue[n];
int front=-1;
int rear=-1;

void enqueue(int x)
{
    if(rear==n-1)
    {
        printf("queue overflow");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1){
        printf("queue is empty");
    }
    else if (front==rear)
    {
        front=rear=-1;
    }
    else{
        printf("Deleted elements",queue[front]);
        front++;
    }
}
void display()
{ int i;
    if (front==-1 && rear==-1)
    {
        printf("queue is empty");
    }
    else{
        for (i=front; i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
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
