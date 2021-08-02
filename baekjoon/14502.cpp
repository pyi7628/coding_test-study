#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int n, m, wall;
int arr[10][10];
bool check[10][10];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<pii> vi;
queue<pii> q;
int answer = 0;
void bfs()
{
    int cnt = 0;
    bool b_check[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            b_check[i][j] = false;
        }
    }
    for (int i = 0; i < vi.size(); i++)
    {
        q.push(vi[i]);
    }
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (cur.first + dir[i][0] >= 0 && cur.first + dir[i][0] < n && cur.second + dir[i][1] >= 0 && cur.second + dir[i][1] < m && check[cur.first + dir[i][0]][cur.second + dir[i][1]] == false && b_check[cur.first + dir[i][0]][cur.second + dir[i][1]] == false && arr[cur.first + dir[i][0]][cur.second + dir[i][1]] == 0)
            {
                b_check[cur.first + dir[i][0]][cur.second + dir[i][1]] = true;
                q.push(make_pair(cur.first + dir[i][0], cur.second + dir[i][1]));
                cnt++;
            }
        }
    }
    // printf("test wall: %d cnt: %d\n", wall, cnt);
    if (answer < n * m - wall - cnt)
        answer = n * m - wall - cnt;
}
void dfs(int cnt)
{
    if (cnt == 3)
    {
        bfs();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check[i][j] == false)
            {
                check[i][j] = true;
                dfs(cnt + 1);
                check[i][j] = false;
            }
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
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 2)
                wall++, vi.push_back(make_pair(i, j));
            else if (arr[i][j] == 1)
                wall++;
        }
    }
    dfs(0);

    printf("%d", answer - 3);

    return 0;
}