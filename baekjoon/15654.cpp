#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> v;
vector<int> nums;
bool check[10];
void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < v.size(); i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
    }
    int i = 1;
    for (; i <= n; i++)
    {
        if (!check[i])
        {
            v.push_back(nums[i - 1]);
            check[i] = true;
            dfs(cnt + 1);
            check[i] = false;
            v.pop_back();
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    dfs(0);
    return 0;
}