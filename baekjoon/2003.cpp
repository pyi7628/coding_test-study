#include <cstdio>
using namespace std;
int n, m;
int nums[10001];
int cnt = 0;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    int s, e, sum = 0;
    for (s = 0, e = 0; e < n;)
    {

        sum += nums[e];
        while (sum > m)
        {
            sum -= nums[s];
            s++;
        }
        if (sum == m)
        {
            cnt++;
        }
        e++;
    }
    printf("%d", cnt);
    return 0;
}