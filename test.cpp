#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
vector<int> a, b, c, d;
vector<int> ab, cd;
LL answer;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int n1, n2, n3, n4;
        scanf("%d%d%d%d", &n1, &n2, &n3, &n4);
        a.push_back(n1);
        b.push_back(n2);
        c.push_back(n3);
        d.push_back(n4);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    int ptr_e = cd.size() - 1;
    LL cnt = 0;
    for (int ptr_s = 0; ptr_s < ab.size(); ptr_s++)
    {
        int target = ab[ptr_s] * (-1);
        if (ptr_s > 0 && ab[ptr_s] == ab[ptr_s - 1])
        {
            answer += cnt;
        }
        else
        {
            cnt = 0;
            while (0 <= ptr_e && target < cd[ptr_e])
            {
                ptr_e--;
            }
            while (0 <= ptr_e && target == cd[ptr_e])
            {
                cnt++;
                ptr_e--;
            }
            answer += cnt;
        }
    }
    printf("%lld", answer);
    return 0;
}