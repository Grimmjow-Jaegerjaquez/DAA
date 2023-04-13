#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 

void floyd(int n, int graph[n][n]) {
    int dist[n][n], i, j, k;
    int count = 0;  // Initialize count of basic operations
    
    // Initialize distance matrix with graph
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    
    // Run Floyd's algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                count++;  // Increment count for each basic operation
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    // Print distance matrix and basic operation count
    printf("Distance matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    printf("Basic operation count: %d\n", count);
}

int main() {
    int n;
    printf("Enter size of matrix : ");
    scanf("%d", &n);
    int graph[n][n], i, j;
    
    // Generate random input graph
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = rand() % 11;  // Random weight between 0 and 10
        }
    }
    
    // Run Floyd's algorithm with random input graph
    floyd(n, graph);
    
    return 0;
}