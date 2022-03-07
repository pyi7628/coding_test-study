#include <cstdio>
#include <queue>
using namespace std;
struct node
{
    int r;
    int c;
    int v;
};
typedef pair<int, int> pii;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char map[101][101];
int check[101][101];
int n;
int ans[2];
queue<pii> q;
void bfs(int type, char val)
{
    pii cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = cur.first + dir[i][0], nc = cur.second + dir[i][1];
            if (nr >= 0 && nc >= 0 && nr < n && nc < n && !check[nr][nc] && (map[nr][nc] == val || (type && val != 'B' && map[nr][nc] != 'B')))
            {
                check[nr][nc] = 1;
                q.push(make_pair(nr, nc));
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf(" %c", &map[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!check[i][j])
            {
                q.push(make_pair(i, j));
                bfs(0, map[i][j]);
                ans[0]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            check[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!check[i][j])
            {
                q.push(make_pair(i, j));
                bfs(1, map[i][j]);
                ans[1]++;
            }
        }
    }
    printf("%d %d", ans[0], ans[1]);
    return 0;
}