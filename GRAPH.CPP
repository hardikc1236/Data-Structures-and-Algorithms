#include <stdio.h>
#include <conio.h>

int adj[10][10], visited[10], temp[10], n;
char name[10][20];

void dfs(int v)
{
    int i;
    visited[v] = 1;
    printf("%-15s %d C\n", name[v], temp[v]);
    for (i = 0; i < n; i++)
        if (adj[v][i] == 1 && visited[i] == 0)
            dfs(i);
}

void main()
{
    int i, e, a, b, start;

    clrscr();
    printf("Number of stations (max 10): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Station %d name: ", i);
        scanf("%s", name[i]);
        printf("Temperature: ");
        scanf("%d", &temp[i]);
    }

    printf("Number of connections: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++) {
        printf("Connected stations (0 to %d): ", n - 1);
        scanf("%d %d", &a, &b);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    printf("Start station: ");
    scanf("%d", &start);

    printf("\nDFS traversal:\n");
    dfs(start);
    getch();
}