#include <cstdio>
using namespace std;
bool check[1050000];
int n, q, c;
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &c);
        int tc = c;
        int c_min = 0;
        while (tc != 0)
        {
            if (check[tc] == 1)
                c_min = tc;
            tc = tc / 2;
        }

        printf("%d\n", c_min);
        if (c_min == 0)
            check[c] = 1;
    }

    return 0;
}