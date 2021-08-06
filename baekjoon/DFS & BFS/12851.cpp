#include <cstdio>
#include <queue>
using namespace std;
int n, k;
int check[100002];
struct POINT
{
    int cnt;
    int pos;
};
queue<POINT> q;
void push_point(int pos, int cnt)
{
    if (pos >= 0 && pos <= 100000 && check[pos] >= cnt)
    {
        POINT temp;
        temp.cnt = cnt;
        temp.pos = pos;

        check[pos] = cnt;
        q.push(temp);
    }
}
int answer = 1000000;
int answer_cnt = 0;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < 100002; i++)
    {
        check[i] = 1000000;
    }
    POINT p;
    p.cnt = 0;
    p.pos = n;
    check[n] = 0;
    q.push(p);
    while (!q.empty())
    {
        POINT cur = q.front();
        q.pop();
        if (cur.cnt > answer)
            break;
        if (cur.pos == k)
        {
            answer = cur.cnt;
            answer_cnt++;
        }
        push_point(cur.pos * 2, cur.cnt + 1);
        push_point(cur.pos + 1, cur.cnt + 1);
        push_point(cur.pos - 1, cur.cnt + 1);
    }

    printf("%d\n%d", answer, answer_cnt);

    return 0;
}