// Aim :- Implement Priority Queue Data Structure using Array

// Input:- enqueue,dequeueHighestPriority
// Output:- deque after operations
// Data Structure used :- Deque (Array in FIFO) pointed by FRONT and REAR
//
// Start
// 1. Take a array of size N QUEUE[N]
// 2. Initialize FRONT = -1 and REAR = -1
//       ITEM has data and priority
// 3. enqueue(ITEM)
// 4.     if(N-1==REAR)
// 5.          print "QUEUE OVERFLOW"
// 6.
// 7.     else if(FRONT == -1 && REAR == -1)
// 8.          FRONT=REAR=0
// 9.          QUEUE[REAR] = ITEM
// 10.    else
// 11.         REAR = REAR + 1
// 12.         QUEUE[REAR] = ITEM
// 13. dequeueHighestPriority()
// 14.     if(FRONT == -1)
// 15.          print "QUEUE UNDERFLOW"
// 16.
// 16.     ITEM = QUEUE[FRONT]
// 17.     else if(FRONT == REAR)
// 18.          FRONT=REAR=-1
// 19.     else
// 20.          FRONT = FRONT + 1
// 21.     return ITEM
// Stop


// Time Complexity
// enqueue(ITEM)
// Worst Case :- O(1)

// Space Complexity
// Worst Case :- O(1)


// dequeueHighestPriority()
// Worst Case :- O(n)

// Space Complexity
// Worst Case :- O(1)

#include <stdio.h>
#include <stdlib.h>

struct pq_element {
    int data;
    int priority;
};

struct pqueue {
    int front;
    int rear;
    int max_size;
    struct pq_element *arr;
};

struct pqueue *create() {
    struct pqueue *p = (struct pqueue *) malloc(sizeof(struct pqueue));
    printf("Enter the max size of the queue: ");
    scanf("%d", &p->max_size);
    p->front = p->rear = -1;
    p->arr = (struct pq_element *) malloc(p->max_size * sizeof(struct pq_element));
    return p;
}

int isFull(struct pqueue *p) {
    if (p->rear + 1 == p->max_size) {
        return 1;
    }
    return 0;
}

int isEmpty(struct pqueue *p) {
    if (p->front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(struct pqueue *p, struct pq_element *item) {
    if (isFull(p)) {
        printf("Queue Overflow\n");
        return;
    } else if (isEmpty(p)) {
        p->front = p->rear = 0;
    } else {
        p->rear++;
    }
    p->arr[p->rear] = *item;
}

int *dequeueHighestPriority(struct pqueue *p) {
    if (isEmpty(p)) {
        printf("Queue Underflow\n");
        return NULL;
    }

    for (int i = p->front; i < p->rear + 1; ++i) {
        int j = i - 1;
        struct pq_element temp = p->arr[i];
        while (j >= 0 && temp.priority < p->arr[j].priority) {
            p->arr[j + 1] = p->arr[j];
            j--;
        }
        p->arr[j + 1] = temp;
    }
    int * val;
    val =  &(p->arr[p->front].data);
    if(p->front == p->rear){
        p->front = p->rear = -1;
    } else{
        p->front++;
    }
    return val;

}

void display(struct pqueue *p) {
    if (isEmpty(p)) {
        printf("\nEmpty Queue\n");
        return;
    }
    printf("(Data,Priority)\n");
    for (int i = p->front; i < p->rear + 1; ++i) {
        if (p->arr[i].priority != 0) {
            printf("(%d\t,%d)\n", p->arr[i].data, p->arr[i].priority);
        }
    }
}

int main() {
    int choose;
    struct pqueue *queue = create();
    struct pq_element a;
    int *val;
    start:
    printf("Choose an Operation\n1.Enqueue\n2.DequeueHighestPriority\n3.Display\n4. Exit\n: ");
    scanf("%d", &choose);
    switch (choose) {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &a.data);
            printf("Enter the priority: ");
            scanf("%d", &a.priority);
            enqueue(queue, &a);
            goto start;
        case 2:
            val = dequeueHighestPriority(queue);
            if (val != NULL) {
                printf("Extracted Element: %d\n", *val);
                free(val);
            }
            goto start;
        case 3:
            display(queue);
            goto start;
        case 4:
            free(queue->arr);
            free(queue);
            printf("Exiting....");
            break;

    }
}