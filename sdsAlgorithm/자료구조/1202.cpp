// 소수의 곱 문제와 비슷
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
int n, k;
long answer;
int main()
{
    vector<pair<int, int> > jams;
    vector<int> bags;
    priority_queue<int> q;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int m, v;
        scanf("%d %d", &m, &v);
        jams.push_back(make_pair(m, v));
    }

    for (int i = 0; i < k; i++)
    {
        int m;
        scanf("%d", &m);
        bags.push_back(m);
    }
    sort(jams.begin(), jams.end());
    sort(bags.begin(), bags.end());

    int jam_i = 0;

    for (int i = 0; i < k; i++)
    {
        // 가방 무게보다 작거나 같은 애중에 가장 큰애를 넣어준다. -> 무게에 맞는 애를 빼서 pq에 넣는다!!!
        // 그 다음 무게꺼 또 넣늗다!!!
        // 계속 탑을 뽑는다.!
        int bag_w = bags[i];
        while (jam_i < jams.size() && bag_w >= jams[jam_i].first)
        {
            q.push(jams[jam_i].second);
            jam_i++;
        }
        if (!q.empty())
            answer += q.top();
        q.pop();
    }
    printf("%ld", answer);
    return 0;
}