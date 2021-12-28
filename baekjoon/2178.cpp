#include <cstdio>
#include <queue>
using namespace std;
struct node
{
    int r;
    int c;
    int cnt;
};

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, answer = 0;
int map[101][101];
int check[101][101];
char input;
queue<node> q;
node temp;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &input);
            map[i][j] = input - '0';
        }
    }
    temp.r = 0, temp.c = 0, temp.cnt = 1;
    q.push(temp);
    while (!q.empty())
    {
        node cur = q.front();
        q.pop();
        if (cur.r == n - 1 && cur.c == m - 1)
        {
            printf("%d", cur.cnt);
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nc = cur.c + dir[i][1], nr = cur.r + dir[i][0];
            if (nc >= 0 && nr >= 0 && nc < m && nr < n && !check[nr][nc] && map[nr][nc])
            {
                check[nr][nc] = 1;
                temp.r = nr, temp.c = nc, temp.cnt = cur.cnt + 1;
                q.push(temp);
            }
        }
    }
    return 0;
}