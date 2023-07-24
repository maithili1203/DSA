#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

Queue* copyQueue(Queue* originalQueue)
{
    Queue* newQueue = createQueue();
    Node* current = originalQueue->front;
    while (current != NULL)
    {
        enqueue(newQueue, current->data);
        current = current->next;
    }
    return newQueue;
}

void displayQueue(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    Node* current = queue->front;
    printf("Queue:\n");
    while (current != NULL)
    {
        printf("Data: %d\tMemory Location: %p\n", current->data, (void*)current);
        current = current->next;
    }
    printf("\n");
}


int main()
{
    Queue* originalQueue = createQueue();

    int choice, data;
    printf("Enter queue elements (enter -1 to stop):\n");
    while (1)
    {
        printf("Enter element: ");
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        enqueue(originalQueue, data);
    }

    printf("Original ");
    displayQueue(originalQueue);

    Queue* copiedQueue = copyQueue(originalQueue);

    printf("Copied ");
    displayQueue(copiedQueue);

    return 0;
}
