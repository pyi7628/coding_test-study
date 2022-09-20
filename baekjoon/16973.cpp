#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

struct node
{
    int r;
    int c;
    int d;
};

int dir[4][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}};

int n,
    m, h, w, sr, sc, fr, fc;
int answer = -1;

int map[1001][1001];
int check[1001][1001];
int sum[1001][1001];

queue<node> q;
node temp;

bool check_size(int r, int c)
{
    return h * w == sum[r][c] - (r - h >= 0 ? sum[r - h][c] : 0) - (c - w >= 0 ? sum[r][c - w] : 0) + (r - h >= 0 && c - w >= 0 ? sum[r - h][c - w] : 0);
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1)
            {
                sum[i][j] -= 1;
            }
            sum[i][j] += (i != 0 ? sum[i - 1][j] : 0) + (j != 0 ? sum[i][j - 1] : 0) +
                         1;
            if (i > 0 && j > 0)
            {
                sum[i][j] -= sum[i - 1][j - 1];
            }
        }
    }
    scanf("%d %d %d %d %d %d", &h, &w, &sr, &sc, &fr, &fc);
    dir[0][2] = w, dir[1][2] = -w, dir[2][2] = h, dir[3][2] = -h;
    temp.r = sr - 1, temp.c = sc - 1, temp.d = 0;
    q.push(temp);

    while (!q.empty())
    {
        node cur = q.front();
        q.pop();

        if (cur.r == fr - 1 && cur.c == fc - 1)
        {
            answer = cur.d;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = cur.r + dir[i][0], nc = cur.c + dir[i][1];

            if (nr + h - 1 < n && nr >= 0 && nc + w - 1 < m && nc >= 0 && !check[nr][nc] && check_size(nr + h - 1, nc + w - 1))
            {
                temp.r = nr, temp.c = nc, temp.d = cur.d + 1;
                q.push(temp);
                check[nr][nc] = 1;
            }
        }
    }

    printf("%d", answer);

    return 0;
}