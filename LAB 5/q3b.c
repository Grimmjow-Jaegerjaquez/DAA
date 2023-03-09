# include <stdio.h>
# include <stdlib.h>

# define MAX_VERTICES 100

struct node{
    int vertex;
    struct node *next;
};

typedef struct node Node;
Node *graph[MAX_VERTICES];

int indegree[MAX_VERTICES]; 
int topological_order[MAX_VERTICES];

void add_edge(int u, int v) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->vertex = v;
    new_node->next = graph[u];
    graph[u] = new_node;

    indegree[v]++;
}

void topological_sort(int num_vertices) {
    int index = 0;
    int queue[MAX_VERTICES];
    int front = 0, rear = -1;

    for (int i = 0; i < num_vertices; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    while (front <= rear) {
        int vertex = queue[front++];
        topological_order[index++] = vertex;

        Node* temp = graph[vertex];
        while (temp != NULL) {
            int adjacent_vertex = temp->vertex;
            indegree[adjacent_vertex]--;
            if (indegree[adjacent_vertex] == 0) {
                queue[++rear] = adjacent_vertex;
            }
            temp = temp->next;
        }
    }

    if (index != num_vertices) {
        printf("The graph has a cycle!\n");
        return;
    }

    printf("Topological order: ");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", topological_order[i]);
    }
    printf("\n");
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
        indegree[i] = 0;
    }

    for (int i = 0; i < num_edges; i++) {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);

        add_edge(u, v);
    }

    topological_sort(num_vertices);

    return 0;
}
