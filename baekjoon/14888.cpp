#include <cstdio>
using namespace std;

int n;
int nums[101];
int max_num = -1000000000, min_num = 1000000000;
int op[4];
int insert_op[11];
void back_tracking(int cnt)
{
    if (cnt == n - 1)
    {
        int cur = nums[0];
        for (int i = 0; i < n - 1; i++)
        {
            switch (insert_op[i])
            {
            case 0:
                cur += nums[i + 1];
                break;
            case 1:
                cur -= nums[i + 1];
                break;
            case 2:
                cur *= nums[i + 1];
                break;
            case 3:
                cur /= nums[i + 1];
                break;
            }
        }
        if (cur > max_num)
            max_num = cur;
        if (cur < min_num)
            min_num = cur;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (op[i])
        {
            op[i]--;
            insert_op[cnt] = i;
            back_tracking(cnt + 1);
            op[i]++;
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &op[i]);
    }
    back_tracking(0);
    printf("%d\n%d", max_num, min_num);
    return 0;
}