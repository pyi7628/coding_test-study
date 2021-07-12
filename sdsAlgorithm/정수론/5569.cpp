#include <cstdio>
#define MOD 100000
int arr[102][102][2][2];
int w, h;
int main()
{
    int answer = 0;
    scanf("%d %d", &w, &h);
    for (int i = 2; i <= w; i++)
    {
        arr[i][1][0][1] = 1;
    }
    for (int i = 2; i <= h; i++)
    {
        arr[1][i][0][0] = 1;
    }
    for (int i = 2; i <= w; i++)
    {
        for (int j = 2; j <= h; j++)
        {
            arr[i][j][0][0] = (arr[i][j - 1][0][0] + arr[i][j - 1][1][0]) % MOD;
            arr[i][j][0][1] = (arr[i - 1][j][0][1] + arr[i - 1][j][1][1]) % MOD;
            arr[i][j][1][0] = arr[i][j - 1][0][1] % MOD;
            arr[i][j][1][1] = arr[i - 1][j][0][0] % MOD;
        }
    }

    answer = (arr[w][h][0][0] + arr[w][h][0][1] + arr[w][h][1][0] + arr[w][h][1][1]) % MOD;
    printf("%d", answer);
    return 0;
}