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

        if (cur.pos * 2 <= 100000 && !check[cur.pos * 2])
        {
            POINT temp;
            temp.cnt = cur.cnt + 1;
            temp.pos = cur.pos * 2;
            check[temp.pos] = true;
            q.push(temp);
        }
        if (cur.pos + 1 <= 100000 && !check[cur.pos + 1])
        {
            POINT temp;
            temp.cnt = cur.cnt + 1;
            temp.pos = cur.pos + 1;
            check[temp.pos] = true;
            q.push(temp);
        }
        if (cur.pos - 1 >= 0 && !check[cur.pos - 1])
        {
            POINT temp;
            temp.cnt = cur.cnt + 1;
            temp.pos = cur.pos - 1;
            check[temp.pos] = true;
            q.push(temp);
        }
    }

    return 0;
}