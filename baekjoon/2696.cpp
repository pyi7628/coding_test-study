#include <cstdio>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > min_pq;
priority_queue<int> max_pq;
int t, m, num, min_swap, max_swap;
int main()
{
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &m);
        printf("%d\n", (m + 1) / 2);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &num);
            if (min_pq.empty())
                min_pq.push(num);
            else if (min_pq.top() <= num)
            {
                if (min_pq.size() > max_pq.size())
                {
                    max_pq.push(min_pq.top());
                    min_pq.pop();
                }
                min_pq.push(num);
            }
            else
            {
                if (min_pq.size() < max_pq.size())
                {
                    min_pq.push(max_pq.top());
                    max_pq.pop();
                }
                max_pq.push(num);
            }

            if (!min_pq.empty() && !max_pq.empty() && min_pq.top() < max_pq.top())
            {
                min_swap = min_pq.top();
                max_swap = max_pq.top();
                min_pq.pop();
                max_pq.pop();
                min_pq.push(max_swap);
                max_pq.push(min_swap);
            }
            if (j % 2 == 0)
                printf("%d ", min_pq.size() > max_pq.size() ? min_pq.top() : max_pq.top());
        }
        printf("\n");
        while (!min_pq.empty())
            min_pq.pop();
        while (!max_pq.empty())
            max_pq.pop();
    }

    return 0;
}