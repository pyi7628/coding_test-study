#include <cstdio>
using namespace std;
int n, k, answer = -10000001;
int arr[100002];
int sum[100002];
int main()
{
    int cnt = 0, cur;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &cur);
        arr[i] = cur;
        sum[i] += (sum[i - 1] + arr[i]);
        cnt++;
        if (k == cnt)
        {
            cnt--;
            sum[i] -= arr[i - k];
            if (answer < sum[i])
                answer = sum[i];
        }
    }
    printf("%d", answer);
    return 0;
}