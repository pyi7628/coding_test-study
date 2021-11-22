#include <cstdio>
using namespace std;
int map[2500][2500];
int n, num;
int cnt[4];
void div(int r, int c, int size)
{
    int cur = map[r][c];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (map[r + i][c + j] != cur)
            {
                for (int k = 0; k < 3; k++)
                {
                    div(r + (size / 3) * k, c, size / 3);
                    div(r + (size / 3) * k, c + (size / 3), size / 3);
                    div(r + (size / 3) * k, c + (size / 3) * 2, size / 3);
                }
                return;
            }
        }
    }
    cnt[cur]++;
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == -1)
                map[i][j] = 2;
        }
    }
    div(0, 0, n);
    printf("%d\n%d\n%d", cnt[2], cnt[0], cnt[1]);

    return 0;
}