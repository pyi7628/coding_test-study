#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    vector<pair<int, int> > frame;
    int check[101] = {
        0,
    };
    int check_old[101] = {
        0,
    };
    // frame에 들어 있는 경우 frame idx+1 의 값으로 저장! -> 위치 알게
    int N, R = 0;
    cin >> N;
    cin >> R;

    for (int i = 0; i < R; i++)
    {
        int num = 0;
        cin >> num;

        if (check[num] > 0)
            frame[check[num] - 1].second++;

        else if (frame.size() < N)
        {
            frame.push_back(make_pair(num, 1));
            check[num] = frame.size();
        }
        else if (frame.size() == N)
        {
            int min_like = 1001;
            int oldest = -1;

            int min_idx = 0;
            for (int j = 0; j < frame.size(); j++)
            {
                if (frame[j].second == min_like && oldest < check_old[frame[j].first])
                {
                    min_idx = frame[j].first;
                    oldest = check_old[frame[j].first];
                }
                else if (frame[j].second < min_like)
                {
                    min_like = frame[j].second;
                    oldest = check_old[frame[j].first];
                    min_idx = frame[j].first;
                }
            }

            frame[check[min_idx] - 1].first = num;
            frame[check[min_idx] - 1].second = 1;
            check_old[frame[check[min_idx] - 1].first] = 0;
            check[num] = check[min_idx];
            check[min_idx] = 0;
        }
        for (int j = 0; j < frame.size(); j++)
        {
            check_old[frame[j].first]++;
        }
    }
    sort(frame.begin(), frame.end());
    for (int i = 0; i < frame.size(); i++)
    {
        printf("%d ", frame[i].first);
    }
    return 0;
}