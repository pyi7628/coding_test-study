#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int p;
    int d;
};
vector<int> v[50001];
node nodes[50001];
queue<node> q;
bool check[50001];
int n, m, n1, n2;
node temp;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &n1, &n2);
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    v[0].push_back(1);
    temp.d = 0, temp.p = 0;
    q.push(temp);
    while (!q.empty())
    {
        node cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur.p].size(); i++)
        {
            if (!check[v[cur.p][i]])
            {
                nodes[v[cur.p][i]].d = cur.d;
                nodes[v[cur.p][i]].p = cur.p;

                check[v[cur.p][i]] = true;
                temp.d = cur.d + 1, temp.p = v[cur.p][i];
                q.push(temp);
            }
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &n1, &n2);

        int p1 = nodes[n1].d >= nodes[n2].d ? n1 : n2; // 1이 무조건 depth 깊음
        int p2 = nodes[n1].d >= nodes[n2].d ? n2 : n1;

        int d1 = nodes[p1].d, d2 = nodes[p2].d;

        while (d1 != d2)
        {
            p1 = nodes[p1].p;
            d1 = nodes[p1].d;
        } // 끝나면 둘의 depth가 같아짐

        while (p1 != p2)
        {
            p1 = nodes[p1].p;
            p2 = nodes[p2].p;
        }
        printf("%d\n", p1);
    }

    return 0;
}