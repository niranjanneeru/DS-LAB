# include <stdio.h>
# include <stdlib.h>

typedef struct construct {
    char data;
    struct construct *next, *prev;
} node;

node *create() {
    return NULL;
}

void addAsFront(node **head, char data) {
    node *ptr = (node *) malloc(sizeof(node));
    if (!ptr) {
        printf("Memory Underflow\n");
        return;
    }
    ptr->data = data;
    ptr->next = *head;
    if (*head) {
        (*head)->prev = ptr;
    }
    ptr->prev = NULL;
    *head = ptr;
}

void addLast(node **head, char data) {
    if (!*head) {
        addAsFront(head, data);
    }
    node *ptr = *head;
    node *next = (node *) malloc(sizeof(node));
    if (!next) {
        printf("Memory Underflow\n");
        return;
    }
    while (ptr->next) {
        ptr = ptr->next;
    }
    next->next = ptr->next;
    ptr->next = next;
    next->prev = ptr;
    next->data = data;
}


void addWithIndex(node **head, char data, int where) {
    int count = 2;
    if (where <= 0) {
        printf("Index not Found\n");
        return;
    }
    if (!*head) {
        if (where != 1) {
            printf("Index not Found\n");
            return;
        }
    }
    if (where == 1) {
        addAsFront(head, data);
    }
    node *ptr = *head;
    while (ptr->next && count != where) {
        count++;
        ptr = ptr->next;
    }
    if (count != where) {
        printf("Index not Found\n");
        return;
    }
    node *ptr1 = (node *) malloc(sizeof(node));
    if (!ptr1) {
        printf("Memory Underflow\n");
        return;
    }
    ptr1->next = ptr->next;
    ptr1->prev = ptr;
    ptr1->data = data;
    ptr->next = ptr1;
}

char deleteFirst(node **head) {
    if (!*head) {
        printf("LinkedList UnderFlow\n");
        return '\0';
    }
    char o = (*head)->data;
    (*head)->next->prev = (*head)->prev;
    node *ptr = (*head);
    (*head) = (*head)->next;
    free(ptr);
    return o;
}

char deleteLast(node **head) {
    if (!*head) {
        printf("LinkedList UnderFlow\n");
        return '\0';
    }
    if (!(*head)->next) {
        return deleteFirst(head);
    }
    node *ptr = *head;
    while (ptr->next) {
        ptr = ptr->next;
    }
    char c = ptr->data;
    ptr->prev->next = ptr->next;
    free(ptr);
    return c;
}

char deleteWithIndex(node **head, int where) {
    int count = 1;
    if (!*head) {
        printf("LinkedList UnderFlow\n");
        return '\0';
    }
    if (where <= 0) {
        printf("Index not Found\n");
        return '\0';
    }
    if (where == 1) {
        deleteFirst(head);
    }
    node *ptr = *head;
    while (ptr->next && count != where) {
        count++;
        ptr = ptr->next;
    }
    if (count != where) {
        printf("Index not Found\n");
        return '\0';
    }
    char c = ptr->data;
    ptr->prev->next = ptr->next;
    free(ptr);
    return c;
}

int isPalindrome(node *head) {
    if (!head) {
        printf("Empty List");
        return 0;
    }
    node *tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    while (head != tail) {
        if (head->data != tail->data) {
            return 0;
        }
        head = head->next;
        tail = tail->prev;
    }
    return 1;
}

void clearList(node *head) {
    node *ptr;
    while (head) {
        ptr = head;
        head = head->next;
        free(ptr);
    }
}

void print(node *head) {
    if (head) {
        printf("%d ", head->data);
        print(head->prev);
    } else {
        printf("\n");
    }
}

