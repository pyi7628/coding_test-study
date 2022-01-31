#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
vector<pii> s;
int n, q, a, b, u, v, x, y;
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        s.push_back(make_pair(a, b));
    }
    sort(s.begin(), s.end());
    int lower, upper;
    while (q--)
    {
        int cnt = 0;
        scanf("%d%d%d%d", &u, &v, &x, &y);
        int left = 0, right = n - 1, mid;
        lower = left;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (s[mid].first == u)
            {
                lower = mid;
                break;
            }
            else if (s[mid].first < u)
                left = mid + 1;

            else
            {
                lower = mid;
                right = mid - 1;
            }
        }
        left = 0, right = n - 1;
        upper = right + 1;
        while (left <= right)
        {
            mid = (left + right) / 2;

            if (s[mid].first == v)
            {
                upper = mid + 1;
                break;
            }
            else if (s[mid].first < v)
                left = mid + 1;

            else
            {
                upper = mid;
                right = mid - 1;
            }
        }
        for (int i = lower; i < upper; i++)
        {
            if (s[i].second >= x && s[i].second <= y)
                cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}