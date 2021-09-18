// #include <cstdio>
// #include <vector>

// using namespace std;
// typedef pair<int, int> pii;
// vector<pii> v[100001];
// int check[100001];
// int n, f, t, w;
// int answer = 0, max_result;

// int dfs(int from, int w, int prev)
// {
//     int max_num = 0, result;
//     for (int i = 0; i < v[from].size(); i++)
//     {
//         //printf("test: %d %d\n", check[from][v[from][i].first], v[from].size());
//         if (v[from][i].first != prev)
//         {
//             if (!check[v[from][i].first])
//             {

//                 result = dfs(v[from][i].first, v[from][i].second, from);
//                 printf("from %d to %d result %d\n", from, v[from][i].first, result);
//                 check[v[from][i].first] = result;
//             }
//             else
//                 result = check[v[from][i].first];
//             if (max_num < result)
//                 max_num = result;
//         }
//     }

//     return w + max_num;
// }
// int main()
// {
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &f);
//         scanf("%d%d", &t, &w);
//         while (t != -1)
//         {
//             v[f].push_back(make_pair(t, w));
//             scanf("%d", &t);
//             if (t == -1)
//                 break;
//             scanf("%d", &w);
//         }
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         max_result = dfs(i, 0, 0);
//         if (max_result > answer)
//             answer = max_result;
//     }
//     printf("%d", answer);
//     return 0;
// }

#include <cstdio>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
vector<pii> v[100001];
bool check[100001];
int n, f, t, w;
int answer = 0, end_p;

void dfs(int from, int sum)
{
    if (answer < sum)
        answer = sum, end_p = from;
    for (int i = 0; i < v[from].size(); i++)
    {
        if (!check[v[from][i].first])
        {
            check[v[from][i].first] = true;
            dfs(v[from][i].first, sum + v[from][i].second);
            check[v[from][i].first] = false;
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &f);
        scanf("%d%d", &t, &w);
        while (t != -1)
        {
            v[f].push_back(make_pair(t, w));
            scanf("%d", &t);
            if (t == -1)
                break;
            scanf("%d", &w);
        }
    }

    check[1] = true;
    dfs(1, 0);
    check[1] = false;
    dfs(end_p, 0);
    printf("%d", answer);
    return 0;
}