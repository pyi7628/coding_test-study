#include <iostream>
using namespace std;
string str;
int max_num = 0,
    min_num = 1000000000;
void calc(string s, int cnt)
{
    int next_cnt = cnt;
    int s1, s2, s3 = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] - '0') % 2 != 0)
            next_cnt++;
    }

    if (s.length() == 1)
    {
        if (max_num < next_cnt)
            max_num = next_cnt;
        if (min_num > next_cnt)
            min_num = next_cnt;
        return;
    }

    else if ((s.length() == 2))
    {
        s1 = s[0] - '0', s2 = s[1] - '0';
        calc(to_string(s1 + s2 + s3), next_cnt);
    }
    else if (s.length() >= 3)
    {
        for (int i = 1; i < s.length(); i++)
        {
            for (int j = i + 1; j < s.length(); j++)
            {
                s1 = stoi(s.substr(0, i));
                s2 = stoi(s.substr(i, j - i));
                s3 = stoi(s.substr(j, s.length() - j));
                calc(to_string(s1 + s2 + s3), next_cnt);
            }
        }
    }
}
int main()
{
    cin >> str;
    calc(str, 0);
    cout << min_num << ' ' << max_num;
    return 0;
}