# include <stdio.h>
# include <stdlib.h>

struct stack {
    int data;
    struct stack *link;
};

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

void printStack(struct stack *top) {
    printf("Stack:- ");
    while (top) {
        printf("%d ", top->data);
        top = top->link;
    }
    printf("\n");
}

int main() {
    int n;
    int x;
    struct stack *top = NULL;
    start:
    printf("Enter 1 or 2 or 3 to perform an Operation others to quit: \n1.Push\n2.Pop\n3.Print\n4.Exit\n: ");
    scanf("%d", &n);
    switch (n) {
        case 1:
            printf("You chose \"PUSH\" \nEnter an element to push: ");
            scanf("%d", &x);
            push(&top, x);
            goto start;
        case 2:
            x = pop(&top);
            if (x != NULL) {
                printf("You chose \"POP\" \nThe element poped out: %d\n", x);
            }
            goto start;
        case 3:
            printStack(top);
            goto start;
        default:
            printf("Exiting ...\n");
            break;

    }
    return 0;
}