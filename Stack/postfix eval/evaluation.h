# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "stack_int.h"

int isOperandEval(char input) {
    if ((input >= '0' && input <= '9')) {
        return 1;
    }
    return 0;
}

int isOperatorEval(char input) {
    if (input == '+' || input == '-' || input == '*' || input == '/' || input == '^' || input == '(') {
        return 1;
    }
    return 0;
}

int isAlpha(char input) {
    if ((input >= 'A') && (input <= 'Z')) {
        return 1;
    }
    return 0;
}

int perform_calc(int x1, int x2, char item) {
    switch (item) {
        case '+':
            return x1 + x2;
        case '-':
            return x1 - x2;
        case '*':
            return x1 * x2;
        case '/':
            return x1 / x2;
        case '^':
            return pow(x1, x2);
    }
}

int evaluate_postfix(char *p) {
    struct stack_int stack_array;
    create(&stack_array, strlen(p));
    int iter = 0;
    int flag = 0;
    while (!(isEmpty(&stack_array)) || iter < (int) strlen(p)) {
        char item = p[iter];
        iter++;
        if (isOperandEval(item)) {
            if (flag) {
                flag = 0;
                push(&stack_array, '0' - item);
            } else {
                push(&stack_array, item - '0');
            }
        } else if (isAlpha(item)) {
            int val;
            printf("Enter a value for %c: ", item);
            scanf("%d", &val);
            if (flag) {
                flag = 0;
                push(&stack_array, -1 * val);
            } else {
                push(&stack_array, val);
            }
        } else if (isOperatorEval(item)) {
            int x2 = pop(&stack_array);
            int x1 = pop(&stack_array);
            push(&stack_array, perform_calc(x1, x2, item));
        } else if (item == '~') {
            flag = 1;
        } else if (item == '#') {
            return pop(&stack_array);
        } else {
            printf("%s\n", "Invalid Expression (not in postfix form)");
            return -1;
        }
    }
    printf("# Symbol Missing");
    return -1;
}

char *add_symbol(char *input, char item) {
    char *str = (char *) malloc((strlen(input) + 1) * sizeof(char));
    int i = 0;
    for (; i < strlen(input); ++i) {
        str[i] = input[i];
    }
    str[i] = item;
    return str;
}

