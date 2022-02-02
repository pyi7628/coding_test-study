#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int n, m, r;
int map[300][300];
vector<pii> pos[150];
vector<int> nums[150];
int main()
{
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &map[i][j]);
    int s = n < m ? n : m;
    for (int i = 0; i < s / 2; i++)
    {
        for (int j = i; j < n - i; j++)
            pos[i].push_back(make_pair(j, i)), nums[i].push_back(map[j][i]);

        for (int j = i + 1; j < m - i; j++)
            pos[i].push_back(make_pair(n - i - 1, j)), nums[i].push_back(map[n - i - 1][j]);

        for (int j = i + 1; j < n - i; j++)
            pos[i].push_back(make_pair(n - j - 1, m - i - 1)), nums[i].push_back(map[n - j - 1][m - i - 1]);

        for (int j = i + 1; j < m - i - 1; j++)
            pos[i].push_back(make_pair(i, m - j - 1)), nums[i].push_back(map[i][m - j - 1]);
    }
    int row, col;
    for (int i = 0; i < s / 2; i++)
        for (int j = 0; j < nums[i].size(); j++)
        {
            row = pos[i][(j + r) % nums[i].size()].first,
            col = pos[i][(j + r) % nums[i].size()].second;
            map[row][col] = nums[i][j];
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }

    return 0;
}