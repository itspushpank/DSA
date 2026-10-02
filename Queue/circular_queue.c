#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

CircularQueue* createCircularQueue() {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(CircularQueue* q) {
    return q->front == -1;
}

int isFull(CircularQueue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Circular Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Circular Queue is empty\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}

int peek(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Circular Queue is empty\n");
        return -1;
    }
    return q->items[q->front];
}

void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Circular Queue: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue* q = createCircularQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    display(q);
    
    printf("Dequeued: %d\n", dequeue(q));
    display(q);
    
    printf("Front element: %d\n", peek(q));
    display(q);
    
    enqueue(q, 50);
    enqueue(q, 60);
    display(q);
    
    free(q);
    return 0;
}