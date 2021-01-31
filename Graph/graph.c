// bfs(int v)
//    visited[v] = 1
//    enqueue v
//    while not empty queue
//        u = dequeue
//        for i from 0 to n
//            if adj[u][i] == 1 and visited[i] == 0
//               visited[i] = 1
//               enqueue i
//
// dfs(int v)
//    visited[v] = 1
//    push v
//    while not empty stack
//        u = pop;
//        for i from 0 to n
//            if adj[u][i] == 1 and visited[i] == 0
//               visited[i] = 1;
//               push i



# include <stdio.h>
# include <stdlib.h>
# include "queue.h"
# include "linear_search.h"
# include "stack.h"

struct stack *s = NULL;
char *node_array;
int **adj, n;
int *visited;
queue q;
char c;
int loc;

void bfs(int);

void dfs(int);

void dfs_stack(int);

int main() {

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    create_queue(&q, n);
    node_array = (char *) malloc(n * sizeof(char));
    adj = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        *(adj + i) = (int *) malloc(n * sizeof(int));
    }

    printf("Enter the nodes: ");
    fflush(stdin);
    for (int i = 0; i < n; ++i) {
        c = getchar();
        if (c == ' ' || c == '\n') {
            i--;
            continue;
        }
        *(node_array + i) = c;

    }
    printf("Enter the Adjacency Matrix: ");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", *(adj + i) + j);
        }
    }

    printf("From Where should we start bfs: ");
    c = getchar();
    if (c == ' ' || c == '\n') {
        c = getchar();
    }
    loc = linear_search(node_array, n, c);
    if (loc == -1) {
        printf("Node Missing");
    } else {
        visited = (int *) calloc(n, sizeof(int));
        bfs(loc);
        free(visited);
    }

    printf("\n");

    printf("From Where should we start dfs: ");
    c = getchar();
    if (c == ' ' || c == '\n') {
        c = getchar();
    }

    loc = linear_search(node_array, n, c);
    if (loc == -1) {
        printf("Node Missing");
    } else {
        visited = (int *) calloc(n, sizeof(int));
        dfs(loc);
        free(visited);
    }

    printf("\n");

    printf("From Where should we start dfs using stack: ");
    c = getchar();
    if (c == ' ' || c == '\n') {
        c = getchar();
    }

    loc = linear_search(node_array, n, c);
    if (loc == -1) {
        printf("Node Missing");
    } else {
        visited = (int *) calloc(n, sizeof(int));
        dfs_stack(loc);
        free(visited);
    }

    free(node_array);
    for (int i = 0; i < n; ++i) {
        free(*(adj + i));
    }
    free(adj);

    return 0;
}

void bfs(int v) {
    int u;
    visited[v] = 1;
//    printf("%c ", node_array[v]);
    enqueue(&q, v);
    while (!isEmpty(&q)) {
        u = dequeue(&q);
        printf("%c ", node_array[u]);
        for (int i = 0; i < n; ++i) {
            if (*(*(adj + u) + i) && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}

void dfs(int v) {
    visited[v] = 1;
    printf("%c ", node_array[v]);
    for (int i = 0; i < n; ++i) {
        if (*(*(adj + v) + i) && !visited[i]) {
            dfs(i);
        }
    }
}


void dfs_stack(int v) {
    visited[v] = 1;
    int u;
//    printf("%c ", node_array[v]);
    push(&s, v);
    while (!isStackEmpty(&s)) {
        u = pop(&s);
        printf("%c ", node_array[u]);
        for (int i = 0; i < n; ++i) {
            if (*(*(adj + u) + i) && !visited[i]) {
                visited[i] = 1;
                push(&s, i);
            }
        }
    }
}
