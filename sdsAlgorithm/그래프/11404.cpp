//플로이드 알고리즘
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 10000000
int g[101][101];
int n, m;
int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            g[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = c < g[a][b] ? c : g[a][b];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (g[j][i] != INF && g[i][k] != INF)
                    g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j] == INF || i == j)
                printf("0 ");
            else
                printf("%d ", g[i][j]);
        }
        printf("\n");
    }
    return 0;
}