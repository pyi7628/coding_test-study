#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, num;
vector<int> v;
vector<int> cur;
void back_tracking(int cnt, int idx)
{
    if (cnt == m)
    {
        for (int i = 0; i < cur.size(); i++)
        {
            printf("%d ", cur[i]);
        }
        printf("\n");
        return;
    }
    for (int i = idx; i < n; i++)
    {

        cur.push_back(v[i]);
        back_tracking(cnt + 1, i);
        cur.pop_back();
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    back_tracking(0, 0);
    return 0;
}