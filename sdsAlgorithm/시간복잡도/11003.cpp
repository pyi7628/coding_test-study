#include <cstdio>
#include <deque>
using namespace std;
int main()
{
    int n, l;
    deque<pair<int, int> > q; // val, idx
    scanf("%d%d", &n, &l);
    for (int i = 0; i < n; i++)
    {
        int cur;
        scanf("%d", &cur);
        while (!q.empty())
        {
            pair<int, int> p = q.back();
            if (cur <= p.first)
            {
                q.pop_back();
            }
            else
                break;
        }
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            if (i - l >= p.second)
            {
                q.pop_front();
            }
            else
                break;
        }
        q.push_back(make_pair(cur, i));
        printf("%d ", q.front().first);
    }
    return 0;
}