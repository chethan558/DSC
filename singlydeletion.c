#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int prev;
    struct node *next;
};

struct node *head = NULL;



void createList(int n) {
    struct node *newNode, *temp = NULL;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes should be greater than 0\n");
        return;
    }


    if (head != NULL) {

        printf("Warning: Overwriting existing list.\n");
        head = NULL;
    }

    for (i = 1; i <= n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    printf("\nLinked list created successfully\n");
}

void displayList() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("\nLinked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteatbeginning(){
    struct node*temp;
    if( head== NULL){
        printf("list is empty");
        return;
    }
    temp=head;
    head=head->next;
    temp->data;
    free (temp);
}

void deleteatend()
{   
    struct node*temp,*prev;
    if(head==NULL){
        printf("list is empty");
        return;
    }
    if(head->next==NULL){
        printf("deleted element:%d\n",head->data);
        head=NULL;
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    printf("deleted element:%d\n",temp->data);
    prev->next=NULL;
    free(temp);
    
}
void deleteatpos(int pos) {
    if (head == NULL) {
        printf("list is empty\n");
        return;
    }

    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }

    struct node *temp = head, *prev = NULL;
    int count = 1;

    if (pos == 1) {
        head = head->next;
        printf("deleted element: %d\n", temp->data);
        free(temp);
        return;
    }
    while (temp != NULL && count < pos) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    prev->next = temp->next;
    printf("deleted element: %d\n", temp->data);
    free(temp);
}





int main() {
    int choice, n, data, pos;

    while (1) {
        printf("\n---- Singly Linked List Operations ----\n");
        printf("1. Create linked list\n");
        printf("2. delete at beginning\n ");
        printf("3. delete at end\n");
        printf("4. delete at pos\n");
        printf("5. Display list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {

             while (getchar() != '\n');
             printf("Invalid input. Please enter a number.\n");
             continue;
        }

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                deleteatbeginning();
                break;
            case 3:
                deleteatend();
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteatpos(pos);
                break;


            case 5:
                displayList();
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
