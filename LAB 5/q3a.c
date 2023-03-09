# include <stdio.h>
# include <stdlib.h>

# define MAX_VERTICES 100

struct node{
    int vertex;
    struct node *next;
};

typedef struct node Node;

Node *graph[MAX_VERTICES];

int stack[MAX_VERTICES];
int top = -1;

int visited[MAX_VERTICES];

void add_edge(int u, int v){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node -> vertex = v;
    new_node -> next = graph[u];
    graph[u] = new_node;
}

void dfs(int vertex){
    visited[vertex] = 1;

    Node *temp = graph[vertex];
    while (temp != NULL) {
        int adjacent_vertex = temp->vertex;
        if (!visited[adjacent_vertex]) {
            dfs(adjacent_vertex);
        }
        temp = temp->next;
    }

    stack[++top] = vertex;
}

void topological_sort(int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < num_vertices; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int num_vertices, num_edges;
    int u, v;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_vertices; i++) {
        graph[i] = NULL;
    }

    for (int i = 0; i < num_edges; i++) {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);

        add_edge(u, v);
    }

    topological_sort(num_vertices);

    return 0;
}