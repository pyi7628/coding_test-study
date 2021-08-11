#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, cnt = 0;
vector<char> s;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s.push_back(str[0]);
        for (int j = 1; j < str.length(); j++)
        {
            if (s.back() == str[j])
                s.pop_back();
            else
                s.push_back(str[j]);
        }
        if (s.empty())
            cnt++;
        s.clear();
    }
    cout << cnt;
    return 0;
}