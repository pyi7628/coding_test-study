#include <cstdio>
#include <cmath>
using namespace std;
int n, m, answer = 0;
int nums[5][5];
bool check[5][5];
int visited[5][5];
char str[10];
int calc_sum(int r1, int r2, int c1, int c2)
{
    int sum = 0;
    if (r1 != r2)
        for (int i = r1; i <= r2; i++)
            sum += pow(10, r2 - i) * nums[i][c1];

    else
        for (int i = c1; i <= c2; i++)
            sum += pow(10, c2 - i) * nums[r1][i];
    return sum;
}
void toggle_check(int r1, int r2, int c1, int c2)
{
    int sum = 0;
    if (r1 != r2)
        for (int i = r1; i <= r2; i++)
            check[i][c1] = !check[i][c1];

    else
        for (int i = c1; i <= c2; i++)
            check[r1][i] = !check[r1][i];
}
void tracking(int sum, int cnt)
{
    if (cnt == m * n)
    {
        if (answer < sum)
            answer = sum;
        return;
    }

    int i = cnt / m, j = cnt % m;
    if (check[i][j])
        tracking(sum, cnt + 1);
    else
    {
        check[i][j] = true;
        tracking(sum + nums[i][j], cnt + 1);
        check[i][j] = false;
        int cur_sum = 0;
        for (int k = 1; i + k < n; k++)
        {
            if (!check[i + k][j])
            {
                toggle_check(i, i + k, j, j);
                cur_sum = calc_sum(i, i + k, j, j);
                tracking(sum + cur_sum, cnt + 1);
                toggle_check(i, i + k, j, j);
            }
            else
                break;
        }
        for (int k = 1; j + k < m; k++)
        {
            if (!check[i][j + k])
            {
                toggle_check(i, i, j, j + k);
                cur_sum = calc_sum(i, i, j, j + k);
                tracking(sum + cur_sum, cnt + 1);
                toggle_check(i, i, j, j + k);
            }
            else
                break;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        for (int j = 0; j < m; j++)
            nums[i][j] = str[j] - '0';
    }

    tracking(0, 0);
    printf("%d", answer);
    return 0;
}