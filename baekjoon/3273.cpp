#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, x, num, cnt = 0;
vector<int> v;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        v.push_back(num);
    }
    scanf("%d", &x);
    sort(v.begin(), v.end());
    int s = 0, e = n - 1;
    while (s < e)
    {
        int cur = v[s] + v[e];
        if (cur > x)
            e--;
        else if (cur == x)
            s++, e--, cnt++;
        else
            s++;
    }
    printf("%d", cnt);
    return 0;
}