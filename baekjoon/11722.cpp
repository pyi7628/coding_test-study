#include <cstdio>
using namespace std;

int dp[1001];
int arr[1001];
int n, answer = 0;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        int max_num = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
                max_num = dp[j] > max_num ? dp[j] : max_num;
        }
        dp[i] = max_num + 1;
        answer = answer > dp[i] ? answer : dp[i];
    }
    printf("%d", answer);
    return 0;
}