#include <cstdio>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    int a, b, c, d, p, q, g;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    p = a * d + b * c;
    q = b * d;
    g = gcd(p, q);
    printf("%d %d", p / g, q / g);
    return 0;
}