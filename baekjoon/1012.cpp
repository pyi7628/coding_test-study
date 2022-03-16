#include <cstdio>
#include <queue>
using namespace std;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int map[51][51];
bool check[51][51];
queue<pair<int, int> > q;
int t, m, n, k, c, r, answer = 0;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                map[i][j] = 0;
                check[i][j] = false;
            }
        }
        answer = 0;

        scanf("%d%d%d", &m, &n, &k);
        for (int i = 0; i < k; i++)
        {
            scanf("%d%d", &c, &r);
            map[r][c] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] && !check[i][j])
                    q.push(make_pair(i, j)), check[i][j] = true, answer++;
                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int x = 0; x < 4; x++)
                    {
                        int nr = cur.first + dir[x][0], nc = cur.second + dir[x][1];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < m && !check[nr][nc] && map[nr][nc])
                        {
                            q.push(make_pair(nr, nc)), check[nr][nc] = true;
                        }
                    }
                }
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}