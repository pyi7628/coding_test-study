#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
struct CMD
{
    char *c;
};
vector<int> s;
void do_command(string cmd)
{

    if (cmd[0] == 'p' && cmd[1] == 'u')
    {
        s.push_back(stoi(cmd.substr(4, cmd.size())));
    }
    else if (cmd[0] == 'p' && cmd[1] == 'o')
    {
        if (!s.empty())
        {
            printf("%d\n", s.back());
            s.pop_back();
        }
        else
            printf("-1\n");
    }
    else if (cmd[0] == 't' && cmd[1] == 'o')
    {
        if (!s.empty())
            printf("%d\n", s.back());
        else
            printf("-1\n");
    }
    else if (cmd[0] == 's' && cmd[1] == 'i')
    {
        printf("%d\n", s.size());
    }
    else if (cmd[0] == 'e' && cmd[1] == 'm')
    {
        if (!s.empty())
            printf("0\n");
        else
            printf("1\n");
    }
}
int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s[0] == 'p' && s[1] == 'u')
        {
            string n;
            cin >> n;
            s.append(n);
        }
        // cout << "test: " << s << '\n';
        do_command(s);
    }

    return 0;
}