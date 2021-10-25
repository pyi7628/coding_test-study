#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int n;
int ans[2];
int map[11][11];
bool check[11][11];
vector<pii> v;
bool pruning(int r, int c)
{
    if (!map[r][c] || check[r][c])
        return false;
    for (int i = 0; i < v.size(); i++)
    {
        if (abs(v[i].second - c) == abs(v[i].first - r))
            return false;
    }
    return true;
}

void back_tracking(int idx, int cnt, int color)
{

    if (idx >= n * n)
    {
        if (cnt > ans[color])
            ans[color] = cnt;
        return;
    }
    int next = idx + 2; // 왜 전역으로 빼면 틀리지?
    if (n % 2 == 0 && ((idx + 1) / n) % 2 != (idx / n) % 2)
        next = idx + 1;
    else if (n % 2 == 0 && ((idx + 2) / n) % 2 != ((idx + 1) / n) % 2)
        next = idx + 3;
    int i = idx / n, j = idx % n;

    if (pruning(i, j))
    {
        check[i][j] = true;
        v.push_back(make_pair(i, j));
        back_tracking(next, cnt + 1, color);
        check[i][j] = false;
        v.pop_back();
    }
    back_tracking(next, cnt, color);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    back_tracking(0, 0, 0);
    back_tracking(1, 0, 1);
    printf("%d", ans[0] + ans[1]);
    return 0;
}