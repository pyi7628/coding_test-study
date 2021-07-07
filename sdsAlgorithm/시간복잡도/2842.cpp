// 이분탐색
// 투포인터
// bfs

// 낮은 높이 , 높은 높이를 임의로 정해서 모든 집에 배달 할 수 있는지 확인하고 싶다.
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, h[50][50], dy[10] = {1, -1, 0, 0, -1, -1, 1, 1}, dx[10] = {0, 0, -1, 1, -1, 1, -1, 1};
int cnt_k = 0, post_x, post_y;
char v[50][51]; // 문자열 받기 위해 뒤에 0까지 생각하여 +1
queue<pair<int, int> > q;

vector<int> h_group;
// 이거 대신에 현 low 보다 한단계 위 값 이런거 저장해줘도 좋을듯

int bfs(int low, int high)
{
    int res = 0;
    int check[50][50] = {
        0,
    };
    if (low <= h[post_y][post_x] && high >= h[post_y][post_x])
        q.push(make_pair(post_y, post_x)); // 우체국에서 시작
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        if (v[p.first][p.second] == 'K')
            res++;
        for (int i = 0; i < 8; i++)
        {
            if (check[p.first + dy[i]][p.second + dx[i]] == 0 && p.first + dy[i] >= 0 && p.first + dy[i] < n && p.second + dx[i] >= 0 && p.second + dx[i] < n && low <= h[p.first + dy[i]][p.second + dx[i]] && high >= h[p.first + dy[i]][p.second + dx[i]])
            {
                check[p.first + dy[i]][p.second + dx[i]] = 1;
                q.push(make_pair(p.first + dy[i], p.second + dx[i]));
            }
        }
    }
    return res;
}
int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf(" %c", &v[i][j]);
            if (v[i][j] == 'K')
                cnt_k++;
            if (v[i][j] == 'P')
                post_y = i, post_x = j;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &h[i][j]);
            h_group.push_back(h[i][j]);
        }
    }
    sort(h_group.begin(), h_group.end());
    int ans_low, ans_high;
    int answer = 1000000;
    for (int low = 0, high = 0; low <= high && low < h_group.size() && high < h_group.size();)
    {
        int cur = bfs(h_group[low], h_group[high]);
        if (cur == cnt_k)
        {
            if (h_group[high] - h_group[low] < answer)
                answer = h_group[high] - h_group[low];
            low++;
        }

        else
            high++;
    }
    printf("%d\n", answer);

    // low, high를 모두 탐색하기에는 시간이 너무 오래 걸리지 않을까..??
    // => 1. 이분탐색
    // => 2. 투포인터
    //

    return 0;
}