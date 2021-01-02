#include <cstdio>
#include <vector>
using namespace std;
int n;
int nums[15];
vector<int> v;
void back_tracking(int cur)
{
    if (v.size() == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
        return;
    }
    if (v.size() > 6 || cur >= n)
        return;
    v.push_back(nums[cur]);
    back_tracking(cur + 1);
    v.pop_back();
    back_tracking(cur + 1);
}
int main()
{
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            return 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &nums[i]);
        }
        back_tracking(0);
        printf("\n");
    }
    return 0;
}