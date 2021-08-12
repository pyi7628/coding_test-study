#include <cstdio>
using namespace std;
int n, m;
int p[500001];
int answer = 0;
int find(int n)
{
    if (n == p[n])
        return n;
    return p[n] = find(p[n]);
}
int main()
{

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        scanf("%d%d", &n1, &n2);
        int p1 = find(n1);
        int p2 = find(n2);
        if (p1 == p2)
        {
            answer = i + 1;
            break;
        }
        p[p2] = p1;
    }
    printf("%d", answer);
    return 0;
}