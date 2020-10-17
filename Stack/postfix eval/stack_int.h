# include <stdio.h>
# include <stdlib.h>

struct stack_int {
    int size;
    int top;
    int *arr;
};

int isFull(struct stack_int *st) {
    if (st->top >= st->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(struct stack_int *st) {
    if (st->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(struct stack_int *st, int x) {
    if (isFull(st)) {
        printf("Stack Overflow");
    } else {
        st->arr[++st->top] = x;
    }
}

int pop(struct stack_int *st) {
    if (isEmpty(st)) {
        printf("Stack Underflow");
        return '\0';
    } else {
        return st->arr[st->top--];
    }
}


void printStack(struct stack_int *st) {
    printf("Stack  : ");
    for (int i = 0; i <= st->top; ++i) {
        printf("%d ", st->arr[i]);
    }
    printf("\n");
}

void create(struct stack_int *st, int size) {
    st->size = size;
    st->arr = (int *) malloc((st->size) * sizeof(int));
    st->top = -1;
}