#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n, c, num, answer = 0;
vector<int> v;
int check_dist(int g)
{
    int cnt = 1, prev = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] - prev >= g)
        {
            prev = v[i];
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int left = 1, right = v[v.size() - 1], mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        int cur = check_dist(mid);
        if (cur >= c)
        {
            left = mid + 1;
            if (answer < mid)
                answer = mid;
        }
        else if (cur < c)
        {
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}