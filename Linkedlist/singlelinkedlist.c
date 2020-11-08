# include<stdio.h>
# include "sll.h"

void main() {
    struct node *head = create();
    int a, val, where;
    start:
    printf("Choose one of the Operations\n1. AddAsFirst\n2. AddAsLast\n3. AddWithKey\n4. AddWithIndex\n5. DeleteFirst\n6. DeleteLast\n7. DeleteWithKey\n8. DeleteWithIndex\n9. Display\n10. Exit\n: ");
    scanf("%d", &a);
    switch (a) {
        case 1:
            printf("Enter the value to add at first: ");
            scanf("%d", &val);
            addAsFirst(&head, val);
            goto start;
        case 2:
            printf("Enter the value to add at last: ");
            scanf("%d", &val);
            addAsLast(&head, val);
            goto start;
        case 3:
            printf("Enter the value to insert: ");
            scanf("%d", &val);
            printf("After which value we have to insert(Set it to a random value if sll is empty): ");
            scanf("%d", &where);
            addWithKey(&head, val, where);
            goto start;
        case 4:
            printf("Enter the value to insert: ");
            scanf("%d", &val);
            printf("Enter the index to insert: ");
            scanf("%d", &where);
            addWithIndex(&head, val, where);
            goto start;
        case 5:
            where = deleteFirst(&head);
            if (where != NULL) {
                printf("Extracted Value :- %d", where);
            }
            printf("\n");
            goto start;
        case 6:
            where = deleteLast(&head);
            if (where != NULL) {
                printf("Extracted Value :- %d", where);
            }
            printf("\n");
            goto start;
        case 7:
            printf("Enter the value to delete: ");
            scanf("%d", &val);
            where = deleteWithKey(&head, val);
            if (where != NULL) {
                printf("Extracted Value :- %d", where);
            }
            printf("\n");
            goto start;
        case 8:
            printf("Enter the index for deletion: ");
            scanf("%d", &where);
            val = deleteWithIndex(&head, where);
            if (val != NULL) {
                printf("Extracted Value :- %d", val);
            }
            printf("\n");
            goto start;
        case 9:
            print(head);
            goto start;
        case 10:
            printf("Exiting...");
            break;
        default:
            printf("I didn't quite catch it");
            goto start;
    }
}