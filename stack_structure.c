# include <stdio.h>
# include <stdlib.h>
# define MAX 10

struct stack{
    int size;
    int top;
    int * arr;
};

int isFull(struct stack *st) {
    if (st->top >= MAX - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(struct stack *st) {
    if (st->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(struct stack *st ,int x) {
    if (isFull(st)) {
        printf("Stack Overflow");
    } else {
        st->arr[++st->top] = x;
    }
}

int pop(struct stack *st ) {
    if (isEmpty(st)) {
        printf("Stack Underflow");
        return -1;
    } else {
        return st->arr[st->top--];
    }
}

void printStack(struct stack *st) {
    for (int i = 0; i <= st->top; ++i) {
        printf("%d ", st->arr[i]);
    }
    printf("\n");
}
void create(struct stack *st){
    printf("Enter the size of the stack: ");
    scanf("%d",&st->size);
    st->arr = (int *)malloc((st->size)*sizeof(int));
    st->top = -1;
}
int main() {
    struct stack stack_array;
    create(&stack_array);
    push(&stack_array,12);
    push(&stack_array,10);
    printStack(&stack_array);
    pop(&stack_array);
    printStack(&stack_array);
    return 0;
}
