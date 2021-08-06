#include <cstdio>
#include <deque>
using namespace std;
int n, k;
int cnt = 0;
bool check[100002];
struct POINT
{
    int cnt;
    int pos;
};
deque<POINT> q;
void push_back_point(int pos, int cnt)
{
    if (pos >= 0 && pos <= 100000 && !check[pos])
    {
        POINT temp;
        temp.cnt = cnt;
        temp.pos = pos;
        check[pos] = true;
        q.push_back(temp);
    }
}
void push_front_point(int pos, int cnt)
{
    if (pos >= 0 && pos <= 100000 && !check[pos])
    {
        POINT temp;
        temp.cnt = cnt;
        temp.pos = pos;
        check[pos] = true;
        q.push_front(temp);
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    POINT p;
    p.cnt = 0;
    p.pos = n;
    check[n] = true;
    q.push_front(p);
    while (!q.empty())
    {
        POINT cur = q.front();
        q.pop_front();
        if (cur.pos == k)
        {
            printf("%d", cur.cnt);
            return 0;
        }
        push_front_point(cur.pos * 2, cur.cnt);
        push_back_point(cur.pos + 1, cur.cnt + 1);
        push_back_point(cur.pos - 1, cur.cnt + 1);
    }

    return 0;
}