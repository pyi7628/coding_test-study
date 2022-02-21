#include <cstdio>
using namespace std;
int n, num;
int dp[12];
int main()
{
    scanf("%d", &n);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 11; i++)
    {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        printf("%d\n", dp[num]);
    }
    return 0;
}