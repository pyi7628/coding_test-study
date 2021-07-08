#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int> max_pq;                             // 더 작은 값
priority_queue<int, vector<int>, greater<int> > min_pq; // 더 큰 값
int n;
int answer = 0;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        if (min_pq.size() == max_pq.size())
            max_pq.push(num);
        else
        {
            min_pq.push(num);
        }
        if (!min_pq.empty() && !max_pq.empty() && min_pq.top() < max_pq.top())
        {
            int temp1 = min_pq.top();
            min_pq.pop();
            int temp2 = max_pq.top();
            max_pq.pop();
            min_pq.push(temp2);
            max_pq.push(temp1);
        }
        printf("%d\n", max_pq.top());
    }
    return 0;
}