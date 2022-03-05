#include <cstdio>
#include <stdlib.h>
#include <cmath>
using namespace std;
int n, r, c;
void dc(int cr, int cc, int s, int cnt)
{
    if (s == 1)
    {
        printf("%d", cnt);
        exit(0);
    }
    if (r < cr + s / 2 && c < cc + s / 2)
        dc(cr, cc, s / 2, cnt);
    else if (r < cr + s / 2 && c < cc + s)
        dc(cr, cc + s / 2, s / 2, cnt + (s * s / 4));
    else if (r < cr + s && c < cc + s / 2)
        dc(cr + s / 2, cc, s / 2, cnt + (s * s / 4) * 2);
    else
        dc(cr + s / 2, cc + s / 2, s / 2, cnt + (s * s / 4) * 3);
}
int main()
{
    scanf("%d%d%d", &n, &r, &c);
    dc(0, 0, pow(2, n), 0);
    return 0;
}