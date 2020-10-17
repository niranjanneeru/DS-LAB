# include <stdio.h>
# include <stdlib.h>

struct stack_char {
    int size;
    int top;
    char *arr;
};

void createChar(struct stack_char *st, int size) {
    st->size = size;
    st->arr = (char *) malloc((st->size) * sizeof(char));
    st->top = -1;
}

void printStackChar(struct stack_char *st) {
    printf("Stack  : ");
    for (int i = 0; i <= st->top; ++i) {
        printf("%c ", st->arr[i]);
    }
    printf("\n");
}

int isFullChar(struct stack_char *st) {
    if (st->top >= st->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmptyChar(struct stack_char *st) {
    if (st->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void pushChar(struct stack_char *st, char x) {
    if (isFullChar(st)) {
        printf("Stack Overflow");
    } else {
        st->arr[++st->top] = x;
    }
}

char popChar(struct stack_char *st) {
    if (isEmptyChar(st)) {
        printf("Stack Underflow");
        return '\0';
    } else {
        return st->arr[st->top--];
    }
}