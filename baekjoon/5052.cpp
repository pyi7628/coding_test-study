#include <iostream>
#include <string>
#include <queue>
using namespace std;

int t, n;
string str;

priority_queue<string, vector<string>, greater<string> > pq;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> str;
            pq.push(str);
        }
        bool dup = false;
        string prev = pq.top();
        pq.pop();
        while (!pq.empty())
        {
            string cur = pq.top();
            pq.pop();
            if (prev.length() != cur.length())
            {
                bool flag = true;
                for (int i = 0; i < prev.length(); i++)
                {
                    if (prev[i] != cur[i])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    dup = true;
                    while (!pq.empty())
                        pq.pop();
                    break;
                }
            }
            prev = cur;
        }
        if (dup)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}