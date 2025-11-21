#include <stdio.h>
#define N 5

struct Position
{
    int row;
    int col;
};

int maze[N][N] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}};

struct Position path[N * N];
int pathLen = 0;

int isSafe(int row, int col, int visited[N][N])
{
    return row >= 0 && row < N && col >= 0 && col < N && maze[row][col] == 0 && !visited[row][col];
}

int solveMaze(int row, int col, int visited[N][N])
{
    if (row == N - 1 && col == N - 1)
    {
        path[pathLen].row = row;
        path[pathLen].col = col;
        pathLen++;
        return 1;
    }
    if (!isSafe(row, col, visited))
        return 0;
    visited[row][col] = 1;
    path[pathLen].row = row;
    path[pathLen].col = col;
    pathLen++;
    if (solveMaze(row, col + 1, visited))
        return 1;
    if (solveMaze(row + 1, col, visited))
        return 1;
    if (solveMaze(row, col - 1, visited))
        return 1;
    if (solveMaze(row - 1, col, visited))
        return 1;
    pathLen--;
    visited[row][col] = 0;
    return 0;
}

int main()
{
    int visited[N][N] = {0};
    if (solveMaze(0, 0, visited))
    {
        printf("Path found! Coordinates visited:\n");
        for (int i = 0; i < pathLen; i++)
        {
            printf("(%d, %d) ", path[i].row, path[i].col);
        }
        printf("\n");
    }
    else
    {
        printf("No path exists.\n");
    }
    return 0;
}
