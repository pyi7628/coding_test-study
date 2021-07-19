#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
int check[20001];
int k;
struct NODE
{
    vector<int> e;
};
NODE n_list[20001];
queue<int> q;
int main()
{
    scanf("%d", &k);
    for (int t = 0; t < k; t++)
    {
        int v, e;
        scanf("%d%d", &v, &e);
        int flag = 0;
        for (int i = 0; i < e; i++)
        {
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            n_list[v1].e.push_back(v2);
            n_list[v2].e.push_back(v1);
        }

        for (int i = 1; i <= v; i++)
        {
            if (n_list[i].e.size() > 0)
            {
                check[i] = 1;
                q.push(i);
                break;
            }
        }

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < n_list[cur].e.size(); i++)
            {
                if (check[n_list[cur].e[i]] != 0 && check[n_list[cur].e[i]] == check[cur])
                {
                    flag = 1;
                    break;
                }
                else if (check[n_list[cur].e[i]] == 0)
                {
                    check[n_list[cur].e[i]] = -check[cur];
                    q.push(n_list[cur].e[i]);
                }
            }
            if (flag == 1)
            {
                printf("NO\n");
                break;
            }
            if (q.empty())
            {
                for (int i = 1; i <= v; i++)
                {
                    if (check[i] == 0)
                    {
                        check[i] = 1;
                        q.push(i);
                        break;
                    }
                }
            }
        }
        if (flag == 0)
            printf("YES\n");
        for (int i = 0; i <= v; i++)
        {
            n_list[i].e.clear();
        }
        memset(check, 0, sizeof(check));
        while (!q.empty())
        {
            q.pop();
        }
    }
    return 0;
}

// 3
// 3 2
// 1 3
// 2 3
// 4 4
// 1 2
// 2 3
// 3 4
// 8 8
// 1 2
// 2 3
// 2 4
// 2 5
// 5 7
// 5 6
// 4 8
// 6 8
