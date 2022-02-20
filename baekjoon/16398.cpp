#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct NODE
{
    int w;
    int n1;
    int n2;
};
vector<NODE> v;
int p[1001];
int n, answer, num;
NODE temp;
bool compare(NODE a, NODE b)
{
    return a.w < b.w;
}

int find(int n)
{
    if (n == p[n])
        return n;
    return p[n] = find(p[n]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &num);
            if (i < j)
            {
                temp.n1 = i, temp.n2 = j, temp.w = num;
                v.push_back(temp);
            }
        }
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++)
    {
        NODE cur = v[i];
        int p1 = find(cur.n1), p2 = find(cur.n2);
        if (p1 != p2)
        {
            p[p2] = p1;
            answer += cur.w;
        }
    }
    printf("%d", answer);
    return 0;
}