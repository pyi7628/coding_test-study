#include <cstdio>
#include <algorithm>
using namespace std;
int dp[100001][101];
int p[101][2];
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &p[i][0], &p[i][1]);
    }
    for (int i = 1; i <= n; i++) // 몇번째꺼 까지 봤는가
    {
        for (int j = 1; j <= k; j++) // 무게
        {
            if (p[i][0] <= j)
            {
                dp[j][i] = max(dp[j][i - 1], dp[j - p[i][0]][i - 1] + p[i][1]);
            }
            else
                dp[j][i] = dp[j][i - 1];
        }
    }
    printf("%d", dp[k][n]);
}