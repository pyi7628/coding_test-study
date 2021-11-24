#include <cstdio>
using namespace std;
int t, n;
long long answer = 0;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        answer += (n / i) * i;
    }
    printf("%lld\n", answer);
    return 0;
}