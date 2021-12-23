#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str;
vector<char> v;
int flag = 0;
int main()
{
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (flag == 0 && str[i] == ' ')
        {
            while (!v.empty())
            {
                cout << v.back();
                v.pop_back();
            }
            cout << ' ';
        }
        else
        {
            if (str[i] == '<')
            {
                flag = 1;
                while (!v.empty())
                {
                    cout << v.back();
                    v.pop_back();
                }
            }
            else if (str[i] == '>')
                flag = 0;
            else if (flag == 0)
            {
                v.push_back(str[i]);
                continue;
            }
            cout << str[i];
        }
    }
    while (!v.empty())
    {
        cout << v.back();
        v.pop_back();
    }
    return 0;
}