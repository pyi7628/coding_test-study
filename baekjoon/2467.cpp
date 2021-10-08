#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int n, num, ans1, ans2;
vector<int> a;
int min_num = 2000000000;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        a.push_back(num);
    }
    int s = 0, e = n - 1, cur;
    while (s < e)
    {
        cur = a[s] + a[e];
        if (abs(cur) < min_num)
        {
            min_num = abs(cur);
            ans1 = a[s], ans2 = a[e];
        }
        if (cur == 0)
            break;
        if (cur > 0)
            e--;
        else if (cur < 0)
            s++;
    }
    printf("%d %d", ans1, ans2);
    return 0;
}