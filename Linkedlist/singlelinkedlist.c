# include<stdio.h>
# include "sll.h"

void main(){
    struct node_int * head = create_sll_int();
    int a,val,where;
    start:
    printf("Choose one of the Operations\n1. Insert\n2. Delete\n3. Display\n4. Exit\n: ");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        printf("Enter the value to insert: ");
        scanf("%d",&val);
        printf("After which value we have to insert(Set it to a random value if sll is empty): ");
        scanf("%d",&where);
        insert_sll_int(&head,val,where);
        goto start;
    case 2:
        printf("Enter the value to delete: ");
        scanf("%d",&val);
        where = delete_sll_int(&head,val);
        if(where != NULL){
            printf("Extracted Value :- %d",where);
        }
        printf("\n");
        goto start;
    case 3:
        print_sll_int(head);
        goto start;
    case 4:
    printf("Exiting...");
    break;
    default:
    printf("I didn't quite catch it");
        goto start;
    }
}