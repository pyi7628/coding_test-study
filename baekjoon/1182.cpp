#include <cstdio>
using namespace std;
int n, s;
int nums[21];
bool check[21];
int cnt = 0;
void dfs(int cur, int sum)
{
    if (sum == s && cur != -1)
    {
        cnt++;
    }
    for (int i = cur + 1; i < n; i++)
    {
        check[i] = true;
        dfs(i, sum + nums[i]);
        check[i] = false;
    }
}
int main()
{
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    dfs(-1, 0);
    printf("%d", cnt);
    return 0;
}