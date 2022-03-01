#include <cstdio>
using namespace std;
int t, n;
long long sum[1000001];
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= 1000000; i++)
    {
        for (int j = i; j <= 1000000; j += i)
        {
            sum[j] += i;
        }
        sum[i] += sum[i - 1];
    }
    while (t--)
    {
        scanf("%d", &n);
        printf("%lld\n", sum[n]);
    }

    return 0;
}