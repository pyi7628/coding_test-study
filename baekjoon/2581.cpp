#include <cstdio>
using namespace std;
int m, n, min_num = -1, sum = 0;
bool prime[10001];
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 2; i <= 5000; i++)
    {
        for (int j = 2; i * j <= 10000; j++)
        {
            prime[i * j] = true;
        }
    }
    prime[1] = true;
    for (int i = m; i <= n; i++)
    {
        if (!prime[i])
        {
            sum += i;
            if (min_num == -1)
                min_num = i;
        }
    }
    if (min_num == -1)
        printf("-1");
    else
        printf("%d\n%d", sum, min_num);
    return 0;
}