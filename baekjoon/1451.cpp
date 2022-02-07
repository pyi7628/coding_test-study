#include <cstdio>
#include <vector>
using namespace std;
int n, m;
int nums[51][51];
int sum[51][51];
vector<int> v;
int point[3][2];
void back_tracking(int cnt, int prev)
{

    if (cnt == 3)
    {
        if (v.back() == n * m - 1)
        {
            int sel_cnt = 0, row, col;
            for (int i = 0; i < v.size(); i++)
            {
                row = v[i]
            }
        }
        return;
    }
    for (int i = prev + 1; i < n * m; i++)
    { //걍 cnt 2일때 무조건 마지막꺼 넣어도 될듯
        v.push_back(i);
        back_tracking(cnt + 1, i);
        v.pop_back();
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", nums[i][j]);
            // sum[i][j] = (i == 0 ? 0 : sum[i - 1][j]) + (j == 0 ? 0 : sum[i][j - 1]) - ((i != 0 && j != 0 ? sum[i - 1][j - 1] : 0));
        }
    }

    return 0;
}