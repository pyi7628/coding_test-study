#include <cstdio>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int n;
int nums[1000002] = {0};
int gcd_se[1000002] = {0};
int gcd_es[1000002] = {0};
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &nums[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        gcd_se[i] = gcd(gcd_se[i - 1], nums[i]);
        gcd_es[n - i + 1] = gcd(gcd_es[n - i + 2], nums[n - i + 1]);
        //  printf("%d %d %d\n",gcd_es[n - i], gcd(gcd_es[n - i + 1], nums[n - i + 1] )
    }
    // for (int i = 1 ; i <= N ; i++) {
    //         leftGcd[i] = gcd(leftGcd[i - 1], A[i]);
    //     }
    //     for (int i = N ; i >= 1 ; i--) {
    //         rightGcd[i] = gcd(rightGcd[i + 1], A[i]);
    //     }
    // for (int i = n; i >= 1; i++)
    // {
    //     gcd_es[i] = gcd(gcd_es[i+1], nums[n]);
    // }
    int answer = -1, minus_num = 0;
    for (int i = 1; i <= n; i++)
    {
        int result_gcd = gcd(gcd_se[i - 1], gcd_es[i + 1]);
        if (nums[i] % result_gcd != 0 && answer < result_gcd)
            minus_num = nums[i], answer = result_gcd;
    }
    if (answer == -1)
        printf("%d", answer);
    else
        printf("%d %d", answer, minus_num);
    return 0;
}