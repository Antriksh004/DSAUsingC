#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue any more elements.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = queue->rear = 0;
    else
        queue->rear++;

    queue->items[queue->rear] = value;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue any elements.\n");
        return -1;
    }

    int dequeuedValue = queue->items[queue->front];

    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;

    return dequeuedValue;
}

int main() {
    Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printf("Dequeued item: %d\n", dequeue(&myQueue));
    printf("Dequeued item: %d\n", dequeue(&myQueue));
    printf("Dequeued item: %d\n", dequeue(&myQueue));

    return 0;
}
