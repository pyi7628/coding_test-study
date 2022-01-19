#include <cstdio>
#include <queue>
using namespace std;
int n, num;
priority_queue<int> pq;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if (num == 0)
        {
            if (pq.empty())
                printf("0\n");
            else
            {
                printf("%d\n", -pq.top());
                pq.pop();
            }
        }
        else
            pq.push(-num);
    }
    return 0;
}