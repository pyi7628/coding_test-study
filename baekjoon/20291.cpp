#include <iostream>
#include <string>
#include <map>
using namespace std;
int n;
string str;
map<string, int> m;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == '.')
            {
                m[str.substr(j + 1, str.length() - j - 1)]++;
            }
        }
    }
    for (map<string, int>::iterator itr = m.begin(); itr != m.end(); ++itr)
    {
        cout << itr->first << " " << itr->second << "\n";
    }

    return 0;
}