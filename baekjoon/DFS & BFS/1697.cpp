#include <cstdio>
#include <queue>
using namespace std;
int n, k;
int cnt = 0;
bool check[100002];
struct POINT
{
    int cnt;
    int pos;
};
queue<POINT> q;
void push_point(int pos, int cnt)
{
    if (pos >= 0 && pos <= 100000 && !check[pos])
    {
        POINT temp;
        temp.cnt = cnt;
        temp.pos = pos;
        check[pos] = true;
        q.push(temp);
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    POINT p;
    p.cnt = 0;
    p.pos = n;
    check[n] = true;
    q.push(p);
    while (!q.empty())
    {
        POINT cur = q.front();
        q.pop();
        if (cur.pos == k)
        {
            printf("%d", cur.cnt);
            return 0;
        }
        push_point(cur.pos * 2, cur.cnt + 1);
        push_point(cur.pos + 1, cur.cnt + 1);
        push_point(cur.pos - 1, cur.cnt + 1);
    }

    return 0;
}