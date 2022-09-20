#include <cstdio>
#include <vector>
#include <queue>

#define CNT_MAX 10000000

using namespace std;
struct node
{
    int r;
    int c;
    int d;
    int is_broken;
};

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

queue<node> q;

char map[1001][1001];
bool check[1001][1001][2];
int n, m, min_cnt = CNT_MAX;
node temp;

void bfs()
{
    while (!q.empty())
    {
        node cur = q.front();
        q.pop();
        if (cur.d >= min_cnt)
            return;
        if (cur.r == n - 1 && cur.c == m - 1)
        {
            if (cur.d < min_cnt)
                min_cnt = cur.d;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = dir[i][0] + cur.r, nc = dir[i][1] + cur.c;
            int check_type = cur.is_broken;
            if (nr < n && nr >= 0 && nc < m && nc >= 0 && !check[nr][nc][check_type] && map[nr][nc] == '0')
            {
                check[nr][nc][check_type] = true;
                temp.r = nr, temp.c = nc, temp.d = cur.d + 1, temp.is_broken = cur.is_broken;
                q.push(temp);
            }
            if (nr < n && nr >= 0 && nc < m && nc >= 0 && !check[nr][nc][1] && map[nr][nc] == '1' && !cur.is_broken)
            {
                check[nr][nc][1] = true;
                temp.r = nr, temp.c = nc, temp.d = cur.d + 1, temp.is_broken = 1;
                q.push(temp);
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
            scanf(" %c", &map[i][j]);
        }
    }

    temp.r = 0, temp.c = 0, temp.d = 1, temp.is_broken = 0;
    q.push(temp);
    bfs();

    printf("%d", min_cnt == CNT_MAX ? -1 : min_cnt);

    return 0;
}

/*
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>

#define CNT_MAX 1000001

using namespace std;
struct node
{
    int r;
    int c;
    int d;
};

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<pair<int, int> > wall_list;
queue<node> q;

char map[1001][1001];
bool check[1001][1001];
int n, m, min_cnt = CNT_MAX;
node temp;

void init_check()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            check[i][j] = false;
        }
    }
}

void bfs()
{
    while (!q.empty())
    {
        node cur = q.front();
        q.pop();
        if (cur.d >= min_cnt)
            return;
        if (cur.r == n - 1 && cur.c == m - 1 && cur.d < min_cnt)
        {
            min_cnt = cur.d;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = dir[i][0] + cur.r, nc = dir[i][1] + cur.c;
            if (nr < n && nr >= 0 && nc < m && nc >= 0 && !check[nr][nc] && map[nr][nc] == '0')
            {
                check[nr][nc] = true;
                temp.r = nr, temp.c = nc, temp.d = cur.d + 1;
                q.push(temp);
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
            scanf(" %c", &map[i][j]);
            if (map[i][j] == '1')
            {
                wall_list.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < wall_list.size(); i++)
    {
        map[wall_list[i].first][wall_list[i].second] = '0';
        //init_check();
        memset(check, 0, sizeof(check));
        temp.r = 0, temp.c = 0, temp.d = 1;
        q.push(temp);
        bfs();
        map[wall_list[i].first][wall_list[i].second] = '1';
    }
    printf("%d", min_cnt == CNT_MAX ? -1 : min_cnt);
}

*/