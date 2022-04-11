#include <cstdio>
#include <vector>
using namespace std;
int p[51];
int truth[51]; // 1이면 진실을 아는 것
vector<int> party[51];
int n, m, tn, pn, num, check, answer = 0;
int find(int v)
{
    if (p[v] == v)
        return v;
    p[v] = find(p[v]);
    return p[v];
}
int main()
{
    for (int i = 0; i <= 50; i++)
    {
        p[i] = i;
    }

    scanf("%d%d%d", &n, &m, &tn);
    for (int i = 0; i < tn; i++)
    {
        scanf("%d", &num);
        truth[num] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &pn);
        for (int j = 0; j < pn; j++)
        {
            scanf("%d", &num);
            party[i].push_back(num);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < party[i].size() - 1; j++)
        {
            int p1 = find(party[i][j]), p2 = find(party[i][j + 1]);
            p[p2] = p1;
            if (truth[p2]) // 이전에 진실을 아는 사람과 모르는 사람이 하나의 트리를 이루고, 그 중 원래는 몰랐던 사람이 그후에 파티에 오는 경우라면 누구와 이어져 있는지를 확인해야하므로
                truth[p1] = 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        check = 0;
        for (int j = 0; j < party[i].size(); j++)
        {
            int p1 = find(party[i][j]);
            if (truth[p1])
                check = 1;
        }
        if (!check)
            answer++;
    }
    printf("%d", answer);
    return 0;
}