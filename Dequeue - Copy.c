#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Structure for the deque
typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty deque
Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

// Function to check if the deque is empty
int isEmpty(Deque* deque) {
    return (deque->front == NULL);
}

// Function to add an element to the front of the deque
void addFront(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

// Function to add an element to the rear of the deque
void addRear(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// Function to delete an element from the front of the deque
int deleteFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }
    int data = deque->front->data;
    Node* temp = deque->front;
    deque->front = deque->front->next;
    if (deque->front != NULL) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to delete an element from the rear of the deque
int deleteRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }
    int data = deque->rear->data;
    Node* temp = deque->rear;
    deque->rear = deque->rear->prev;
    if (deque->rear != NULL) {
        deque->rear->next = NULL;
    } else {
        deque->front = NULL;
    }
    free(temp);
    return data;
}

// Function to display the contents of the deque
void displayDeque(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    Node* current = deque->front;
    printf("Deque: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create an empty deque
    Deque* deque = createDeque();

    int choice, data;

    while (1) {
        printf("1. Add element to front\n");
        printf("2. Add element to rear\n");
        printf("3. Delete element from front\n");
        printf("4. Delete element from rear\n");
        printf("5. Display deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add: ");
                scanf("%d", &data);
                addFront(deque, data);
                printf("Element added to the front.\n");
                break;
            case 2:
                printf("Enter data to add: ");
                scanf("%d", &data);
                addRear(deque, data);
                printf("Element added to the rear.\n");
                break;
            case 3:
                data = deleteFront(deque);
                if (data != -1) {
                    printf("Deleted element from front: %d\n", data);
                }
                break;
            case 4:
                data = deleteRear(deque);
                if (data != -1) {
                    printf("Deleted element from rear: %d\n", data);
                }
                break;
            case 5:
                displayDeque(deque);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}
