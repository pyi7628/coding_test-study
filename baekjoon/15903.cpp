#include <cstdio>
#include <queue>
using namespace std;
priority_queue<long long> pq;
int n, m, num;
long long sum = 0;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        pq.push(-num);
    }
    for (int i = 0; i < m; i++)
    {
        long long s1 = -pq.top();
        pq.pop();
        long long s2 = -pq.top();
        pq.pop();
        s1 += s2;
        pq.push(-s1);
        pq.push(-s1);
    }
    while (!pq.empty())
    {
        sum -= pq.top();
        pq.pop();
    }

    printf("%lld", sum);
    return 0;
}