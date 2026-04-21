#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node *next;
} *GNODE;

GNODE graph[100] = {NULL};

/* Function to print adjacency list */
void print(int *N) {
    int i;
    GNODE temp;

    for (i = 1; i <= *N; i++) {
        if (graph[i] != NULL) {
            printf("%d=>", i);
            temp = graph[i];
            while (temp != NULL) {
                printf("%d\t", temp->vertex);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

/* Insert Edge */
void insertEdge(int *N) {
    int src, dest;
    GNODE newnode, temp;

    printf("Enter the source vertex of the edge : ");
    scanf("%d", &src);

    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &dest);

    if (src < 1 || src > *N || dest < 1 || dest > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    newnode = (GNODE)malloc(sizeof(struct node));
    newnode->vertex = dest;
    newnode->next = NULL;

    if (graph[src] == NULL) {
        graph[src] = newnode;
    } else {
        temp = graph[src];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }

    printf("After inserting edge the adjacency list is : \n");
    print(N);
}

/* Insert Vertex */
void insertVertex(int *N) {
    int i, edges, v;
    GNODE newnode, temp;

    (*N)++;

    /* edges from existing vertices to new vertex */
    printf("Enter the number of edges from existing vertices to new vertex : ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++) {
        scanf("%d", &v);

        if (v < 1 || v > *N) {
            printf("Invalid vertex.\n");
            (*N)--;
            return;
        }

        newnode = (GNODE)malloc(sizeof(struct node));
        newnode->vertex = *N;
        newnode->next = NULL;

        if (graph[v] == NULL)
            graph[v] = newnode;
        else {
            temp = graph[v];
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }

    /* edges from new vertex to existing vertices */
    printf("Enter the number of edges from new vertex to existing vertices : ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++) {
        scanf("%d", &v);

        if (v < 1 || v > *N) {
            printf("Invalid vertex.\n");
            (*N)--;
            return;
        }

        newnode = (GNODE)malloc(sizeof(struct node));
        newnode->vertex = v;
        newnode->next = NULL;

        if (graph[*N] == NULL)
            graph[*N] = newnode;
        else {
            temp = graph[*N];
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }

    printf("After inserting vertex the adjacency list is : \n");
    print(N);
}

/* Delete Edge */
void deleteEdge(int *N) {
    int src, dest;
    GNODE temp, prev;

    printf("Enter the source vertex of the edge : ");
    scanf("%d", &src);

    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &dest);

    if (src < 1 || src > *N || dest < 1 || dest > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    temp = graph[src];
    prev = NULL;

    while (temp != NULL) {
        if (temp->vertex == dest) {
            if (prev == NULL)
                graph[src] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("After deleting edge the adjacency list is : \n");
    print(N);
}

/* Delete Vertex */
void deleteVertex(int *N) {
    int v, i;
    GNODE temp, prev, del;

    if (*N == 0) {
        printf("Graph is empty.\n");
        return;
    }

    printf("Enter the vertex to be deleted : ");
    scanf("%d", &v);

    if (v < 1 || v > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    /* remove incoming edges */
    for (i = 1; i <= *N; i++) {
        if (i == v) continue;

        temp = graph[i];
        prev = NULL;

        while (temp != NULL) {
            if (temp->vertex == v) {
                if (prev == NULL)
                    graph[i] = temp->next;
                else
                    prev->next = temp->next;

                del = temp;
                temp = temp->next;
                free(del);
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
    }

    /* delete adjacency list of vertex */
    temp = graph[v];
    while (temp != NULL) {
        del = temp;
        temp = temp->next;
        free(del);
    }

    /* shift left */
    for (i = v; i < *N; i++)
        graph[i] = graph[i + 1];

    graph[*N] = NULL;

    /* update vertex numbers */
    for (i = 1; i < *N; i++) {
        temp = graph[i];
        while (temp != NULL) {
            if (temp->vertex > v)
                temp->vertex--;
            temp = temp->next;
        }
    }

    (*N)--;

    printf("After deleting vertex the adjacency list is : \n");
    print(N);
}