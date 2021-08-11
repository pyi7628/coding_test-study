#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
//typedef pair<int, int> pii;
int n, m;
struct N
{
    int val;
    int s;
    int e;
};
vector<N> v;
bool compare(N a, N b)
{
    return a.val < b.val;
}
void find(int num)
{
    int left = 0, right = v.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (v[mid].val == num)
        {
            printf("%d ", v[mid].e - v[mid].s + 1);
            return;
        }
        else if (v[mid].val > num)
            right = mid - 1;
        else if (v[mid].val < num)
            left = mid + 1;
    }
    printf("0 ");
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        N temp;
        temp.val = num;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), compare);
    int prev = 10000001;
    int prev_pos = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (prev == v[i].val)
        {
            v[i].s = prev_pos;
        }
        else
        {
            prev = v[i].val;
            prev_pos = i;
            v[i].s = i;
        }
    }
    prev = 10000001;
    prev_pos = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (prev == v[i].val)
        {
            v[i].e = prev_pos;
        }
        else
        {
            prev = v[i].val;
            prev_pos = i;
            v[i].e = i;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        printf("val: %d s: %d e: %d\n", v[i].val, v[i].s, v[i].e);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int num;
        scanf("%d", &num);
        find(num);
    }

    return 0;
}