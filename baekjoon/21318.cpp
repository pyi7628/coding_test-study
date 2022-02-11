#include <cstdio>
using namespace std;
int n, m, s, e;
int nums[100001];
int sums[100001];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &nums[i]);
        if (nums[i] < nums[i - 1])
            sums[i - 1]++;
        sums[i] = sums[i - 1];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &s, &e);
        printf("%d\n", sums[e - 1] - sums[s - 1]);
    }

    return 0;
}