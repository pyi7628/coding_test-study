#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
struct node
{
    int s;
    int e;
    double d;
};
int n;
double answer = 0, n1, n2, dist;
int p[101];
vector<node> v;
vector<pair<double, double> > point;
node temp;

bool compare(node a, node b)
{
    return a.d < b.d;
}

int find(int n)
{
    if (p[n] == n)
        return n;
    return p[n] = find(p[n]);
}
int main()
{

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf%lf", &n1, &n2);
        point.push_back(make_pair(n1, n2));
        p[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                dist = sqrt(pow(point[i].first - point[j].first, 2) + pow(point[i].second - point[j].second, 2));
                temp.s = i, temp.e = j, temp.d = dist;
                v.push_back(temp);
            }
        }
    }
    sort(v.begin(), v.end(), compare);

    int p1, p2;
    for (int i = 0; i < v.size(); i++)
    {
        p1 = find(v[i].s), p2 = find(v[i].e);

        if (p1 != p2)
        {
            p[p2] = p1;
            answer += v[i].d;
        }
    }
    printf("%.2lf", answer);
    return 0;
}