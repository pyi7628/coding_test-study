#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, num;
bool check[10001];
vector<int> nums;
vector<int> answer;
void back_tracking(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < answer.size(); i++)
        {
            printf("%d ", answer[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        answer.push_back(nums[i]);
        back_tracking(cnt + 1);
        answer.pop_back();
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if (!check[num])
        {
            check[num] = true;
            nums.push_back(num);
        }
    }
    sort(nums.begin(), nums.end());
    back_tracking(0);
    return 0;
}