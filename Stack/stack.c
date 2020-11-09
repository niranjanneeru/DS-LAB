// 5.	Implement a Stack using arrays with the operations:
// 5.1.Pushing elements to the Stack.
// 5.2.Popping elements from the Stack
// 5.3.Display the contents of the Stack after each operation.

// Implement Stack Functions

// Input :- Menu driven push pop printing
// Output:- Stack After Operations
// Data Strucutre Used:- Stack

// Start
// 1. Initilize an Array and SET TOP = -1
//
// 2. Function Push(X)
// 3. Check the STACK is full (TOP == MAX-1)
// 4. Increase the value of TOP
// 5.   STACK[TOP] = X
//
// 6. Function POP()
// 7. Check the STACK is empty (TOP == -1)
// 8. X = STACK[TOP]
// 9. Decrement TOP
// 10.return X
//
//
// 11. Call the Functions according to the menu
// 12. PRINT STACK
// Stop

// Time Complexity
// POP
// Worst Case :- O(1); n row and m coloumn

// Space Complexity
// O(1)

// PUSH
// Worst Case :- O(col*no.non zeros) ;

// Space Complexity
// O(1)

# include <stdio.h>
# include <stdlib.h>
# define MAX 5
int STACK[MAX];
int top = -1;

int isFull() {
    if (top >= MAX - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(int x) {
    if (isFull()) {
        printf("Stack Overflow\n");
    } else {
        STACK[++top] = x;
        printf("Sucess full operation at position %d\n",top);
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return STACK[top--];
    }
}

void printStack() {
  printf("\nStack: ");
    for (int i = 0; i <= top; ++i) {
        printf("%d ", STACK[i]);
    }
    if(isEmpty()){
      printf("Empty Stack");
    }
    printf("\n\n");
}

int main() {
  int n;
  start:
  printf("Enter 1 or 2 or 3 to perform an Operation others to quit: \n1.Push\n2.Pop\n3.Print\n");
  scanf("%d",&n );
  int x;
  switch (n) {
    case 1:
    printf("You chose \"PUSH\" \nEnter an element to push: ");
    scanf("%d", &x);
    push(x);
    goto start;
    case 2:
    x = pop();
    if(x!=-1){
    printf("You chose \"POP\" \nThe element poped out: %d\n",x);
  }
    goto start;
    case 3:
    printStack();
    goto start;
    default:
    printf("Exiting the Pallate\n");
    exit(0);

  }
    return 0;
}

// Output 1
// Enter 1 or 2 or 3 to perform an Operation others to quit:
// 1.Push
// 2.Pop
// 3.Print
// 2
// Stack Underflow
// Enter 1 or 2 or 3 to perform an Operation others to quit:
// 1.Push
// 2.Pop
// 3.Print
// 3
//
// Stack: Empty Stack
//
// Enter 1 or 2 or 3 to perform an Operation others to quit:
// 1.Push
// 2.Pop
// 3.Print
// 1
// You chose "PUSH"
// Enter an element to push: 12
// Sucess full operation at position 0
// Enter 1 or 2 or 3 to perform an Operation others to quit:
// 1.Push
// 2.Pop
// 3.Print
// 1
// You chose "PUSH"
// Enter an element to push: 54
// Sucess full operation at position 1
// Enter 1 or 2 or 3 to perform an Operation others to quit:
// 1.Push
// 2.Pop
// 3.Print
// 1
// You chose "PUSH"
// Enter an element to push: 76
// Sucess full operation at position 2
// Enter 1 or 2 or 3 to perform an Operation others to quit:
// 1.Push
// 2.Pop
// 3.Print
// 1
// You chose "PUSH"
// Enter an element to push: 45
// Sucess full operation at position 3
// Enter 1 or 2 or 3 to perform an Operation others to quit:
// 1.Push
// 2.Pop
// 3.Print
// 3
//
// Stack: 12 54 76 45
//
// Enter 1 or 2 or 3 to perform an Operation others to quit:
// 1.Push
// 2.Pop
// 3.Print
// 2
// You chose "POP"
// The element poped out: 45
// Enter 1 or 2 or 3 to perform an Operation others to quit:
// 1.Push
// 2.Pop
// 3.Print
// 2
// You chose "POP"
// The element poped out: 76
// Enter 1 or 2 or 3 to perform an Operation others to quit:
// 1.Push
// 2.Pop
// 3.Print
// 2
// You chose "POP"
// The element poped out: 54
// Enter 1 or 2 or 3 to perform an Operation others to quit:
// 1.Push
// 2.Pop
// 3.Print
// 3
//
// Stack: 12
//
// Enter 1 or 2 or 3 to perform an Operation others to quit:
// 1.Push
// 2.Pop
// 3.Print
// 1
// You chose "PUSH"
// Enter an element to push: 9
// Sucess full operation at position 1
// Enter 1 or 2 or 3 to perform an Operation others to quit:
// 1.Push
// 2.Pop
// 3.Print
// 1
// You chose "PUSH"
// Enter an element to push: 45
// Sucess full operation at position 2
// Enter 1 or 2 or 3 to perform an Operation others to quit:
// 1.Push
// 2.Pop
// 3.Print
// 1
// You chose "PUSH"
// Enter an element to push: 32
// Sucess full operation at position 3
// Enter 1 or 2 or 3 to perform an Operation others to quit:
// 1.Push
// 2.Pop
// 3.Print
// 176
// Exiting the Pallate
