#include <cstdio>
using namespace std;
int dp[1002][10];
int n, answer = 0;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n + 1; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j < 10; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
        }
    }
    printf("%d", dp[n + 1][9]);
    return 0;
}