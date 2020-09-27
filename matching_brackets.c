# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX 100

struct stack {
    int size;
    int top;
    char *arr;
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

void push(struct stack *st, int x) {
    if (isFull(st)) {
        printf("Stack Overflow");
    } else {
        st->arr[++st->top] = x;
    }
}

int pop(struct stack *st) {
    if (isEmpty(st)) {
        printf("Stack Underflow");
        return -1;
    } else {
        return st->arr[st->top--];
    }
}

void printStack(struct stack *st) {
    for (int i = 0; i <= st->top; ++i) {
        printf("%c ", st->arr[i]);
    }
    printf("\n");
}

void create(struct stack *st) {
    // printf("Enter the size of the stack: ");
    // scanf("%d",&st->size);
    st->size = MAX;
    st->arr = (char *) malloc((st->size) * sizeof(char));
    st->top = -1;
}

int bracket_verifier(char *string, struct stack *st) {
    for (size_t i = 0; i < strlen(string); i++) {
        if (string[i] == '(' || string[i] == '[' || string[i] == '{') {
            push(st, string[i]);
        } else if (string[i] == ')') {
            if (pop(st) != '(') {
                return 0;
            }
        } else if (string[i] == ']') {
            if (pop(st) != '[') {
                return 0;
            }
        } else if (string[i] == '}') {
            if (pop(st) != '{') {
                return 0;
            }
        }
    }
    if (isEmpty(st)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    struct stack stack_array;
    create(&stack_array);
    char string[MAX]; // Accepting the string from the input side to check whether it's a valid expression or not
    printf("Enter the String: ");
    fgets(string, MAX, stdin);
    if (bracket_verifier(string, &stack_array)) {
        printf("Valid Expression");
    } else {
        printf("Not valid Expression");
    }
    return 0;
}
