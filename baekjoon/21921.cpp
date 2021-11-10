#include <cstdio>
using namespace std;
int n, m;
int arr[250001];
int max_visit, cnt = 0, sum = 0;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int s = 0, e = 0;
    sum = arr[0];
    while (e != n)
    {
        if (e - s < m - 1)
            e++, sum += arr[e];
        else if (e - s == m - 1)
        {
            if (sum > max_visit)
            {
                max_visit = sum;
                cnt = 1;
            }
            else if (sum == max_visit)
                cnt++;
            e++, sum += arr[e];
            sum -= arr[s], s++;
        }
    }
    if (max_visit == 0)
        printf("SAD");
    else
    {
        printf("%d\n%d", max_visit, cnt);
    }
    return 0;
}