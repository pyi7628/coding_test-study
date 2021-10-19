#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int n, answer = 0;
int map[11][11];
bool check[11][11];
vector<pii> v;
bool pruning(int r, int c)
{
    if (!map[r][c] || check[r][c])
        return false;
    for (int i = 0; i < v.size(); i++)
    {
        if (abs(v[i].second - c) == abs(v[i].first - r))
            return false;
    }
    return true;
}
int back_tracking(int idx)
{

    if (idx >= n * n)
    {
        // if (answer < cnt)
        // {
        //     answer = cnt;
        //     // for (int i = 0; i < n; i++)
        //     // {
        //     //     for (int j = 0; j < n; j++)
        //     //     {
        //     //         printf("%d ", check[i][j]);
        //     //     }
        //     //     printf("\n");
        //     // }
        //     // printf("\n");
        // }

        return 0;
    }
    int i = idx / n, j = idx % n;
    int result = 0;

    // for (; i < n; i++)
    // {
    //     for (; j < n; j++)
    //     {

    if (pruning(i, j))
    {
        check[i][j] = true;
        v.push_back(make_pair(i, j));
        result = max(back_tracking(idx + 2) + 1, result);
        check[i][j] = false;
        v.pop_back();
    }
    result = max(back_tracking(idx + 2), result);
    return result;
    //     }
    //     j = 0;
    // }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    answer = back_tracking(0) + back_tracking(1);

    printf("%d", answer);
    return 0;
}