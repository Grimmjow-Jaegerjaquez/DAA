#include <stdio.h>
#include <stdlib.h>

int opc = 0;

void floyd(int **a, int len)
{
    for(int itr = 0; itr < len; itr++)
    {
        for(int i = 0; i < len; i++)
        for(int j = 0; j < len; j++)
        {
            opc++;
            if(i == itr || j == itr) continue;
            else a[i][j] = (a[i][itr] + a[itr][j] > a[i][j]) ? a[i][j] : a[i][itr] + a[itr][j];
        }
    }
}

int main()
{
    int len;
    printf("Enter number of vertices: ");
    scanf("%d", &len);

    int ** adj = (int **) malloc(sizeof(int*) * len);
    for(int i = 0; i < len; i++) adj[i] = (int *) malloc(sizeof(int) * len);

    printf("Enter adj matrix: \n");
    for(int i = 0; i < len; i++)
    for(int j = 0; j < len; j++)
        scanf("%d", &adj[i][j]);

    floyd(adj, len);

    printf("\nAfter floyd: \n");
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
            printf("%d\t", adj[i][j]);
        printf("\n");
    }

    printf("Opc = %d\n", opc);
}