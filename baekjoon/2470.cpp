#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int n, num, ans1, ans2, cur_sum = 2000000001;
vector<int> v;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int s = 0, e = n - 1, cur;
    while (s < e)
    {
        cur = v[s] + v[e];
        if (abs(cur) < cur_sum)
        {
            cur_sum = abs(cur);
            ans1 = v[s];
            ans2 = v[e];
        }
        if (cur < 0)
            s++;
        else if (cur > 0)
            e--;
        else if (cur == 0)
        {
            ans1 = v[s];
            ans2 = v[e];
            break;
        }
    }
    printf("%d %d", ans1, ans2);
    return 0;
}