# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "stack_char.h"

int isOperand(char input) {
    if ((input >= 'A' && input <= 'Z') || (input >= '0' && input <= '9')) {
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

void display(char *p, int size) {
    printf("Output : ");
    for (int i = 0; i < size; i++) {
        printf("%c ", *(p + i));
    }
    printf("\n");
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

char *postfix(char *p) {
    struct stack_char *st;
    createChar(st, strlen(p));
    pushChar(st, '(');
    char *result = (char *) malloc(strlen(p) * sizeof(char));
    int k = 0;
    int i = 0;
    while (!(isEmptyChar(st)) && i < (int) strlen(p)) {
        char item = p[i];
        i++;
        char x = popChar(st);
        if (isOperand(item)) {
            result[k++] = item;
            pushChar(st, x);
        } else if (item == ')') {
            while (x != '(') {
                result[k++] = x;
                x = popChar(st);
            }
        } else if (isOperator(item)) {
            if (isp(x) >= icp(item)) {
                while (isp(x) >= icp(item)) {
                    result[k++] = x;
                    x = popChar(st);
                }
                pushChar(st, x);
                pushChar(st, item);
            } else if (isp(x) < icp(item)) {
                pushChar(st, x);
                pushChar(st, item);
            }
        } else {
            printf("%s\n", "Invalid Expression");
            break;
        }
    }
    free(st->arr);
    return result;
}
