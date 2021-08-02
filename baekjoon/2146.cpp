#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int init_cnt = 1;
bool init_check[100][100];
bool check[100][100];
int default_map[100][100];
int map[100][100];
int n;
int answer = 100000;
int cur_num = 0;
queue<pii> q;

void dfs(int row, int col, int cur_num, int from_num, int flag, int cnt)
{
    printf("flag: %d, cur_num: %d, from_num: %d, cnt: %d, answer: %d\n", flag, cur_num, from_num, cnt, answer);
    if (answer <= cnt)
        return;

    for (int k = 0; k < 4; k++)
    {
        if (dir[k][0] + row >= 0 && dir[k][1] + col >= 0 && dir[k][0] + row < n && dir[k][1] + col < n && check[dir[k][0] + row][dir[k][1] + col] == false)
        {
            int next_flag = flag;
            int next_from_num = from_num;
            if (flag == 0 && cur_num == 0 && map[dir[k][0] + row][dir[k][1] + col] != 0)
            {
                next_from_num = map[dir[k][0] + row][dir[k][1] + col];
            }
            if (flag == 0 && cur_num != 0 && map[dir[k][0] + row][dir[k][1] + col] == 0)
            {
                next_flag = 1;
                next_from_num = cur_num;
            }
            if (flag == 1 && cur_num == 0 && map[dir[k][0] + row][dir[k][1] + col] != 0)
            {
                next_flag = 0;
                next_from_num = map[dir[k][0] + row][dir[k][1] + col];
                if (from_num != map[dir[k][0] + row][dir[k][1] + col] && answer > cnt + 1)
                    answer = cnt + 1;
            }
            check[dir[k][0] + row][dir[k][1] + col] = true;
            dfs(dir[k][0] + row, dir[k][1] + col, next_from_num, map[dir[k][0] + row][dir[k][1] + col], next_flag, cnt + next_flag);
            check[dir[k][0] + row][dir[k][1] + col] = false;
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
            scanf("%d", &default_map[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (default_map[i][j] == 1 && init_check[i][j] == false)
            {
                q.push(make_pair(i, j));
                init_check[i][j] = true;
            }
            while (!q.empty())
            {
                pii cur = q.front();
                q.pop();
                map[cur.first][cur.second] = init_cnt;
                for (int k = 0; k < 4; k++)
                {
                    // 이런 if 문 좀 짧게 짜는 방법은 없을꺄
                    if (dir[k][0] + cur.first >= 0 && dir[k][1] + cur.second >= 0 && dir[k][0] + cur.first < n && dir[k][1] + cur.second < n && init_check[dir[k][0] + cur.first][dir[k][1] + cur.second] == false && default_map[dir[k][0] + cur.first][dir[k][1] + cur.second] == 1)
                    {
                        q.push(make_pair(dir[k][0] + cur.first, dir[k][1] + cur.second));
                        init_check[dir[k][0] + cur.first][dir[k][1] + cur.second] = true;
                    }
                }
                if (q.empty())
                    init_cnt++;
            }
        }
    }

    dfs(0, 0, map[0][0], 0, 0, 0);
    printf("%d", answer);
    return 0;
}