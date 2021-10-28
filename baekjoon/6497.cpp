#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int from;
    int to;
    int weight;
};
bool compare(node a, node b)
{
    return a.weight < b.weight;
}
int p[200001];
int find(int n)
{
    if (p[n] == n)
        return n;
    return p[n] = find(p[n]);
}

int n, m, f, t, w;
vector<node> v;
node temp;
int main()
{
    while (1)
    {

        long long sum = 0, total = 0;
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0)
            return 0;
        for (int i = 0; i <= n; i++)
        {
            p[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &f, &t, &w);
            total += w;
            temp.from = f, temp.to = t, temp.weight = w;
            v.push_back(temp);
        }
        sort(v.begin(), v.end(), compare);
        int p1, p2;
        for (int i = 0; i < v.size(); i++)
        {
            p1 = find(v[i].from), p2 = find(v[i].to);
            p[p2] = p1;
            if (p1 != p2)
                sum += v[i].weight;
        }
        printf("%lld\n", total - sum);
        v.clear();
    }
    return 0;
}