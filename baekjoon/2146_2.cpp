#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
struct node
{
    int st;
    int r;
    int c;
    int cnt;
};
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n;
int map[101][101];
bool init_check[101][101];
int search_check[101][101];
queue<pii> q;
queue<node> sq;
int c, r, nc, nr, st, cnt;
node temp;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);

    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!init_check[i][j] && map[i][j] == 1)
                q.push(make_pair(i, j)), init_check[i][j] = true, idx++;

            while (!q.empty())
            {
                r = q.front().first, c = q.front().second;
                q.pop();
                map[r][c] = idx;
                temp.st = idx, temp.r = r, temp.c = c, temp.cnt = 0;
                sq.push(temp);
                search_check[r][c] = st;
                for (int i = 0; i < 4; i++)
                {
                    nr = dir[i][0] + r, nc = dir[i][1] + c;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && !init_check[nr][nc] && map[nr][nc] != 0)
                    {
                        q.push(make_pair(nr, nc));
                        init_check[nr][nc] = true;
                    }
                }
            }
        }
    }

    while (!sq.empty())
    {
        r = sq.front().r, c = sq.front().c, st = sq.front().st, cnt = sq.front().cnt;
        sq.pop();
        for (int i = 0; i < 4; i++)
        {
            nr = dir[i][0] + r, nc = dir[i][1] + c;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n)
            {
                if (map[nr][nc] != 0 && map[nr][nc] != st)
                {
                    printf("%d", cnt);
                    return 0;
                }
                else if (search_check[nr][nc] != st && map[nr][nc] == 0)
                {
                    temp.st = st, temp.r = nr, temp.c = nc, temp.cnt = cnt + 1;
                    sq.push(temp);
                    search_check[nr][nc] = st;
                }
            }
        }
    }
    return 0;
}