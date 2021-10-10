#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
string str;
vector<pair<int, string> > v;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        v.push_back(make_pair(str.length(), str));
    }
    sort(v.begin(), v.end());
    string cur = "";
    for (int i = 0; i < n; i++)
    {
        if (v[i].second.compare(cur) != 0)
            cout << v[i].second << '\n';
        cur = v[i].second;
    }
    return 0;
}