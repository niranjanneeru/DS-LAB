# include <stdio.h>
# include "dll.h"
# include <string.h>
# include <stdlib.h>


int main() {
//    node *head = create();
//    addAsFront(&head,'a');
//    addAsFront(&head,'a');
//    addLast(&head,'b');
//    addWithIndex(&head,'c',2);
//    print(head);
//    deleteWithIndex(&head,3);
//    print(head);

    int length = 100;
    node *head = create();
    char *in, *pos;
    in = (char *) malloc(length * sizeof(char));
    printf("Enter the string: ");
    fgets(in, length, stdin);
    if (in[0] == '\n') {
        fgets(in, length, stdin);
    }
    if ((pos = strchr(in, '\n')) != NULL)
        *pos = '\0';
    for (int i = strlen(in); i > 0; i--) {
        addAsFront(&head, in[i - 1]);
    }
    if (isPalindrome(head)) {
        printf("%s is Palindrome", in);
    } else {
        printf("%s is not Palindrome", in);
    }
    clearList(head);
    free(in);
    return 0;
}