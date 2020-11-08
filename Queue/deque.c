// Aim :- Implement Circular Deque Data Structure using Array

// Input:- enqueue,dequeue operations through front and rear
// Output:- deque after operations
// Data Structure used :- Deque (Array in FIFO) pointed by FRONT and REAR

//Start
//1. Take a array of size N QUEUE[N]
//2. Initialize FRONT = -1 and REAR = -1
//3. ENQUEUEREAR(ITEM)
//4.     if(FRONT == (REAR+1)%N)
//5.          print "QUEUE OVERFLOW"
//6.
//7.     else if(FRONT == -1 && REAR == -1)
//8.          FRONT=REAR=0
//9.          QUEUE[REAR] = ITEM
//10.    else
//11.         REAR = (REAR + 1)%N
//12.         QUEUE[REAR] = ITEM
//13. ENQUEUEFRONT(ITEM)
//14.     if(FRONT == (REAR+1)%N)
//15.          print "QUEUE OVERFLOW"
//16.
//17.     else if(FRONT == -1 && REAR == -1)
//18.          FRONT=REAR=0
//19.      Else if(FRONT == 0)
//20.            FRONT = N-1
//21.     Else
//22.             FRONT = FRONT - 1
//23.     QUEUE[FRONT] = ITEM
//24. DEQUEUEFRONT()
//25.     if(FRONT == -1)
//25.          print "QUEUE UNDERFLOW"
//26.      VAL = QUEUE[FRONT]
//26.     if(FRONT == REAR)
//27.            FRONT = REAR = -1
//28.    else
//29.            FRONT = (FRONT + 1)%N
//30.       return VAL
//31.  DEQUEUEFRONT()
//32.     if(FRONT == -1)
//33.          print "QUEUE UNDERFLOW"
//34.      VAL = QUEUE[REAR]
//35.      if(FRONT==REAR)
//36.              FRONT = REAR = -1
//37.    Else if REAR == 0
//38.                REAR = N - 1
//39.    Else
//40.                REAR = REAR - 1
//41.     Return VAL
//
//Stop


// Time Complexity
// enqueueFront(ITEM) and enqueueRear(ITEM)
// Worst Case :- O(1)
//
// Space Complexity
// Worst Case :- O(1)
//
//
// dequeueFront() and dequeueRear()
// Worst Case :- O(1)
//
// Space Complexity
// Worst Case :- O(1)


#include <stdio.h>
#include <stdlib.h>

#define loop(i, n) for (int i = 0; i < n; i++)

struct deque {
    int front;
    int rear; 
    int max_size;
    int *queue;
};

int isFull(struct deque *d) {
    if (d->front == (d->rear + 1) % d->max_size) {
        return 1;
    }
    return 0;
}

int isEmpty(struct deque *d) {
    if (d->front == -1) {
        return 1;
    }
    return 0;
}

void create_deque(struct deque *d) {
    printf("Enter the max size of the queue: ");
    scanf("%d", &d->max_size);
    d->front = d->rear = -1;
    d->queue = (int *) malloc(d->max_size * sizeof(int));
}

void enqueuerear(struct deque *d, int item) {
    if (isFull(d)) {
        printf("%s\n", "Deque Overflow");
        return;
    }
    if (d->front == -1 && d->rear == -1) {
        d->front = d->rear = 0;
        d->queue[d->rear] = item;
    } else {
        d->rear = (d->rear + 1) % d->max_size;
        d->queue[d->rear] = item;
    }
}

void enqueuefront(struct deque *d, int item) {
    if (isFull(d)) {
        printf("%s\n", "Deque Overflow");
        return;
    }
    if (d->front == -1 && d->rear == -1) {
        d->front = d->rear = 0;
        d->queue[d->front] = item;
    } else if (d->front == 0) {
        d->front = d->max_size - 1;
        d->queue[d->front] = item;
    } else {
        d->front--;
        d->queue[d->front] = item;
    }
}

void printqueue(struct deque *d) {
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

int dequefront(struct deque *d) {
    if (isEmpty(d)) {
        printf("%s\n", "Deque Underflow");
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

int dequerear(struct deque *d) {
    if (isEmpty(d)) {
        printf("%s\n", "Deque Underflow");
        return NULL;
    }
    int item = d->queue[d->rear];
    if (d->front == d->rear) {
        d->front = d->rear = -1;
    } else if (d->rear == 0) {
        d->rear = d->max_size - 1;
    } else {
        d->rear--;
    }
    return item;
}


int main() {
    struct deque deque_array;
    int choose;
    int val;
    create_deque(&deque_array);
    start:
    printf("Choose an Operation\n1.ENQUEUEFRONT\n2.ENQUEUEREAR\n3.DEQUEUEFRONT\n4.DEQUEUEREAR\n5.DISPLAY\n: ");
    scanf("%d", &choose);
    switch (choose) {
        case 1:
            printf("Enter the value to enqueuefront: ");
            scanf("%d", &val);
            enqueuefront(&deque_array, val);
            goto start;
        case 2:
            printf("Enter the value to enqueuerear: ");
            scanf("%d", &val);
            enqueuerear(&deque_array, val);
            goto start;
        case 3:
            val = dequefront(&deque_array);
            if (val != NULL) {
                printf("Extracted Value from the front : %d\n", val);
            }
            goto start;
        case 4:
            val = dequerear(&deque_array);
            if (val != NULL) {
                printf("Extracted Value from the rear : %d\n", val);
            }
            goto start;
        case 5:
            printqueue(&deque_array);
            goto start;
        default:
            printf("Exiting...");
            break;
    }
    return 0;
}
