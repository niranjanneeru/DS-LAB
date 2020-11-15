# include <stdio.h>
# include <string.h>
# include "postfix.h"
# include "evaluation.h"

# define MAX 100

int main() {
    char *result, *result_with_h;
    char input[MAX];
    printf("Enter the Expression in Infix Form: ");
    fgets(input, MAX, stdin);
    char *pos;
    if ((pos = strchr(input, '\n')) != NULL)
        *pos = ')';
//    input_with_p = (char *) malloc(strlen(input) + 1);
//    int i = 0;
//    for (; i < strlen(input); ++i) {
//        input_with_p[i] = input[i];
//    }
//    input_with_p[i++] = ')';
//    input_with_p[i] = '\0';
    result = postfix(input);
    printf("Expression in PostFix Form: %s\n", result);
    result_with_h = add_symbol(result, '#');
    printf("Postfix Evaluated Value: %d", evaluate_postfix(result_with_h));
    free(result_with_h);
    free(result);
    return 0;
}