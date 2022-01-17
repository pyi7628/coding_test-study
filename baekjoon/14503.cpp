#include <cstdio>
#include <stdlib.h>
using namespace std;
int n, m, r, c, d;
int answer = 0;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int map[51][51];
int check[51][51];
void dfs(int row, int col, int direction)
{
    if (!check[row][col])
    {
        check[row][col] = 1;
        answer++;
    }
    for (int i = 0; i < 4; i++)
    {
        int cur_dir = (direction + 3 - i) % 4;
        int nr = row + dir[cur_dir][0], nc = col + dir[cur_dir][1];
        if (!map[nr][nc] && !check[nr][nc])
            dfs(nr, nc, cur_dir);
    }

    int backd = direction + 2 >= 4 ? direction - 2 : direction + 2;
    int backr = row + dir[backd][0], backc = col + dir[backd][1];

    if (!map[backr][backc])
        dfs(backr, backc, direction);
    else
    {
        printf("%d", answer);
        exit(0);
    }
}
int main()
{
    scanf("%d%d%d%d%d", &n, &m, &r, &c, &d);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &map[i][j]);
    dfs(r, c, d);
    return 0;
}