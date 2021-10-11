#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, string> pis;

bool compare(pis a, pis b)
{
    return a.first < b.first;
}
string str;
int age;
int n;
vector<pis> v;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> age;
        cin >> str;
        v.push_back(make_pair(age, str));
    }
    stable_sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}