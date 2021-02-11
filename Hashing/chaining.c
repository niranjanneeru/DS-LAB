# include <stdio.h>
# include <stdlib.h>

# define HASH_SIZE 10

typedef struct chain_node {
    int data;
    struct chain_node *link;
} node;

void print(node **hash_table) {
    for (int i = 0; i < HASH_SIZE; ++i) {
        if (*(hash_table + i)) {
            printf("(%d)| -> |", i);
            node *ptr = *(hash_table + i);
            while (ptr) {
                printf(" -> %d ", ptr->data);
                ptr = ptr->link;
            }
        } else {
            printf("(%d)|    |", i);
        }
        printf("\n");
    }
}

int hash_function(int item) {
    return item % HASH_SIZE;
}

void insert(node **hash_table, int item) {
    int pos = hash_function(item);
    node *ptr = (node *) malloc(sizeof(node));
    ptr->data = item;
    ptr->link = NULL;
    if (*(hash_table + pos)) {
        ptr->link = *(hash_table + pos);
        *(hash_table + pos) = ptr;
    } else {
        *(hash_table + pos) = ptr;
    }
}

int search(node **hash_table, int item) {
    int pos = hash_function(item);
    node *ptr = hash_table[pos];
    while (ptr) {
        if (item == ptr->data) {
            return 1;
        }
        ptr = ptr->link;
    }
    return 0;
}

int delete(node **hash_table, int item) {
    int pos = hash_function(item);
    node *ptr = hash_table[pos];
    node *qtr = ptr;
    if (ptr) {
        while (ptr && ptr->data != item) {
            printf("%d", ptr->data);
            printf("%d", qtr->data);
            qtr = ptr;
            ptr = ptr->link;
        }
        if (ptr->data == item) {
            if (qtr->data == item) {
                hash_table[pos] = qtr->link;
                free(qtr);
            } else {
                qtr->link = ptr->link;
                free(ptr);
            }
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

void clear(node **hash_table) {
    node *ptr, *qtr;
    for (int i = 0; i < HASH_SIZE; ++i) {
        if (*(hash_table + i)) {
            ptr = *(hash_table + i);
            while (ptr) {
                qtr = ptr;
                ptr = ptr->link;
                free(qtr);
                qtr = NULL;
            }
        }
    }
    free(hash_table);
    hash_table = NULL;
}

int main() {
    node **hash_table;
    hash_table = (node **) calloc(HASH_SIZE, sizeof(node *));
    int choice, item;
    start:
    printf("Choose \n1. Insert \n2. Search \n3. Delete\n4. Print : ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &item);
            insert(hash_table, item);
            goto start;
        case 2:
            printf("Enter the data to be searched: ");
            scanf("%d", &item);
            if (search(hash_table, item)) {
                printf("Element Found in %dth chain\n", hash_function(item));
            } else {
                printf("Element Not Found\n");
            };
            goto start;
        case 3:
            printf("Enter the data to be deleted: ");
            scanf("%d", &item);
            if (delete(hash_table, item)) {
                printf("Element Deleted from %dth chain\n", hash_function(item));
            } else {
                printf("Element Not Found\n");
            };
            goto start;
        case 4:
            print(hash_table);
            goto start;
        default:
            clear(hash_table);
            printf("Exiting");

    }
    return 0;
}