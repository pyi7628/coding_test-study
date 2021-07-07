#include <cstdio>
#include <vector>
using namespace std;

int answer;
int n, m;
long long v[1000000];
long long get_sum(int mid)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long temp = v[i] - mid;
        if (temp > 0)
        {
            if (sum + temp > 2000000000)
                sum = 2000000001;
            else
                sum += temp;
        }
    }
    return sum;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%lld", &v[i]);

    int start = 0, end = 1000000000;
    while (end >= start)
    {
        int mid = (start + end) / 2;
        long long sum = get_sum(mid);
        if (sum > m)
        {
            start = mid + 1;
            answer = mid;
        }
        else if (sum < m)
            end = mid - 1;
        else if (sum == m)
        {
            answer = mid;
            break;
        }
    }

    printf("%d", answer);
    return 0;
}