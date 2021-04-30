#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<pair<int, int> > q; // inx, time

    int time = 1;
    int cur_weight = truck_weights[0];
    q.push(make_pair(0, time));
    while (!q.empty())
    {
        time++;
        if (time - q.front().second == bridge_length)
        {
            printf("pop: %d %lu\n", q.front().first, q.size());
            cur_weight -= truck_weights[q.front().first];
            q.pop();
        }
        // printf("???%d %d \n", q.back().first - 1 < (int)truck_weights.size(), cur_weight + truck_weights[q.back().first + 1] <= weight);
        if (q.back().first + 1 < (int)truck_weights.size() && cur_weight + truck_weights[q.back().first + 1] <= weight)
        {
            printf("push: %d %lu \n", q.back().first + 1, q.size());
            q.push(make_pair(q.back().first + 1, time));
            cur_weight += truck_weights[q.back().first];
        }
    }
    printf("%d\n", time);
    return time;
}
int main()
{

    vector<int> v = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    solution(100, 100, v);
    return 0;
}
