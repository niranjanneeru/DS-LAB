// Aim :- Infix to PostFix
// Input: Proper(Balanced Without any parenthesis Issue) Arithmetic Expression as String (Infix Notation) and STACK with '(' in top position
// Table defined with In Stack Priority and In Coming Priority
// Output : Arithmetic Expression as String (PostFix Notation)
// Data Structure :- Stack (Array in LIFO) with top pointed in the top

// Start
// 1.Initialize TOP = -1,PUSH('(')
// 2.while(TOP>-1)do
// 3. item = E.Readsymbol()
// 4. x = POP()
// 5. Case item = operand
//     a. PUSH(x)
//     b. output(item)
// 6. Case item = ')'
//      a. while x!= '('
//      b.    output(x)
//      c.    x = POP()
// 7. Case item = operator
// 8. Case ISP(x) >= ICP(item)
// 9.       while(ISP(x) >= ICP(item))do
// 10.           output(x)
// 11.           x = POP()
// 12.      endwhile
// 13.      PUSH(x)
// 14.      PUSH(item)
// 15.Case ISP(x) < ICP(item)
// 16.      PUSH(x)
// 17.      PUSH(item)
// 18. Otherwise
// 19.    print("Invalid")

// Aim :- PostFix Evaluation
// Input: Postfix Expression with Single digit operands in E
// Output : Value after evaluation
// Data Structure :- Stack (Array in LIFO) with top pointed in the top

// Start
// 1.Initialize STACK TOP = -1
// 2.while(TOP>=-1)do
// 3. item = E.Readsymbol()
// 4. Case item = operand
//     a. PUSH(item)
// 5. Case item = operator
//      a. x2 = POP()
//      b. x1 = POP()
//      c. PUSH(x1(item)x2)
// 6. Case item = #
//      x = POP()
//      return x
// 7. Otherwise
// 8.    print("Invalid")
// Stop


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
    input_with_p[i] = ')';


    result = postfix(input_with_p);
    printf("Expression in PostFix Form: %s\n", result);

    result_with_h = add_symbol(result, '#');

    printf("Postfix Evaluated Value: %d", evaluate_postfix(result_with_h));

    free(input_with_p);
    free(result_with_h);
    free(result);

    return 0;
}
