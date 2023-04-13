#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int trans_closure[MAX_VERTICES][MAX_VERTICES];

void init_graph(int num_vertices)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

void print_graph(int num_vertices)
{
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void warshall(int num_vertices, int *opcount)
{
    int i, j, k;
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            trans_closure[i][j] = graph[i][j];
        }
    }
    for (k = 0; k < num_vertices; k++) {
        for (i = 0; i < num_vertices; i++) {
            for (j = 0; j < num_vertices; j++) {
                trans_closure[i][j] = trans_closure[i][j] || (trans_closure[i][k] && trans_closure[k][j]);
                (*opcount)++;
            }
        }
    }

    printf("Operation count: %d\n", *opcount);

}

void print_trans_closure(int num_vertices)
{
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            printf("%d ", trans_closure[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int num_vertices;
    int opcount = 0;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    init_graph(num_vertices);

    printf("\nRandomly generated graph:\n");
    print_graph(num_vertices);

    warshall(num_vertices, &opcount);

    printf("\nTransitive closure of the graph:\n");
    print_trans_closure(num_vertices);

    return 0;
}