//Queue using array

#include<stdio.h>
#include<stdlib.h>

#define MAX 10
int *q, REAR = -1, FRONT = -1, el;

void DISPLAY(int *q) {
    if (-1 == FRONT) {
        printf("\n The Queue is Empty");

    } else {
        printf("\n The Queue is: ");
        for (int i = FRONT; i <= REAR; i++) {
            printf("\n %d", q[i]);
        }
    }

}

void ENQUEUE(int *q,int el) {
    if (REAR == MAX - 1) {
        printf("\n The Queue is Full");
    } else {
        if ((REAR == -1) && (FRONT == -1)) {
            FRONT++;
            REAR++;
            q[REAR] = el;

        } else {
            REAR++;
            q[REAR] = el;
        }
        printf("\n The element has entered the queue");
    }
}

int DEQUEUE(int *q, int *FRONT, int *REAR) {
    if (*FRONT == *REAR) {
        printf("\n The Queue is empty");
        return -1;
    } else {
        int rem = q[*REAR];
        *FRONT = *FRONT + 1;
        if (*FRONT == *REAR) {
            *FRONT = -1;
            *REAR = -1;
        }
        return rem;
    }
}


void main() {
    int c, rem;
    q = (int *) malloc(MAX * sizeof(int));
    while (1) {
        printf("\n Enter the operation to be performed on the QUEUE");
        printf("\n 1.ENQUEUE \n 2.DEQUEUE \n 3.DISPLAY \n 4.EXIT \n");
        scanf("%d", &c);
        if (c == 4) {
            break;
        }
        switch (c) {
            case 1: {
                printf("\n Enter the element to be inserted into the Queue: ");
                scanf("%d", &el);
                ENQUEUE(q, el);
                break;
            }
            case 2: {
                printf("\n Removing element in the Queue: ");
                rem = DEQUEUE(q, &FRONT, &REAR);
                if (rem != -1) {
                    printf("\n The removed element is: %d", rem);
                    break;
                }

            }
            case 3: {
                DISPLAY(q);
                break;
            }
            default: {
                printf("\n Invalid Value");
                break;
            }

        }

    }
}
