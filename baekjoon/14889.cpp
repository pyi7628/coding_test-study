#include <cstdio>
#include <cmath>
using namespace std;
int map[21][21];
int n, answer = 10000;
int check[21];
int sum[2];
void back_tracking(int num, int cnt)
{
    if (cnt == n / 2)
    {
        sum[0] = 0, sum[1] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (check[i] == check[j])
                    sum[check[i]] += map[i][j];
            }
        }
        if (abs(sum[0] - sum[1]) < answer)
            answer = abs(sum[0] - sum[1]);
        return;
    }
    if (num == n)
        return;
    check[num] = 1;
    back_tracking(num + 1, cnt + 1);
    check[num] = 0;
    back_tracking(num + 1, cnt);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    back_tracking(0, 0);
    printf("%d", answer);
    return 0;
}