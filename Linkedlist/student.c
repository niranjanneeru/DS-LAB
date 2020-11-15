# include <stdio.h>
# include <stdlib.h>
# include "student.h"

# define length 30

int main() {
    struct student *head = create();
    int choose, number, total_marks, where;
    char *s, *pos;
    struct student *temp;
    start:
    printf("Choose any the operations\n1.addAsFirst\n2.addAsLast\n3.deleteFirst\n4.deleteLast\n5.display\n6.searchStudentByNumber\n7.searchStudentByName\n8.sort\n9.addWithIndex\n10.deleteWithIndex\n11.Exit\n: ");
    scanf_s("%d", &choose);
    switch (choose) {
        case 1:
            s = (char *) malloc(length
                                * sizeof(char));
            printf("Enter the number (Roll No.) of the student: ");
            scanf_s("%d", &number);
            printf("Enter the Name: ");
            fgets(s, length, stdin);
            if (s[0] == '\n') {
                fgets(s, length, stdin);
            }
            if ((pos = strchr(s, '\n')) != NULL)
                *pos = '\0';
            printf("Enter the Total Mark for the student: ");
            scanf_s("%d", &total_marks);
            addAsFirst(&head, number, s, total_marks);
            goto start;
        case 2:
            s = (char *) malloc(length * sizeof(char));
            printf("Enter the number (Roll No.) of the student: ");
            scanf_s("%d", &number);
            printf("Enter the Name: ");
            fgets(s, length, stdin);
            if (s[0] == '\n') {
                fgets(s, length, stdin);
            }
            if ((pos = strchr(s, '\n')) != NULL)
                *pos = '\0';
            printf("Enter the Total Mark for the student: ");
            scanf_s("%d", &total_marks);
            addAsLast(&head, number, s, total_marks);
            goto start;
        case 3:
            temp = deleteFirst(&head);
            if (temp != NULL) {
                printf("Roll No. : %d Name : %s Total Marks : %d\n", temp->number, temp->name, temp->total_mark);
                free(temp->name);
                free(temp);
            }
            goto start;
        case 4:
            temp = deleteLast(&head);
            if (temp != NULL) {
                printf("Roll No. : %d Name : %s Total Marks : %d\n", temp->number, temp->name, temp->total_mark);
                free(temp->name);
                free(temp);
            }
            goto start;
        case 5:
            print(head);
            goto start;
        case 6:
            printf("Enter the number to be searched: ");
            scanf_s("%d", &number);
            temp = searchStudentByNumber(head, number);
            if (temp != NULL) {
                printf("Record Found\n");
                printf("Roll No. : %d Name : %s Total Marks : %d\n", temp->number, temp->name, temp->total_mark);
            }
            goto start;
        case 7:
            s = (char *) malloc(length * sizeof(char));
            printf("Enter the name to be searched: ");
            fgets(s, length, stdin);
            if (s[0] == '\n') {
                fgets(s, length, stdin);
            }
            if ((pos = strchr(s, '\n')) != NULL)
                *pos = '\0';
            temp = searchStudentByName(head, s);
            if (temp != NULL) {
                printf("Record Found\n");
                printf("Roll No. : %d Name : %s Total Marks : %d\n", temp->number, temp->name, temp->total_mark);
            }
            free(s);
            goto start;
        case 8:
            sort(head);
            print(head);
            goto start;
        case 9:
            s = (char *) malloc(length * sizeof(char));
            printf("Enter the number (Roll No.) of the student: ");
            scanf_s("%d", &number);
            printf("Enter the Name: ");
            fgets(s, length, stdin);
            if (s[0] == '\n') {
                fgets(s, length, stdin);
            }
            if ((pos = strchr(s, '\n')) != NULL)
                *pos = '\0';
            printf("Enter the Total Mark for the student: ");
            scanf_s("%d", &total_marks);
            printf("Where to insert this record: ");
            scanf_s("%d", &where);
            addWithIndex(&head, number, s, total_marks, where);
            goto start;
        case 10:
            printf("Where to delete: ");
            scanf_s("%d", &where);
            temp = deleteWithIndex(&head, where);
            if (temp != NULL) {
                printf("Roll No. : %d Name : %s Total Marks : %d\n", temp->number, temp->name, temp->total_mark);
                free(temp->name);
                free(temp);
            }
            goto start;
        default:
            clearList(head);
            printf("Exiting...");
            break;
    }
}