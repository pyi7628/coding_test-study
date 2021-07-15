//게임
//dfs
#include <cstdio>
bool check[51][51];
int arr[51][51];
int n, m;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    return 0;
}