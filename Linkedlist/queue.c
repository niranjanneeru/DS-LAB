// Aim :- 	Implement a Queue using LinkedList with the operations:
// .Enqueuing elements to the Queue.
// .Dequeue element from the Queue
// .Display the contents of the Queue after each operation.

// Implement Queue Functions

// Input :- Menu driven operations
// Output:- Queue After Operations
// Data Structure Used:- Queue using LinkedList pointed by a FRONT and REAR

// Start
// 1. Set up a node for LinkedList and SET FRONT = NULL and REAR = NULL

// 2. Function Enqueue(X)
// 3. newNode = GetNode(node)
// 4. if newNode is NULL
// 5.   print OverFlow
// 6. newNode->data = X
// 7. if REAR == NULL
// 8.   newNode->link = REAR
// 9.   REAR = FRONT = newNode
// 10.else
// 11.  newNode->link = REAR->link
// 12.  REAR->link = newNode
// 13.  REAR = REAR->link

// 14. Function Dequeue()
// 15. Check the Queue is empty (FRONT == NULL)
// 16. X = FRONT->data
// 17. ptr=FRONT
// 18. FRONT = FRONT->link
// 19. ReturnNode(ptr)
// 20. return X
//
//
// 21. Call the Functions according to the menu
// 22. PRINT Queue
// Stop

// Time Complexity
// DEQUEUE
// Worst Case :- O(1)

// Space Complexity
// O(1)

// ENQUEUE
// Worst Case :- O(1)

// Space Complexity
// O(1)

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
