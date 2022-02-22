#include <cstdio>
#include <vector>
using namespace std;
int n, k, q, m, num;
int sleep[5003];
vector<int> v;
int sum[5003];
int main()
{
    scanf("%d%d%d%d", &n, &k, &q, &m);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &num);
        sleep[num] = 1;
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &num);
        if (!sleep[num])
            v.push_back(num);
    }
    int flag = 0;

    for (int i = 3; i < n + 3; i++)
    {
        flag = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (i % v[j] == 0)
            {
                flag = 1;
                break;
            }
        }
        sum[i] = sum[i - 1];
        if (!flag || sleep[i])
            sum[i]++;
    }
    int s, e;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &s, &e);
        printf("%d\n", sum[e] - sum[s - 1]);
    }
    return 0;
}