#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
int n;

bool comp(pii a, pii b)
{
    return a.second < b.second;
}
pii player[500000];
int tr[1 << 20]; //2의 20승

// l~r사이의 구간이 궁금하다!! s/e 는 세그먼트 트리의 시작 끝 점
int seg_sum(int node, int s, int e, int l, int r)
{
    if (r < s || e < l)
        return 0;
    if (l <= s && e <= r)
    {
        return tr[node];
    }
    // 교묘하게 겹치는 경우! 아래 애들한테 물어볼 수 있다.
    else
    {
        // 왼쪽 오른쪽 탐색해서 합구함
        return seg_sum(node * 2, s, (s + e) / 2, l, r) + seg_sum(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
    }
}

void update(int node, int s, int e, int idx, int v)
{
    if (idx < s || e < idx)
        return;
    if (s == e)
    {
        tr[node] = v;
        /* 이런거도 있음!
        tr[node]+=v;
        tr[node]-=v;
        tr[node]*=v;
        tr[node]^=v;
        tr[node]&=v;
        */
    }
    else
    {
        update(node * 2, s, (s + e) / 2, idx, v);
        update(node * 2 + 1, (s + e) / 2 + 1, e, idx, v);
        tr[node] = tr[node * 2] + tr[node * 2 + 1];
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int power;
        scanf("%d", &power);
        player[i].first = i;
        player[i].second = power;
    }
    sort(player, player + n, comp);

    // 좌표 압축
    //re labeling -> 힘이 어짜피 차례대로 들어가 있음!!!! 그래서 그냥 순차적으로 index로 만들어줌
    for (int i = 0; i < n; i++)
    {
        player[i].second = i + 1;
    }
    // 다시 입력 받은 순서, 선수 순서 대로 정렬한다!, 그래야 세그먼트 트리에 넣으면서 순차적으로 그 구간에 대해 구할 수 있음
    sort(player, player + n);
    for (int i = 0; i < n; i++)
    {
        int cur_power = player[i].second;
        int cnt = 0;
        if (cur_power > -1)
            cnt = seg_sum(1, 1, n, 1, cur_power - 1);
        update(1, 1, n, cur_power, 1);
        printf("%d ", i + 1 - cnt);
    }

    return 0;
}