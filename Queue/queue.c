//Queue using array

#include<stdio.h>
#include <stdlib.h>

#define loop(j, n) for (int i = j; i < n; i++)

struct queue {
    int front;
    int rear;
    int max_size;
    int *queue;
};

int isFull(struct queue *d) {
    if (d->max_size - 1 == d->rear) {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *d) {
    if (-1 == d->front) {
        return 1;
    }
    return 0;
}

void create_queue(struct queue *d) {
    printf("Enter the max size of the queue: ");
    scanf("%d", &d->max_size);
    d->front = d->rear = -1;
    d->queue = (int *) malloc(d->max_size * sizeof(int));
}

void enqueue(struct queue *d, int item) {
    if (isFull(d)) {
        printf("Queue Overflow\n");
        return;
    }
    if (d->front == -1 && d->rear == -1) {
        d->front = d->rear = 0;
    } else {
        d->rear++;
    }
    d->queue[d->rear] = item;
}

int dequeue(struct queue *d) {

    if (isEmpty(d)) {
        printf("Queue UnderFlow\n");
        return NULL;
    }
    int item = d->queue[d->front];
    if (d->front == d->rear) {
        d->front = d->rear = -1;
    } else {
        d->front++;
    }
    return item;
}

void printqueue(struct queue *d) {
    printf("\n");
    if (d->front == -1 && d->rear == -1) {
        printf("Empty Queue\n");
        return;
    }
    printf("Front :- %d Rear :- %d\n", d->front, d->rear);
    printf("||:- ");
    loop(d->front, d->rear + 1)printf("%d ", *(d->queue + i));
    printf("\n");
}

int main() {
    struct queue que_array;
    create_queue(&que_array);
    enqueue(&que_array, val);
    val = dequeue(&que_array);
    int choose;
    int val;
    start:
    printf("Choose\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit \n: ");
    scanf("%d", &choose);
    switch (choose) {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &val);
            enqueue(&que_array, val);
            goto start;
        case 2:
            val = dequeue(&que_array);
            if (val != NULL) {
                printf("Extracted Value : %d\n", val);
            }
            goto start;
        case 3:
            printqueue(&que_array);
            goto start;
        default:
            printf("Exiting...");
            break;
    }
    return 0;
}
