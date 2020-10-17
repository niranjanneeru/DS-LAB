// Aim :- PostFix Evaluation
// Input: PostFix Expression with # at the end
// Output : Result evaluates
// Data Structure :- Stack (Array in LIFO) with top pointed in the top

// Start
// 1.Initialize STACK, TOP = -1
// 2.while(TOP>-1)do
// 3. item = E.Readsymbol()
// 4. Case item = operand
//     a. PUSH(item)
// 5. Case item = operator
//          x2 = POP()
//          x1 = POP()
//          x = x1(item)x2
//          PUSH(x)
// 6. Case item = #
//          x = POP()
//          Output(x)
// 7. Otherwise
// 8.    print("Invalid")
// Stop

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *st) {
    if (st->top >= st->size - 1) {
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

void push(struct stack *st, char x) {
    if (isFull(st)) {
        printf("Stack Overflow");
    } else {
        st->arr[++st->top] = x;
    }
}

char pop(struct stack *st) {
    if (isEmpty(st)) {
        printf("Stack Underflow");
        return '\0';
    } else {
        return st->arr[st->top--];
    }
}

void display(char *p, int size) {
    printf("Output : ");
    for (int i = 0; i < size; i++) {
        printf("%c ", *(p + i));
    }
    printf("\n");
}

void printStack(struct stack *st) {
    printf("Stack  : ");
    for (int i = 0; i <= st->top; ++i) {
        printf("%c ", st->arr[i]);
    }
    printf("\n");
}

void create(struct stack *st) {
    st->arr = (char *) malloc((st->size) * sizeof(char));
    st->top = -1;
}

int isOperand(char input) {
//    if( (input>='A' && input <= 'Z') || (input>='0' && input <= '9') ){
    if (input >= '0' && input <= '9') {
        return 1;
    }
    return 0;
}

int isOperator(char input) {
    if (input == '+' || input == '-' || input == '*' || input == '/' || input == '^' || input == '(') {
        return 1;
    }
    return 0;
}

int isp(char x) {
    switch (x) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '^':
            return 5;
        case '(':
            return 0;
    }
    return -1;
}

int icp(char x) {
    switch (x) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 3;
        case '^':
            return 6;
        case '(':
            return 9;
        case ')':
            return 0;
    }
    return -1;
}

char *postfix(struct stack *st, char *p) {
    char *result = (char *) malloc(strlen(p) * sizeof(char));
    int k = 0;
    int i = 0;
    while (!(isEmpty(st)) && i < (int) strlen(p)) {
//        display(result,k);      // Steps
//        printStack(st);
        char item = p[i];
        i++;
        char x = pop(st);
        if (isOperand(item)) {
            push(st, x);
            result[k++] = item;
        } else if (item == ')') {
            while (x != '(') {
                result[k++] = x;
                x = pop(st);
            }
        } else if (isOperator(item)) {
            if (isp(x) >= icp(item)) {
                while (isp(x) >= icp(item)) {
                    result[k++] = x;
                    x = pop(st);
                }
                push(st, x);
                push(st, item);
            } else if (isp(x) < icp(item)) {
                push(st, x);
                push(st, item);
            }
        } else {
            printf("%s\n", "Invalid Expression");
            break;
        }
    }
    return result;
}

void dealloc(char *c) {
    free(c);
}

