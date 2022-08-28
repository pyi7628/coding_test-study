#include <cstdio>
#include <queue>
using namespace std;

struct node
{
    int r;
    int c;
    int h;
    int d;
};
int map[101][101][101];
int check[101][101][101];
int dir[6][3] = {{1, 0, 0},
                 {-1, 0, 0},
                 {0, 1, 0},
                 {0, -1, 0},
                 {0, 0, 1},
                 {0, 0, -1}};
queue<node> q;

int n, m, h, total_cnt = 0, cnt = 0, day = -1;
node temp;
int main()
{
    scanf("%d%d%d", &m, &n, &h);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                scanf("%d", &map[j][k][i]);
                if (map[j][k][i] == 1)
                {
                    temp.r = j, temp.c = k, temp.h = i, temp.d = 0;
                    q.push(temp);
                    check[j][k][i] = 1;
                }
                else if (map[j][k][i] == 0)
                    total_cnt++;
            }
        }
    }

    while (!q.empty())
    {
        node cur = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int cr = cur.r + dir[i][0], cc = cur.c + dir[i][1], ch = cur.h + dir[i][2];
            if (cr >= 0 && cr < n && cc >= 0 && cc < m && ch >= 0 && ch < h && map[cr][cc][ch] == 0 && check[cr][cc][ch] == 0)
            {
                temp.r = cr, temp.c = cc, temp.h = ch, temp.d = cur.d + 1;
                q.push(temp);
                check[cr][cc][ch] = 1;
                cnt++;
                if (day < cur.d)
                    day = cur.d;
            }
        }
    }

    if (cnt == total_cnt)
    {
        printf("%d", day + 1);
    }
    else
        printf("-1");

    return 0;
}

