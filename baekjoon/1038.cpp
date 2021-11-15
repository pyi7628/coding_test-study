#include <iostream>
#include <queue>
#include <string>
using namespace std;
queue<string> q;
int cnt = -1, n;
int main()
{
    cin >> n;
    for (int i = 0; i <= 9; i++)
    {
        q.push(to_string(i));
    }
    while (!q.empty())
    {
        string cur = q.front();
        q.pop();
        cnt++;
        if (cnt == n)
        {
            cout << cur;
            return 0;
        }
        for (int i = 0; i <= 8; i++)
        {
            if (cur[cur.length() - 1] - '0' > i)
                q.push(cur + to_string(i));
        }
    }
    cout << "-1";
    return 0;
}