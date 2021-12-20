#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, c_cnt = 0, t_cnt = 0;
int map[101][101];
int check[101][101];
void dfs(int row, int col)
{
    for (int i = 0; i < 4; i++)
    {
        if (row + dir[i][0] >= 0 && row + dir[i][0] < n && col + dir[i][1] >= 0 && col + dir[i][1] < m && check[row + dir[i][0]][col + dir[i][1]] != -1 && map[row + dir[i][0]][col + dir[i][1]] == 1)
        {
            check[row + dir[i][0]][col + dir[i][1]]++;
            if (check[row + dir[i][0]][col + dir[i][1]] >= 2)
            {
                check[row + dir[i][0]][col + dir[i][1]] = -1;
                map[row + dir[i][0]][col + dir[i][1]] = 0;
                c_cnt++;
            }
        }
        if (row + dir[i][0] >= 0 && row + dir[i][0] < n && col + dir[i][1] >= 0 && col + dir[i][1] < m && check[row + dir[i][0]][col + dir[i][1]] == 0 && map[row + dir[i][0]][col + dir[i][1]] == 0)
        {
            check[row + dir[i][0]][col + dir[i][1]] = 1;
            dfs(row + dir[i][0], col + dir[i][1]);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j])
                t_cnt++;
        }
    }
    int cnt = 0;
    while (c_cnt != t_cnt)
    {
        cnt++;
        dfs(0, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                check[i][j] = 0;
    }
    printf("%d", cnt);

    return 0;
}