#include <cstdio>
#include <queue>
#include <string.h>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
queue<pii> q;
vector<pii> v;
int cur_cnt = 0, cur_sum = 0, n, l, r, flag = 1, answer = 0;
int map[101][101];
bool check[101][101];

int main()
{
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    while (flag)
    {
        memset(check, false, sizeof(check));
        flag = 0;
        answer += 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (!check[i][j])
                    q.push(make_pair(i, j)), v.clear(), cur_cnt = 0, cur_sum = 0;
                while (!q.empty())
                {
                    pii cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nr = cur.first + dir[k][0], nc = cur.second + dir[k][1];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && !check[nr][nc] && abs(map[nr][nc] - map[cur.first][cur.second]) >= l && abs(map[nr][nc] - map[cur.first][cur.second]) <= r)
                        {
                            flag = 1;
                            cur_cnt++;
                            cur_sum += map[nr][nc];
                            check[nr][nc] = true;
                            q.push(make_pair(nr, nc));
                            v.push_back(make_pair(nr, nc));
                        }
                    }
                }
                for (int k = 0; k < v.size(); k++)
                {
                    pii cur = v[k];
                    map[cur.first][cur.second] = cur_sum / cur_cnt;
                }
            }
    }
    printf("%d", answer - 1);

    return 0;
}