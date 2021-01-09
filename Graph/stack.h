# include <stdio.h>
# include <stdlib.h>

struct stack {
    int data;
    struct stack *link;
};


int isStackEmpty(struct stack **top) {
    if (*top == NULL) {
        return 1;
    }
    return 0;
}

void push(struct stack **top, int val) {
    struct stack *next = (struct stack *) malloc(sizeof(struct stack));
    if (next == NULL) {
        printf("Memory Underflow\n");
        return;
    }
    next->data = val;
    next->link = *top;
    *top = next;
}

int pop(struct stack **top) {
    if (*top == NULL) {
        printf("LinkedList UnderFlow\n");
        return NULL;
    }
    int val = (*top)->data;
    struct stack *ptr = *top;
    *top = (*top)->link;
    free(ptr);
    return val;
}