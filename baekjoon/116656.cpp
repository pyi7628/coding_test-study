#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string str;
vector<string> v;
int main()
{
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        v.push_back(str.substr(i, str.length() - i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
    return 0;
}