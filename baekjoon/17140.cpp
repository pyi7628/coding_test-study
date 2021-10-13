#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
int arr[101][101];
int check[101];
vector<pii> v;
int r, c, k;
int row_cnt = 3, col_cnt = 3, cnt = 0;
int main()
{
    scanf("%d%d%d", &r, &c, &k);
    for (int i = 0; i < row_cnt; i++)
        for (int j = 0; j < col_cnt; j++)
            scanf("%d", &arr[i][j]);

    while (cnt <= 100)
    {
        if (arr[r - 1][c - 1] == k)
        {
            printf("%d", cnt);
            return 0;
        }
        if (row_cnt >= col_cnt)
        {
            int max_size = col_cnt;
            for (int i = 0; i < row_cnt; i++)
            {
                memset(check, 0, sizeof(check));
                for (int j = 0; j < col_cnt; j++)
                    check[arr[i][j]]++;
                for (int j = 1; j <= 100; j++)
                {
                    arr[i][j - 1] = 0;
                    if (check[j] != 0)
                        v.push_back(make_pair(check[j], j));
                }
                sort(v.begin(), v.end());
                for (int j = 0; j < v.size() && j < 50; j++)
                {
                    arr[i][2 * j] = v[j].second;
                    arr[i][2 * j + 1] = v[j].first;
                }
                if (max_size < v.size() * 2)
                    max_size = v.size() > 50 ? 100 : v.size() * 2;
                v.clear();
            }
            col_cnt = max_size;
        }
        else
        {
            int max_size = row_cnt;
            for (int i = 0; i < col_cnt; i++)
            {
                memset(check, 0, sizeof(check));
                for (int j = 0; j < row_cnt; j++)
                    check[arr[j][i]]++;
                for (int j = 1; j <= 100; j++)
                {
                    arr[j - 1][i] = 0;
                    if (check[j] != 0)
                        v.push_back(make_pair(check[j], j));
                }
                sort(v.begin(), v.end());
                for (int j = 0; j < v.size() && j < 50; j++)
                {
                    arr[2 * j][i] = v[j].second;
                    arr[2 * j + 1][i] = v[j].first;
                }
                if (max_size < v.size() * 2)
                    max_size = v.size() > 50 ? 100 : v.size() * 2;
                v.clear();
            }
            row_cnt = max_size;
        }
        cnt++;
    }
    printf("-1");
    return 0;
}