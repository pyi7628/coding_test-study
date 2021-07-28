#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n;
long long sum = 0;
priority_queue<int, vector<int>, greater<int> > pq;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        pq.push(num);
    }
    if (pq.size() == 1)
    {
        printf("0");
        return 0;
    }
    while (!pq.empty())
    {
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();
        sum += n1 + n2;
        if (!pq.empty())
            pq.push(n1 + n2);
    }
    printf("%lld", sum);
    return 0;
}