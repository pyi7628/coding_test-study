#include <cstdio>
#include <algorithm>
using namespace std;
int answer = 100000;
int c, n, flag = 1;
int sum[1001];
int val[20][2];
int dp(int left)
{
    int cur_min = 100000;
    if (left <= 0)
    {
        return 0;
    }
    if (sum[left])
        return sum[left];
    for (int i = 0; i < n; i++)
    {
        cur_min = min(cur_min, dp(left - val[i][1]) + val[i][0]);
    }
    sum[left] = cur_min;
    return cur_min;
}
int main()
{
    scanf("%d%d", &c, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &val[i][0], &val[i][1]);
    }
    answer = dp(c);
    printf("%d", answer);
    return 0;
}