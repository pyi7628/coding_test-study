#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int flag = 0;
string s, t, cur;
void dfs(string str)
{

    if (s.length() > str.length())
        return;
    if (str.compare(s) == 0)
    {
        flag = 1;
        return;
    }
    if (str[str.length() - 1] == 'A')
    {
        cout << "-A: " << str << '\n';
        dfs(str.substr(0, str.length() - 1));
    }
    else
    {
        reverse(str.begin(), str.end());
        cout << "-B: " << str << '\n';
        dfs(str.substr(1, str.length() - 1));
    }
}

int main()
{
    cin >> s;
    cin >> t;
    dfs(t);
    printf("%d", flag);
    return 0;
}