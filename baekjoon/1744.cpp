#include <cstdio>
#include <queue>

#include <algorithm>
using namespace std;
int n;
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int> > mq;
int sum = 0;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        if (num <= 0)
            mq.push(num);
        else
            pq.push(num);
    }
    while (!mq.empty())
    {
        int n1 = mq.top();
        mq.pop();
        if (mq.empty())
        {
            sum += n1;
            break;
        }
        int n2 = mq.top();
        mq.pop();
        sum += n1 * n2;
    }
    while (!pq.empty())
    {
        int n1 = pq.top();
        pq.pop();
        if (pq.empty())
        {
            sum += n1;
            break;
        }
        int n2 = pq.top();
        pq.pop();
        if (n2 == 0 || n2 == 1)
        {
            sum += n1 + n2;
        }
        else
            sum += n1 * n2;
    }
    printf("%d", sum);
    return 0;
}