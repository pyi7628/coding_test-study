#include <cstdio>
#include <string>
#include <queue>
using namespace std;
typedef pair<string, int> sti;
bool check[1000000][2];
string str;
queue<sti> q;
int n, k, answer = -1;

int main()
{
    scanf("%d%d", &n, &k);
    str = to_string(n);
    if (k == 0)
    {
        printf("%d", n);
        return 0;
    }
    q.push(make_pair(str, 0));
    sti cur;
    string next_str;
    int next_num;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for (int i = 0; i < cur.first.length() - 1; i++)
        {
            for (int j = i + 1; j < cur.first.length(); j++)
            {
                if (!(i == 0 && cur.first[j] == '0'))
                {
                    next_str = cur.first;
                    next_str[i] = cur.first[j];
                    next_str[j] = cur.first[i];
                    next_num = stoi(next_str);
                    if (answer < next_num && cur.second + 1 <= k && (cur.second + 1) % 2 == k % 2)
                        answer = next_num;
                    if (!check[next_num][(cur.second + 1) % 2])
                    {
                        check[next_num][(cur.second + 1) % 2] = true;
                        q.push(make_pair(next_str, cur.second + 1));
                    }
                }
            }
        }
    }
    printf("%d", answer);
    return 0;
}