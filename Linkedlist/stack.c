// Aim :- 	Implement a Stack using LinkedList with the operations:
// .Pushing elements to the Stack.
// .Popping elements from the Stack
// .Display the contents of the Stack after each operation.

// Implement Stack Functions

// Input :- Menu driven push pop printing
// Output:- Stack After Operations
// Data Structure Used:- Stack using LinkedList pointed by a TOP

// Start
// 1. Set up a node for LinkedList and SET TOP = NULL
//
// 2. Function Push(X)
// 3. newNode = GetNode(node)
// 4. if newNode is NULL
// 5.   print OverFlow
// 6. newNode->data = X
// 7. newNode->link = TOP->link
// 8. TOP->link = newNode


// 9. Function POP()
// 10. Check the STACK is empty (TOP == NULL)
// 11. X = TOP->data
// 12. ptr=TOP
// 13. TOP = TOP->link
// 14. ReturnNode(ptr)
// 15. return X
//
//
// 16. Call the Functions according to the menu
// 17. PRINT STACK
// Stop

// Time Complexity
// POP
// Worst Case :- O(1)

// Space Complexity
// O(1)

// PUSH
// Worst Case :- O(1) ;

// Space Complexity
// O(1)


# include <stdio.h>
# include <stdlib.h>

struct stack {
    int data;
    struct stack *link;
};

void push(struct stack **top, int val) {
    struct stack *next = (struct stack *) malloc(sizeof(struct stack));
    if (next == NULL) {
        printf("Memory Underflow\n");
        return;
    }
    next->data = val;
    next->link = *top;
    *top = next;
}

int pop(struct stack **top) {
    if (*top == NULL) {
        printf("LinkedList UnderFlow\n");
        return NULL;
    }
    int val = (*top)->data;
    struct stack *ptr = *top;
    *top = (*top)->link;
    free(ptr);
    return val;
}

void printStack(struct stack *top) {
    printf("Stack:- ");
    while (top) {
        printf("%d ", top->data);
        top = top->link;
    }
    printf("\n");
}

int main() {
    int n;
    int x;
    struct stack *top = NULL;
    start:
    printf("Enter 1 or 2 or 3 to perform an Operation others to quit: \n1.Push\n2.Pop\n3.Print\n4.Exit\n: ");
    scanf("%d", &n);
    switch (n) {
        case 1:
            printf("You chose \"PUSH\" \nEnter an element to push: ");
            scanf("%d", &x);
            push(&top, x);
            goto start;
        case 2:
            x = pop(&top);
            if (x != NULL) {
                printf("You chose \"POP\" \nThe element popped out: %d\n", x);
            }
            goto start;
        case 3:
            printStack(top);
            goto start;
        default:
            printf("Exiting ...\n");
            break;

    }
    return 0;
}