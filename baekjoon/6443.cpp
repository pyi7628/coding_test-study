#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int c[26];
string str;
int n;

void back_tracking(int cnt, string s)
{
    if (cnt == str.length())
    {
        cout << s << "\n";
        return;
    }
    for (int i = 0; i < 26; i++)
    {
        if (c[i])
        {
            c[i]--;
            string next = s + (char)(i + 'a');
            back_tracking(cnt + 1, next);
            c[i]++;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        memset(c, 0, sizeof(c));
        cin >> str;
        for (int j = 0; j < str.length(); j++)
            c[str[j] - 'a']++;
        back_tracking(0, "");
    }

    return 0;
}