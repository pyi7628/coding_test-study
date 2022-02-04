#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
struct node
{
    int r;
    int c;
    int s;
};
int n, m, k, nr, nc, ns, answer = 50000;
int fmap[300][300];
vector<node> v;
bool check[10];
node cur;
vector<int> seq;

void rotate(int (*map)[300])
{
    int r = v[seq.back()].r, c = v[seq.back()].c, s = v[seq.back()].s;
    for (int i = 0; i < s; i++)
    {
        int temp = map[r - s - 1 + i][c - s - 1 + i], next;
        for (int j = c - s + i; j < c + s - i; j++)
            next = map[r - s - 1 + i][j], map[r - s - 1 + i][j] = temp, temp = next;

        for (int j = r - s + i; j < r + s - i; j++)
            next = map[j][c + s - 1 - i], map[j][c + s - 1 - i] = temp, temp = next;

        for (int j = c + s - 2 - i; j >= c - s - 1 + i; j--)
            next = map[r + s - 1 - i][j], map[r + s - 1 - i][j] = temp, temp = next;

        for (int j = r + s - 2 - i; j >= r - s - 1 + i; j--)
            next = map[j][c - s - 1 + i], map[j][c - s - 1 + i] = temp, temp = next;
    }
}
void back_tracking(int cnt, int (*cur_map)[300])
{
    //new map init
    int temp_map[300][300];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            temp_map[i][j] = cur_map[i][j];

    // 여기서 seq 마지막 껄로 rotate
    if (!seq.empty())
        rotate(temp_map);

    if (cnt == k)
    {
        // find min;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < m; j++)
                sum += temp_map[i][j];
            if (sum < answer)
                answer = sum;
        }
        return;
    }
    for (int i = 0; i < k; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            seq.push_back(i);
            back_tracking(cnt + 1, temp_map);
            seq.pop_back();
            check[i] = false;
        }
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &fmap[i][j]);
    for (int t = 0; t < k; t++)
    {
        scanf("%d%d%d", &nr, &nc, &ns);
        cur.r = nr, cur.c = nc, cur.s = ns;
        v.push_back(cur);
    }

    back_tracking(0, fmap);
    printf("%d", answer);

    return 0;
}