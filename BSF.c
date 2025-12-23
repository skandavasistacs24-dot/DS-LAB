#include <stdio.h>

int G[20][20], visited[20], q[20];
int n, front = 0, rear = -1;

void bfs(int start)
{
    int i, curr;
    q[++rear] = start;
    visited[start] = 1;

    while (front <= rear)
    {
        curr = q[front++];
        printf("%d ", curr);

        for (i = 0; i < n; i++)
        {
            if (G[curr][i] == 1 && visited[i] == 0)
            {
                q[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int edges, u, v, start, i;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &edges);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter edges (u v):\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1;
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
