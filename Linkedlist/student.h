# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct student {
    int number;
    char *name;
    int total_mark;
    struct student *link;
};

struct student *create() {
    return NULL;
}


void addAsFirst(struct student **head, int number, char *name, int total_mark) {
    struct student *next = (struct student *) malloc(sizeof(struct student));
    if (next == NULL) {
        printf("Memory Overflow\n");
        return;
    }
    next->link = *head;
    *head = next;
    next->number = number;
    next->name = name;
    next->total_mark = total_mark;
}


struct student *deleteFirst(struct student **head) {
    if (*head == NULL) {
        printf("LinkedList UnderFlow\n");
        return NULL;
    }
    struct student *ptr = *head;
    *head = (*head)->link;
    return ptr;
}

void addAsLast(struct student **head, int number, char *name, int total_mark) {
    struct student *ptr = *head;
    struct student *node = (struct student *) malloc(sizeof(struct student));
    if (node == NULL) {
        printf("Memory Underflow\n");
        return;
    }
    if (*head == NULL) {
        node->link = *head;
        *head = node;
        node->number = number;
        node->name = name;
        node->total_mark = total_mark;
        return;
    }
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    node->link = ptr->link;
    ptr->link = node;
    node->number = number;
    node->name = name;
    node->total_mark = total_mark;
}


struct student *deleteLast(struct student **head) {
    struct student *prev, *ptr = *head;
    if (*head == NULL) {
        printf("List Underflow\n");
        return NULL;
    }
    if ((*head)->link == NULL) {
        struct student *ptr = *head;
        *head = (*head)->link;
        return ptr;
    }
    while (ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
    }
    prev->link = ptr->link;
    return ptr;
}


void print(struct student *head) {
    printf("Student Linked List\n");
    while (head) {
        printf("%d. %s : %d marks\n", head->number, head->name, head->total_mark);
        head = head->link;
    }
    printf("\n");
}


void clearList(struct student *head) {
    struct student *ptr;
    while (head) {
        ptr = head;
        head = head->link;
        free(ptr->name);
        free(ptr);
    }
}

struct student *searchStudentByNumber(struct student *head, int number) {
    while (head && head->number != number) {
        head = head->link;
    }
    if (head) {
        return head;
    }
    printf("Record Not Found with number: %d\n", number);
    return NULL;
}

struct student *searchStudentByName(struct student *head, char *name) {
    while (head && strcmp(head->name, name) != 0) {
        head = head->link;
    }
    if (head) {
        return head;
    }
    printf("Record Not Found with Name: %s\n", name);
    return NULL;
}


void singleSwap(struct student *ptr) {
    if (ptr == NULL || ptr->link == NULL) {
        return;
    }
    if (ptr->number <= ptr->link->number) {
        singleSwap(ptr->link);
    } else {
        int temp = ptr->number;
        ptr->number = ptr->link->number;
        ptr->link->number = temp;
        temp = ptr->total_mark;
        ptr->total_mark = ptr->link->total_mark;
        ptr->link->total_mark = temp;
        char *t = ptr->name;
        ptr->name = ptr->link->name;
        ptr->link->name = t;
        singleSwap(ptr->link);
    }
}

struct student *sort(struct student *head) {
    if (head == NULL) {
        printf("Empty LinkedList\n");
        return NULL;
    }
    struct student *ptr = head;
    while (ptr->link) {
        singleSwap(head);
        ptr = ptr->link;
    }
    return NULL;
}

void addWithIndex(struct student **head, int number, char *name, int total, int where) {
    int count = 2;
    struct student *ptr = *head;
    if (where <= 0) {
        printf("Index not Found\n");
        return;
    }
    if (*head == NULL) {
        if (where != 1) {
            printf("Index not Found\n");
            return;
        }
    }
    if (where == 1) {
        struct student *node = (struct student *) malloc(sizeof(struct student));
        if (node == NULL) {
            printf("Memory Underflow\n");
            return;
        }
        node->link = *head;
        *head = node;
        node->name = name;
        node->number = number;
        node->total_mark = total;
        return;
    }
    while (count != where && ptr->link != NULL) {
        ptr = ptr->link;
        count++;
    }
    if (count != where) {
        printf("Index not Found\n");
        return;
    }
    struct student *node = (struct student *) malloc(sizeof(struct student));
    if (node == NULL) {
        printf("Memory Underflow\n");
        return;
    }
    node->name = name;
    node->number = number;
    node->total_mark = total;
    node->link = ptr->link;
    ptr->link = node;
}


struct student *deleteWithIndex(struct student **head, int where) {
    int count = 1;
    struct student *prev = *head, *ptr = *head;
    if (*head == NULL) {
        printf("List Underflow\n");
        return NULL;
    }
    if (where == 1) {
        *head = ptr->link;
        return ptr;
    }
    while (where != count && ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
        count++;
    }
    if (where != count) {
        printf("Index not Found\n");
        return NULL;
    }
    prev->link = ptr->link;
    return ptr;
}