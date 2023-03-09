# include <stdio.h>
# include <stdlib.h>

# define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];

int visited[MAX_VERTICES];

void dfs(int vertex, int num_vertices){
    visited[vertex] = 1;
    printf("%d ", vertex);

    for(int i = 0; i < num_vertices; i++){
        if(graph[vertex][i] && !visited[i])
            dfs(i, num_vertices);
    }
}

int main(){
    int num_vertices, num_edges, u, v;

    printf("Enter the number of vertices in the graph : ");
    scanf("%d",&num_vertices);

    printf("Enter the number of edges in the graph : ");
    scanf("%d", &num_edges);

    for(int i = 0; i < num_vertices; i++){
        for(int j = 0; j < num_vertices; j++){
            graph[i][j] = 0;
        }
    }

    for(int i = 0; i < num_edges; i++){
        printf("Enter edge %d (u v) : ", i + 1);
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Depth-first search traversal: ");
    for (int i = 1; i < num_vertices; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < num_vertices; i++) {
        if (!visited[i]) {
            dfs(i, num_vertices);
        }
    }

    return 0;
}