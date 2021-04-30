#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int solution(string name)
{
    int answer = 0;
    queue<pair<int, int> > q; // index, cnt
    queue<string> check;
    string init_str = name;

    for (int i = 1; i < name.length(); i++)
    {
        init_str[i] = 'A';
    }

    q.push(make_pair(0, min('A' - name[0] + 26, -('A' - name[0]))));
    check.push(init_str);

    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        string str = check.front();

        if (name.compare(str) == 0)
        {
            answer = cnt;
            break;
        }
        q.pop();
        check.pop();

        for (int i = 1; i < name.length(); i++)
        {
            int right = (cur + i) % name.length();
            int left = (cur - i + name.length()) % name.length();

            if (str[right] == 'A' && name[right] != 'A')
            {
                q.push(make_pair(right, cnt + i + min('A' - name[right] + 26, -('A' - name[right]))));
                string temp = str;
                temp[right] = name[right];
                check.push(temp);

                break;
            }
            if (str[left] == 'A' && name[left] != 'A')
            {
                q.push(make_pair(left, cnt + i + min('A' - name[left] + 26, -('A' - name[left]))));
                string temp = str;
                temp[left] = name[left];
                check.push(temp);
                break;
            }
        }
    }
    return answer;
}

int main()
{
    char str[21] = {
        0,
    };
    scanf("%s", str);
    solution(str);
    return 0;
}