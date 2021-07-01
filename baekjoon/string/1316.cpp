#include <iostream>
#include <string>

using namespace std;

bool is_group(string s)
{
    int check[30] = {0};
    int cur_char = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (cur_char == (s[i] - 'a'))
            check[s[i] - 'a']++;
        else if (check[s[i] - 'a'] == 0)
        {
            cur_char = s[i] - 'a';
            check[s[i] - 'a']++;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n = 0;
    int cnt = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (is_group(s))
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
