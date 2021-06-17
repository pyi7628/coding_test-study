#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int n;

queue<int> s;
void do_command(string cmd)
{

    if (cmd[0] == 'p' && cmd[1] == 'u')
    {
        s.push(stoi(cmd.substr(4, cmd.size())));
    }
    else if (cmd[0] == 'p' && cmd[1] == 'o')
    {
        if (!s.empty())
        {
            printf("%d\n", s.front());
            s.pop();
        }
        else
            printf("-1\n");
    }
    else if (cmd[0] == 'b' && cmd[1] == 'a')
    {
        if (!s.empty())
            printf("%d\n", s.back());
        else
            printf("-1\n");
    }
    else if (cmd[0] == 'f' && cmd[1] == 'r')
    {
        if (!s.empty())
            printf("%d\n", s.front());
        else
            printf("-1\n");
    }
    else if (cmd[0] == 's' && cmd[1] == 'i')
    {
        printf("%lu\n", s.size());
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
        cout << "test: " << s << '\n';
        do_command(s);
    }

    return 0;
}