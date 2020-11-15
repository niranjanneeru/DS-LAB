# include <stdio.h>
#include <stdlib.h>

typedef struct term {
    int exp;
    float coeff;
    struct term *link;
} node;

node *create() {
    return NULL;
}

void addAsFront(node **head, int exp, float coeff) {
    node *ptr = (node *) malloc(sizeof(node));
    if (!ptr) {
        printf("Memory Overflow\n");
        return;
    }
    ptr->exp = exp;
    ptr->coeff = coeff;
    ptr->link = *head;
    *head = ptr;
}

void print(node *head) {
    printf("Polynomial Linked List\n");
    while (head) {
        printf("%.2f x^%d", head->coeff, head->exp);
        head = head->link;
        if (head) {
            printf("+ ");
        }
    }
    printf("\n");
}


void clearList(node *head) {
    node *ptr;
    while (head) {
        ptr = head;
        head = head->link;
        free(ptr);
    }
}

node *add(node *head1, node *head2) {
    node *res = NULL;
    if (!head1 || !head2) {
        printf("Can't perform the operations");
        return NULL;
    }
    while (head1 && head2) {
        if (head1->exp == head2->exp) {
            addAsFront(&res, head1->exp, head1->coeff + head2->coeff);
            head1 = head1->link;
            head2 = head2->link;
        } else if (head1->exp > head2->exp) {
            addAsFront(&res, head1->exp, head1->coeff);
            head1 = head1->link;
        } else {
            addAsFront(&res, head2->exp, head2->coeff);
            head2 = head2->link;
        }
    }
    while (head1) {
        addAsFront(&res, head1->exp, head1->coeff);
        head1 = head1->link;
    }
    while (head2) {
        addAsFront(&res, head2->exp, head2->coeff);
        head2 = head2->link;
    }
    return res;
}

void similarCoeffCheck(node **head) {
    node *ptr = *head, *ptr1, *ptr2;
    while (ptr && ptr->link) {
        ptr1 = ptr;
        while (ptr1->link) {
            if (ptr->exp == ptr1->link->exp) {
                ptr->coeff += ptr1->link->coeff;
                ptr2 = ptr1->link;
                ptr1->link = ptr1->link->link;
                free(ptr2);
            } else {
                ptr1 = ptr1->link;
            }
        }
        ptr = ptr->link;
    }
}

node *multiply(node *head1, node *head2) {
    if (!head1 || !head2) {
        printf("Can't perform the operations");
        return NULL;
    }
    node *res = NULL;
    float coeff;
    int exp;
    node *p = head1, *q = head2;
    while (p) {
        while (q) {
            coeff = p->coeff * q->coeff;
            exp = p->exp + q->exp;
            addAsFront(&res, exp, coeff);
            q = q->link;
        }
        q = head2;
        p = p->link;
    }
    similarCoeffCheck(&res);
    return res;
}
