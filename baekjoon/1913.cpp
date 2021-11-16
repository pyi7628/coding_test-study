#include <cstdio>
using namespace std;
int arr[1000][1000];
int n, m, row, col, num, cnt = 0;
int main()
{
    scanf("%d%d", &n, &m);
    num = n - 2 * cnt;
    while (num != -1)
    {
        for (int i = 0; i < num; i++)
        {
            arr[cnt + i][cnt] = num * num - i;
            arr[n - 1 - cnt][cnt + i] = num * num - (num - 1) - i;
            arr[n - 1 - cnt - i][n - 1 - cnt] = num * num - (num - 1) * 2 - i;
            arr[cnt][n - 1 - cnt - i] = num * num - (num - 1) * 3 - i;
        }
        arr[cnt][cnt] = num * num;
        cnt++;
        num = n - 2 * cnt;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
            if (arr[i][j] == m)
                row = i, col = j;
        }
        printf("\n");
    }
    printf("%d %d", row + 1, col + 1);
    return 0;
}