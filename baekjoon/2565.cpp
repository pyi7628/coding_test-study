#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{

    vector<pair<int, int> > list;
    int dp[102] = {
        0,
    };
    int N = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int t1, t2 = 0;
        scanf("%d %d", &t1, &t2);

        pair<int, int> p = make_pair(t1, t2);

        list.push_back(p);
    }

    sort(list.begin(), list.end(), compare);

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        int max_num = 0;
        for (int j = 0; j < i; j++)
        {
            if (list[i].second > list[j].second)
                max_num = max(max_num, dp[j]);
        }

        dp[i] = max_num + 1;
        answer = max(dp[i], answer);
    }

    printf("%d\n", N - answer);
}