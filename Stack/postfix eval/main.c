# include <stdio.h>
# include <string.h>
# include "postfix.h"
# include "evaluation.h"

# define MAX 100

int main() {
    char *result, *input_with_p, *result_with_h;
    char input[MAX];
    printf("Enter the Expression in Infix Form: ");
    scanf("%s", input);
    input_with_p = (char *) malloc(strlen(input) + 1);
    int i = 0;
    for (; i < strlen(input); ++i) {
        input_with_p[i] = input[i];
    }
    input_with_p[i++] = ')';
    input_with_p[i] = '\0';
    result = postfix(input_with_p);
    printf("Expression in PostFix Form: %s\n", result);
    result_with_h = add_symbol(result, '#');
    printf("Postfix Evaluated Value: %d", evaluate_postfix(result_with_h));
    free(input_with_p);
    free(result_with_h);
    free(result);
    return 0;
}