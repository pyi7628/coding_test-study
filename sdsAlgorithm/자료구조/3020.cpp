#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int n, h, answer = 200000, cnt = 0;
vector<int> bt;
vector<int> tb;
int bt_sum[500000] = {
    0,
};
int tb_sum[500000] = {
    0,
};
int main()
{
    scanf("%d %d", &n, &h);
    for (int i = 0; i < n; i += 2)
    {
        int num;
        scanf("%d", &num);
        bt.push_back(num);
        scanf("%d", &num);
        tb.push_back(num);
    }
    for (int i = 0; i < n / 2; i++)
    {
        bt_sum[0]++;
        bt_sum[bt[i]]--;
        tb_sum[0]++;
        tb_sum[tb[i]]--;
    }
    for (int i = 1; i < h; i++)
    {
        bt_sum[i] = bt_sum[i - 1] + bt_sum[i];
        tb_sum[i] = tb_sum[i - 1] + tb_sum[i];
    }
    for (int i = 0; i < h; i++)
    {
        int crash = bt_sum[i] + tb_sum[h - i - 1];
        if (crash < answer)
        {
            cnt = 1;
            answer = crash;
        }
        else if (crash == answer)
            cnt++;
    }
    printf("%d %d", answer, cnt);
    return 0;
}