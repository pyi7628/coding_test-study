#include <cstdio>
#include <queue>
#include <string>
using namespace std;

queue<string> q;
int n, cnt = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= 9; i++)
    {
        q.push(to_string(i));
    }
    while (!q.empty())
    {
        string cur = q.front();
        q.pop();
        cnt++;

        if (cnt == n)
        {
            printf("%.f", stod(cur));
            return 0;
        }

        for (int i = 0; i <= 9; i++)
        {
            if (cur[cur.length() - 1] - '0' > i)
            {
                q.push(cur + to_string(i));
            }
        }
    }
    printf("-1");
    return 0;
}