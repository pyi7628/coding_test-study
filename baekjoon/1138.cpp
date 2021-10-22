#include <cstdio>
using namespace std;
int n, num;
int arr[11];
int main()
{
    scanf("%d", &n);
    int cnt;
    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        scanf("%d", &num);
        for (int j = 0; j < n; j++)
        {
            if (!arr[j])
                cnt++;
            if (cnt > num)
            {
                arr[j] = i;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}