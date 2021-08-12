#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;
int a, b, c;
long long mul(int num)
{
    // printf("test: %d %d\n", a, c);
    if (num == 1)
        return a % c;
    long long mul_result = mul(num / 2);
    if (num % 2 == 0)
        return (mul_result * mul_result) % c;
    else
        return ((mul_result * mul_result) % c * a) % c;
}
int main()
{
    scanf("%d%d%d", &a, &b, &c);
    printf("%lld", mul(b));
    return 0;
}