#include <cstdio>
#include <algorithm>
using namespace std;
int dp[501][501];
int input[501][501];
int n;
int top_down(int h, int i)
{
    if (h == n - 1)
        return input[h][i];
    if (dp[h][i] != 0)
        return dp[h][i];
    dp[h][i] = max(top_down(h + 1, i) + input[h][i], top_down(h + 1, i + 1) + input[h][i]);
    return dp[h][i];
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            scanf("%d", &input[i][j]);
        }
    }
    printf("%d", top_down(0, 0));
    return 0;
}