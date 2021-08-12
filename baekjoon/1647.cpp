#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int sum = 0;
struct NODE
{
    int a;
    int b;
    int c;
};
vector<NODE> v;
bool compare(NODE a, NODE b)
{
    return a.c < b.c;
}
int p[100002];
int find(int num)
{
    if (num == p[num])
        return num;
    return p[num] = find(p[num]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        NODE node;
        node.a = a;
        node.b = b;
        node.c = c;
        v.push_back(node);
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++)
    {
        int p1 = find(v[i].a);
        int p2 = find(v[i].b);
        if (p1 != p2)
        {
            p[p2] = p1;
            sum += v[i].c;
            n--;
        }
        if (n == 2)
        {
            printf("!!!!\n");
            break;
        }
        // printf("%d ", v[i].c);
    }
    printf("%d", sum);
    return 0;
}