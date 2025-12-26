#include <stdio.h>

int visited[10];

void dfs(int n, int cost[10][10], int u)
{
    visited[u] = 1;

    for (int v = 0; v < n; v++)
    {
        if (cost[u][v] == 1 && !visited[v])
        {
            dfs(n, cost, v);
        }
    }
}

int main()
{
    int n, cost[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    dfs(n, cost, 0);

    int connected = 1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("Graph is connected\n");
    else
        printf("Graph is not connected\n");

    return 0;
}
