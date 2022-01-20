#include <cstdio>
using namespace std;
int t, n;
long long answer;
int cur_max = 1;
long long prefix_sum[1000001];
int main()
{
    scanf("%d", &t);
    prefix_sum[1] = 1;
    while (t--)
    {
        answer = 0;
        scanf("%d", &n);
        if (cur_max >= n)
            answer = prefix_sum[n];
        else
        {
            for (int i = cur_max; i <= n; i++)
            {
                if (i > cur_max)
                    cur_max = i;
                answer += (n / i) * i;
            }
        }
        printf("%lld\n", answer);
    }
    return 0;
}