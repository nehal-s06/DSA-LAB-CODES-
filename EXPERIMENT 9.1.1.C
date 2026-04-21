#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph represented using adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];
int visited[MAX_VERTICES];

// Function to create a new adjacency list node
Node* createNode(int vertex) {
          Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
    
    
    
    
}

// Function to add an edge to the graph
void addEdge(int u, int v) {
         Node* newNode = createNode(v);

    // Insert at beginning (we will sort later)
    newNode->next = adjList[u];
    adjList[u] = newNode;
    
    
    
    
}

// Function to sort the adjacency list for each vertex
void sortAdjList(int V) {
        for (int i = 0; i < V; i++) {
        if (adjList[i] == NULL) continue;

        Node *sorted = NULL;

        Node *current = adjList[i];
        while (current != NULL) {
            Node *next = current->next;

            // Insert into sorted list
            if (sorted == NULL || current->vertex < sorted->vertex) {
                current->next = sorted;
                sorted = current;
            } else {
                Node *temp = sorted;
                while (temp->next != NULL && temp->next->vertex < current->vertex) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }

            current = next;
        }

        adjList[i] = sorted;
	}
    
    
    
    
}

// Depth-First Search (DFS) function
void DFS(int start) {
         visited[start] = 1;
    printf("%d ", start);

    Node* temp = adjList[start];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
	}
    
    
    
    
}

int main() {
    int V, E;
    int u, v, start;

    // Read number of vertices and edges
    scanf("%d %d", &V, &E);

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Read the edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Sort the adjacency list for each vertex
    sortAdjList(V);

    // Read the starting node
    scanf("%d", &start);

    // Perform DFS starting from the given node
    DFS(start);

    return 0;
}