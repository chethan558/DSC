#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a linked list
void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes should be greater than 0.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("\nLinked List created successfully!\n");
}

// Display the linked list
void display() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Sort the linked list (Bubble Sort)
void sortList() {
    struct Node *i, *j;
    int temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("Linked List sorted.\n");
}

// Reverse the linked list
void reverseList() {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    printf("Linked List reversed.\n");
}

// Concatenate two linked lists
struct Node* concatenate(struct Node *h1, struct Node *h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    struct Node *temp = h1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = h2;
    return h1;
}

int main() {
    int n, choice;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Create Linked List\n");
        printf("2. Display List\n");
        printf("3. Sort List\n");
        printf("4. Reverse List\n");
        printf("5. Concatenate Two Lists\n");
        printf("6. Exit\n");
        printf("----------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            createList(n);
            break;

        case 2:
            display();
            break;

        case 3:
            sortList();
            break;

        case 4:
            reverseList();
            break;

        case 5: {
            struct Node *head2 = NULL;
            int m;
            printf("Enter number of nodes for second list: ");
            scanf("%d", &m);

            // Create second list
            struct Node *tempHead = head;
            head = NULL;
            createList(m);

            head2 = head;
            head = tempHead;

            head = concatenate(head, head2);

            printf("Lists concatenated successfully.\n");
            break;
        }

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
