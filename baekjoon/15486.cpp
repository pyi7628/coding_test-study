#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1500001][2];
int dp[1500001];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &arr[i][0], &arr[i][1]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i + arr[i][0] > n)
            dp[i] = dp[i + 1];
        else
            dp[i] = max(dp[i + 1], dp[i + arr[i][0]] + arr[i][1]);
    }
    printf("%d", dp[0]);
    return 0;
}