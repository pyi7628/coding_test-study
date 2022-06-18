#include <cstdio>
using namespace std;

int map[51][51];
char c;
int n, m, answer = 3000;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &c);
            if (c == 'W')
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }
    }
    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            int cur = 0, cnt = 0;
            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x++)
                {
                    if (map[i + y][j + x] != cur)
                        cnt++;
                    cur = !cur;
                }
                cur = !cur;
            }
            if (answer > cnt)
                answer = cnt;

            cur = 1, cnt = 0;
            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x++)
                {
                    if (map[i + y][j + x] != cur)
                        cnt++;
                    cur = !cur;
                }
                cur = !cur;
            }
            if (answer > cnt)
                answer = cnt;
        }
    }

    printf("%d", answer);

    return 0;
}