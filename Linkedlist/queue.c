#include<stdio.h>
#include <stdlib.h>


struct queue {
    int data;
    struct queue *link;
};


int isEmpty(struct queue *d) {
    if (NULL == d) {
        return 1;
    }
    return 0;
}


void enqueue(struct queue **head, struct queue **rear, int item) {
    struct queue *next = (struct queue *) malloc(sizeof(struct queue));
    if (next == NULL) {
        printf("Memory Underflow\n");
        return;
    }
    next->data = item;
    if (*rear == NULL) {
        next->link = *rear;
        *rear = next;
        *head = next;
        return;
    } else {
        next->link = (*rear)->link;
        (*rear)->link = next;
        *rear = (*rear)->link;
    }
}

int dequeue(struct queue **front) {
    if (isEmpty(*front)) {
        printf("Queue UnderFlow\n");
        return NULL;
    }
    int val = (*front)->data;
    struct queue *ptr = *front;
    *front = (*front)->link;
    free(ptr);
    return val;
}

void printQueue(struct queue *head) {
    printf("\nQueue:- ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->link;
    }
    printf("\n");
}

int main() {
    struct queue *front = NULL;
    struct queue *rear = NULL;
    int choose;
    int val;
    start:
    printf("Choose\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit \n: ");
    scanf("%d", &choose);
    switch (choose) {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &val);
            enqueue(&front, &rear, val);
            goto start;
        case 2:
            val = dequeue(&front);
            if (val != NULL) {
                printf("Extracted Value : %d\n", val);
            }
            goto start;
        case 3:
            printQueue(front);
            goto start;
        default:
            printf("Exiting...");
            break;
    }
    return 0;
}
