#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <math.h>

#define MAX_NUM 1000000000

using namespace std;

vector<long long> s;

struct CMD
{
    char *c;
};

bool do_command(int num, vector<CMD> cmd)
{
    for (int i = 0; i < cmd.size(); i++)
    {
        char *c = cmd[i].c;

        if (c[0] == 'N' && c[1] == 'U')
        {
            char *n = cmd[i + 1].c;
            s.push_back(atol(n));
        }
        else if (c[0] == 'P' && c[1] == 'O')
        {
            if (s.size() < 1)
                return false;
            s.pop_back();
        }
        else if (c[0] == 'I' && c[1] == 'N')
        {
            if (s.size() < 1)
                return false;
            long long n = s.back();
            s.pop_back();
            s.push_back(n * (-1));
        }
        else if (c[0] == 'D' && c[1] == 'U')
        {
            if (s.size() < 1)
                return false;
            long long n = s.back();
            s.push_back(n);
        }
        else if (c[0] == 'S' && c[1] == 'W')
        {
            if (s.size() < 2)
                return false;
            long long n1 = s.back();
            s.pop_back();
            long long n2 = s.back();
            s.pop_back();
            s.push_back(n1);
            s.push_back(n2);
        }
        else if (c[0] == 'A' && c[1] == 'D')
        {
            if (s.size() < 2)
                return false;
            long long n1 = s.back();
            s.pop_back();
            long long n2 = s.back();
            s.pop_back();
            long long ans = n1 + n2;
            if (abs(ans) > MAX_NUM)
                return false;
            s.push_back(ans);
        }
        else if (c[0] == 'S' && c[1] == 'U')
        {
            if (s.size() < 2)
                return false;
            long long n1 = s.back();
            s.pop_back();
            long long n2 = s.back();
            s.pop_back();
            long long ans = n2 - n1;
            if (abs(ans) > MAX_NUM)
                return false;
            s.push_back(ans);
        }
        else if (c[0] == 'M' && c[1] == 'U')
        {
            if (s.size() < 2)
                return false;
            long long n1 = s.back();
            s.pop_back();
            long long n2 = s.back();
            s.pop_back();
            long long ans = n1 * n2;
            if (abs(ans) > MAX_NUM)
                return false;
            s.push_back(ans);
        }
        else if (c[0] == 'D' && c[1] == 'I')
        {
            if (s.size() < 2)
                return false;
            long long n1 = s.back();
            s.pop_back();
            long long n2 = s.back();
            s.pop_back();
            long long t = n1 * n2;
            if (n1 == 0)
                return false;
            s.push_back(n2 / n1);
        }
        else if (c[0] == 'M' && c[1] == 'O')
        {
            if (s.size() < 2)
                return false;
            long long n1 = s.back();
            s.pop_back();
            long long n2 = s.back();
            s.pop_back();
            long long t = n1 * n2;
            if (n1 == 0)
                return false;
            s.push_back(n2 % n1);
        }
    }
    if (s.size() == 1)
        return true;
    else
        return false;
}

int main()
{

    while (true)
    {
        char buf[20] = "";
        vector<CMD> cmd;

        while (strcmp(buf, "END") != 0)
        {
            scanf("%s", buf);
            if (strcmp(buf, "QUIT") == 0)
                return 0;
            if (strcmp(buf, "END") == 0)
                break;
            CMD temp;
            temp.c = (char *)malloc(sizeof(buf) + 1);
            strcpy(temp.c, buf);
            cmd.push_back(temp);
        }

        int n = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int num = 0;
            scanf("%d", &num);
            s.push_back(num);
            bool result = do_command(num, cmd);
            if (result)
                cout << s.back() << '\n';
            else
                cout << "ERROR" << '\n';

            s.clear();
        }
        cout << '\n';
    }

    return 0;
}