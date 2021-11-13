#include <cstdio>
using namespace std;
int n;
int map[130][130];
int cnt[2];

void div(int sr, int sc, int size)
{
    int f = map[sr][sc];
    bool flag = 0;
    if (size == 1)
    {
        cnt[f]++;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (f != map[sr + i][sc + j])
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 0)
    {
        cnt[f]++;
        return;
    }

    div(sr, sc, size / 2);
    div(sr + size / 2, sc, size / 2);
    div(sr, sc + size / 2, size / 2);
    div(sr + size / 2, sc + size / 2, size / 2);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    div(0, 0, n);
    printf("%d\n%d", cnt[0], cnt[1]);

    return 0;
}