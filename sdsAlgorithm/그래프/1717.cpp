#include <cstdio>
#include <vector>
using namespace std;
int check[1000001];
int find(int n)
{
    if (n == check[n])
        return n;

    return check[n] = find(check[n]); // 루트가 다를 경우 부모를 쫓아가면서 최상의 노드를 찾고 현재 n의 최상위 노드를 업데이트 한다.
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 1000000; i++)
    {
        check[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int type, n1, n2;
        scanf("%d%d%d", &type, &n1, &n2);
        if (type == 0)
        {
            check[find(n2)] = find(n1);
        }
        if (type == 1)
        {
            if (find(n1) == find(n2))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}