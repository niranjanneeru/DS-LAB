//Queue using array

#include<stdio.h>
#include <stdlib.h>

#define loop(j, n) for (int i = j; i < n; i++)

typedef struct {
    int front;
    int rear;
    int max_size;
    node **queue;
} queue;

int isFull(queue * d) {
    if (d->max_size - 1 == d->rear) {
        return 1;
    }
    return 0;
}

int isEmpty(queue * d) {
    if (-1 == d->front) {
        return 1;
    }
    return 0;
}

void create_queue(queue * d, int
size) {
d->
max_size = size;
d->
front = d->rear = -1;
d->
queue = (node **) malloc(d->max_size * sizeof(node *));
}

void enqueue(queue * d, node * item) {
    if (isFull(d)) {
        printf("Queue Overflow\n");
        return;
    }
    if (d->front == -1 && d->rear == -1) {
        d->front = d->rear = 0;
    } else {
        d->rear++;
    }
    d->queue[d->rear] =
            item;
}

node *dequeue(queue * d) {

    if (isEmpty(d)) {
        printf("Queue UnderFlow\n");
        return NULL;
    }
    node *item = d->queue[d->front];
    if (d->front == d->rear) {
        d->front = d->rear = -1;
    } else {
        d->front++;
    }
    return item;
}

void printQueue(queue * d) {
    printf("\n");
    if (d->front == -1 && d->rear == -1) {
        printf("Empty Queue\n");
        return;
    }
    printf("Front :- %d Rear :- %d\n", d->front, d->rear);
    printf("||:- ");
    loop(d->front, d->rear + 1)printf("%d ", (d->queue)[i]->data);
    printf("\n");
}