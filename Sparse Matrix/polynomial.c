// Write a program to read two polynomials and store them in an array.
// Calculate the sum of the two polynomials and display the first polynomial,
// second polynomial and the resultant polynomial.

// Sum of polynomials

// Input:- Two polynomial in the array whose exp and coeff in Strucutre ie, Array of Strucutre
// Output:- Resultant Polynomial array which is the sum of both
// Data Strucutre Used:- Array of Strucutre

// Start
// 1. Accept two polynomial array P,Q
// 2. Accept the number of elements in both representation in two variables t1,t2 respectivily
// 3. while(i<t1 || j<t2)
// 4. if P[i].exp == Q[j].exp
// 5.   R[k].coeff = P[i].coeff+Q[j++].coeff
// 6.   R[k++].exp = P[i++].exp
// 7. else if P[i].exp > Q[j].exp
// 8.   R[k].coeff = P[i].coeff
// 9.   R[k++].exp = P[i++].exp
// 10. else if P[i].exp < Q[j].exp
// 11.   R[k].coeff = Q[j].coeff
// 12.   R[k++].exp = Q[j++].exp
// 13. Print the Resultant Array
// Stop

// Time Complexity
// Best Case :- O(n+m)
// Average Case :- O(n+m)
// Worst Case :- O(n+m)

// Space Complexity
// O(n+m)


#include <stdio.h>

# define MAX 100

struct polynomial {
    int exp;
    int coeff;
};

void acceptPolynomial(struct polynomial *P, int *t) {
    printf("\n");
    printf("Enter the number of terms in Polynomial : ");
    scanf("%d", t);
    for (int i = 0; i < *t; i++) {
        printf("Enter the Coefficient: ");
        scanf("%d", &P[i].coeff);
        printf("Enter the Exponent: ");
        scanf("%d", &P[i].exp);
    }
    printf("\n");
}

int addRepresentation(int, int, struct polynomial *, struct polynomial *, struct polynomial *);

void printPolynomial(struct polynomial *, int t);

int main() {
    struct polynomial P[MAX], Q[MAX], R[MAX];
    int t1, t2;
    // Accepting
    acceptPolynomial(P, &t1);
    acceptPolynomial(Q, &t2);
    // Trigger
    int t3 = addRepresentation(t1, t2, P, Q, R);
    // Printing
    printf("Polynomial 1: ");
    printPolynomial(P, t1);
    printf("Polynomial 2: ");
    printPolynomial(Q, t2);
    printf("Sum : ");
    printPolynomial(R, t3);
    return 0;
}

int addRepresentation(int n, int m, struct polynomial *P, struct polynomial *Q, struct polynomial *R) {
    int count = 0;
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (P[i].exp == Q[j].exp) {
            R[count].exp = P[i].exp;
            R[count].coeff = P[i].coeff + Q[j].coeff;
            i++;
            j++;
        } else if (P[i].exp > Q[j].exp) {
            R[count].exp = P[i].exp;
            R[count].coeff = P[i].coeff;
            i++;
        } else if (P[i].exp < Q[j].exp) {
            R[count].exp = Q[j].exp;
            R[count].coeff = Q[j].coeff;
            j++;
        }
        count++;
    }
    while (i < n) {
        R[count].exp = P[i].exp;
        R[count].coeff = P[i].coeff;
        i++;
        count++;
    }
    while (j < m) {
        R[count].exp = Q[j].exp;
        R[count].coeff = Q[j].coeff;
        j++;
        count++;
    }
    return count;
}

void printPolynomial(struct polynomial *temp, int t) {
    for (int i = 0; i < t; i++) {
        printf("%dx^%d", temp[i].coeff, temp[i].exp);
        if (i != t - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Output
// Enter the number of terms in Polynomial : 3
// Enter the Coefficient: 12
// Enter the Exponent: 99
// Enter the Coefficient: 4
// Enter the Exponent: 4
// Enter the Coefficient: 2
// Enter the Exponent: 2
//
//
// Enter the number of terms in Polynomial : 2
// Enter the Coefficient: 10
// Enter the Exponent: 4
// Enter the Coefficient: 1
// Enter the Exponent: 1
//
// Polynomial 1: 12x^99 + 4x^4 + 2x^2
// Polynomial 2: 10x^4 + 1x^1
// Sum : 12x^99 + 14x^4 + 2x^2 + 1x^1
