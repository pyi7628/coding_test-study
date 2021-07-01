#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int total_len = s.length();
    int minus_num = 0;
    int answer = 0;
    for (int i = 1; i < total_len; i++)
    {
        // cout << typeid(s[i]).name() << '\n';
        switch (s[i])
        {
        case '=':
            if (s[i - 1] == 'c' || s[i - 1] == 's')
            {
                answer += 1;
                minus_num += 2;
            }
            else if (s[i - 1] == 'z')
            {
                if (i - 2 >= 0 && s[i - 2] == 'd')
                    minus_num += 3;
                else
                    minus_num += 2;
                answer += 1;
            }
            break;
        case '-':
            if (s[i - 1] == 'c' || s[i - 1] == 'd')
            {
                answer += 1;
                minus_num += 2;
            }
            break;
        case 'j':
            if (s[i - 1] == 'l' || s[i - 1] == 'n')
            {
                answer += 1;
                minus_num += 2;
            }
            break;
        }
    }
    answer += (total_len - minus_num);
    cout << answer << '\n';
    return 0;
}