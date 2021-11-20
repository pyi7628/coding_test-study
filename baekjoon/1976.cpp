#include <cstdio>
#include <vector>
using namespace std;
int n, m, num;
vector<int> trip_route;

int p[201];

int find(int n)
{
    if (n == p[n])
        return n;
    else
        return p[n] = find(p[n]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &num);
            if (num)
            {
                int p1 = find(i), p2 = find(j);
                p[p2] = p1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &num);
        trip_route.push_back(num - 1);
    }
    for (int i = 0; i < m - 1; i++)
    {
        int p1 = find(trip_route[i]), p2 = find(trip_route[i + 1]);
        if (p1 != p2)
        {
            printf("NO");
            return 0;
        }
    }

    printf("YES");

    return 0;
}