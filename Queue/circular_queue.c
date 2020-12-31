// Aim :- Implement -  Circular Queue Data Structure using Array

// Input:- enqueue,dequeue operations
// Output:- circular queue after operations
// Data Structure used :- Circular Queue (Array in FIFO) pointed by FRONT and REAR

// Start
// 1. Take a array of size N QUEUE[N]
// 2. Initialize FRONT = -1 and REAR = -1
// 3. enqueue(ITEM)
// 4.     if(FRONT==(REAR+1)%N)
// 5.          print "QUEUE OVERFLOW"
// 6.
// 7.     else if(FRONT == -1 && REAR == -1)
// 8.          FRONT=REAR=0
// 9.          QUEUE[REAR] = ITEM
// 10.    else
// 11.         REAR = (REAR + 1) %N
// 12.         QUEUE[REAR] = ITEM
// 13. dequeue()
// 14.     if(FRONT == -1)
// 15.          print "QUEUE UNDERFLOW"
// 16.     ITEM = QUEUE[FRONT]
// 17.     else if(FRONT == REAR)
// 18.          FRONT=REAR=-1
// 19.     else
// 20.          FRONT = (FRONT + 1)%N
// 21.     return ITEM
// Stop


// Time Complexity
// enqueue(ITEM)
// Worst Case :- O(1)

// Space Complexity
// Worst Case :- O(1)


// dequeue()
// Worst Case :- O(1)

// Space Complexity
// Worst Case :- O(1)

#include <stdio.h>
#include <stdlib.h>

struct queue {
    int front;
    int rear;
    int max_size;
    int *queue;
};

int isFull(struct queue *d) {
    if (d->front == (d->rear + 1) % d->max_size) {
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
        d->rear = (d->rear + 1) % d->max_size;
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
        d->front = (d->front + 1) % d->max_size;
    }
    return item;
}

void printqueue(struct queue *d) {
    printf("\n");
    printf("Front :- %d Rear :- %d\n", d->front, d->rear);
    if (isEmpty(d)) {
        printf("%s\n", "Empty Queue");
        return;
    }
    int i = d->front;
    while (i != d->rear) {
        printf("%d ", *(d->queue + i));
        i = (i + 1) % d->max_size;
    }
    printf("%d\n", *(d->queue + d->rear));
}


int main() {
    struct queue circular_array;
    create_queue(&circular_array);
    int choose;
    int val;
    start:
    printf("Choose\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit \n: ");
    scanf("%d", &choose);
    switch (choose) {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &val);
            enqueue(&circular_array, val);
            goto start;
        case 2:
            val = dequeue(&circular_array);
            if (val != NULL) {
                printf("Extracted Value : %d\n", val);
            }
            goto start;
        case 3:
            printqueue(&circular_array);
            goto start;
        default:
            printf("Exiting...");
            break;
    }
    return 0;
}