# include <stdio.h>

# include "polynomial.h"

int main() {
    int exp;
    float coeff;
    char choice;
    node *head1 = NULL, *head2 = NULL, *res = NULL;

    printf("Polynomial 1\n");
    step1:
    printf("Enter the coefficient: ");
    scanf_s("%f", &coeff);
    printf("Enter the exponent: ");
    scanf_s("%d", &exp);
    addAsFront(&head1, exp, coeff);
    printf("Are there more terms(Y/N): ");
    scanf_s("%c", &choice);
    if (choice == '\n')
        scanf_s("%c", &choice);
    if (choice == 'Y' || choice == 'y')
        goto step1;

    printf("Polynomial 2\n");
    step2:
    printf("Enter the coefficient: ");
    scanf_s("%f", &coeff);
    printf("Enter the exponent: ");
    scanf_s("%d", &exp);
    addAsFront(&head2, exp, coeff);
    printf("Are there more terms(Y/N): ");
    scanf_s("%c", &choice);
    if (choice == '\n')
        scanf_s("%c", &choice);
    if (choice == 'Y' || choice == 'y')
        goto step2;

    printf("Polynomial 1\n");
    print(head1);
    printf("Polynomial 2\n");
    print(head2);

    res = add(head1, head2);
    printf("Polynomial After Summation\n");
    print(res);
    clearList(res);

    res = multiply(head1, head2);
    printf("Polynomial After Multiplication\n");
    print(res);
    clearList(res);

    clearList(head1);
    clearList(head2);
}