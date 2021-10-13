#include <cstdio>
using namespace std;
int n, m, answer = 0;
int map[501][501];
int temp[501][501];
int shape[7][4][2] = {
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 1}, {1, 0}, {2, 0}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}}};

void search(int r, int c)
{
    for (int i = 0; i < 7; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            if (r + shape[i][j][0] < n && c + shape[i][j][1] < m)
                sum += map[r + shape[i][j][0]][c + shape[i][j][1]];
            else
            {
                sum = 0;
                break;
            }
        }
        if (sum > answer)
            answer = sum;
    }
}
void rotate()
{
    int t;
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++)
            temp[j][n - i - 1] = map[i][j];

    t = n, n = m, m = t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            map[i][j] = temp[i][j];
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &map[i][j]);

    for (int cnt = 0; cnt < 4; cnt++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                search(i, j);
        rotate();
    }
    printf("%d", answer);
    return 0;
}