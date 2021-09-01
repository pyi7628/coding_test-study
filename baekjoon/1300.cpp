#include <cstdio>
using namespace std;
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    int low = 1, high = n, mid;
    int min_mid = n;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (mid * mid >= k)
        {
            if (mid < min_mid)
                min_mid = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    int answer = 0;
    for (int i = 1, cnt = 2; i <= min_mid; i++, cnt += 2)
    {
        answer = min_mid * i;
        if (cnt >= k - (min_mid - 1) * (min_mid - 1))
            break;
    }
    printf("%d", answer);
    return 0;
}