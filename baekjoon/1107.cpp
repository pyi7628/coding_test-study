#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
struct node
{
    int num;
    int cnt;
    int type;
};
int n, m, num, answer = 1000000;
int bad_button[11];
queue<node> q;
node temp;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &num);
        bad_button[num] = 1;
    }
    temp.num = n, temp.cnt = 0, temp.type = 1;
    q.push(temp);
    temp.type = -1;
    q.push(temp);
    while (!q.empty())
    {
        node cur = q.front();
        q.pop();

        int cur_num = cur.num;
        int cur_len = 0;

        if (abs(cur.num - 100) <= 2 && abs(cur.num - 100) >= 0)
        {
            if (answer > abs(n - cur.num) + abs(cur.num - 100))
                answer = abs(n - cur.num) + abs(cur.num - 100);
        }
        while (!bad_button[cur_num % 10])
        {
            cur_len++;
            cur_num /= 10;
            if (cur_num == 0)
                break;
        }
        if ((cur.num == 0 && !bad_button[0]) || (cur.num >= pow(10, cur_len - 1) && cur.num < pow(10, cur_len)))
        {
            if (answer > abs(n - cur.num) + cur_len)
                answer = abs(n - cur.num) + cur_len;
        }
        temp.num = cur.num + cur.type, temp.cnt = cur.cnt + 1, temp.type = cur.type;
        if (temp.num <= 1000000 && temp.num >= 0)
            q.push(temp);
    }
    printf("%d", answer);
    return 0;
}
