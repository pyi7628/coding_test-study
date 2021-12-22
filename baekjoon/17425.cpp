#include <cstdio>
using namespace std;
int t, n;
long long answer;
int cur_max = 0;
long long prefix_sum[1000001];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        answer = 0;
        scanf("%d", &n);
        if (cur_max >= n)
            answer = prefix_sum[n];
        for (int i = 1; i <= n; i++)
        {
            answer += (n / i) * i;
        }
        printf("%lld\n", answer);
    }
    return 0;
}