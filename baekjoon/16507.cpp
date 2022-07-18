#include <cstdio>
using namespace std;

int pic[1001][1001];
int picsum[1001][1001];
int r, c, q, r1, c1, r2, c2;
int main()
{

    scanf("%d%d%d", &r, &c, &q);
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            scanf("%d", &pic[i][j]);
            picsum[i][j] = pic[i][j] + picsum[i - 1][j] + picsum[i][j - 1] - picsum[i - 1][j - 1];
        }
    }
    while (q--)
    {
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        printf("%d\n", (picsum[r2][c2] - picsum[r1 - 1][c2] - picsum[r2][c1 - 1] + picsum[r1 - 1][c1 - 1]) / ((r2 - r1 + 1) * (c2 - c1 + 1)));
    }
    return 0;
}