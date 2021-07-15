#include <cstdio>
#include <algorithm>
using namespace std;
struct st
{
    int a, b, c;
};
st e[100002];
int p[1001]; // 부모가 누구일까용, index(나!)에 대한 부모노드의 번호를 저장!
int find(int n)
{
    if (n == p[n])
        return n;

    return p[n] = find(p[n]); // 루트가 다를 경우 부모를 쫓아가면서 최상의 노드를 찾고 현재 n의 최상위 노드를 업데이트 한다.
}
int do_union(st n)
{
    int p1 = find(n.a), p2 = find(n.b);
    if (p1 == p2)
        return 0; // 최상단에서 union 할 수 없음 -> cycle이 생기게 됨
                  // if (p1 < p2)
                  //     p[p1] = p2;
                  // else
    p[p2] = p1;
    return 1;
}
bool compare(st a, st b)
{
    return a.c < b.c;
}
int answer = 0, cnt = 0;
int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[i].a = a;
        e[i].b = b;
        e[i].c = c;
    }
    for (int i = 1; i <= n; i++)
    {
        p[i + 1] = i + 1;
    }
    sort(e, e + m, compare);
    for (int i = 0; i < m; i++)
    {
        if (do_union(e[i]) != 0)
        {
            cnt += 1;
            answer += e[i].c;
        }
        if (cnt == n - 1)
            break;
    }
    printf("%d", answer);
}